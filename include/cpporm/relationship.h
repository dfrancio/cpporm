/*!
 * \file
 * \brief     Relationship class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/util/macros.h>

CPPORM_BEGIN_NAMESPACE

/*
 * Forward declarations
 */
namespace db
{
class Session;
class Criteria;
}
class Entity;
class PropertyMap;

/*
 * Helper classes
 */
namespace detail
{
template <typename T>
struct function_traits /** @cond */ : public function_traits<decltype(&T::operator())>
/** @endcond */
{ /** @cond */
};

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType (ClassType::*)(Args...) const>
{ /** @endcond */
    enum
    {
        arity = sizeof...(Args)
    };

    typedef ReturnType result_type;

    template <std::size_t i>
    struct arg
    {
        typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
    };
};
}

/*!
 * \brief Abstract class to represent database relationships
 *
 * A relationship has a name, a set of properties, a list of names of foreign keys and a list of
 * names of referenced columns (one for each foreign key). Relationships should derive from
 * ToOneRelationship or ToManyRelationship, not from this class.
 *
 * \see ToOneRelationship
 * \see ToManyRelationship
 */
class CPPORM_EXPORT Relationship
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Relationship();

    /*!
     * \brief Construct a new relationship
     * \param[in] parent The parent entity
     */
    Relationship(Entity &parent);

    Relationship(const Relationship &other) = delete;

    /*!
     * \brief Copy from another relationship
     * \param[in] other The other relationship
     */
    Relationship &operator=(const Relationship &other);

    /*!
     * \brief Get relationship name
     * \return The relationship name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get relationship properties
     * \return The relationship properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get relationship foreign key names
     * \return The list of foreign key names
     */
    virtual const std::vector<std::string> &GetForeignKeyNames() const = 0;

    /*!
     * \brief Get relationship referenced names
     * \return The list of referenced names
     */
    virtual const std::vector<std::string> &GetReferencedNames() const = 0;

protected:
    /*!
     * \brief Befriend class Entity
     */
    friend class Entity;

    /*!
     * \brief Befriend class ToOneRelationship
     */
    friend class ToOneRelationship;

    /*!
     * \brief Befriend class ToManyRelationship
     */
    friend class ToManyRelationship;

    /*!
     * \brief Get relationship reciprocal name
     * \return The relationship reciprocal name
     */
    virtual const std::string &GetReciprocalName() const = 0;

    /*!
     * \brief Get prototype of the related type
     * \return The prototype of the related type
     */
    virtual Entity &GetPrototype() const = 0;

    /*!
     * \brief Unrelate
     */
    virtual void Unrelate();

    /*!
     * \brief Invalidate relationship
     */
    virtual void Invalidate();

    /*!
     * \brief Dissolve relationship
     */
    virtual void Dissolve();

    /*!
     * \brief Get database session
     * \return The database session
     */
    db::Session *GetSession() const;

    /*!
     * \brief Remove parent entity
     */
    void RemoveParent() const;

    /*!
     * \brief Set cached only
     * \param[in] criteria The search criteria
     * \param[in] value The value of the flag
     */
    void SetCachedOnly(db::Criteria &criteria, bool value) const;

    /*!
     * \brief The parent entity
     */
    Entity &mParent;
};

/*!
 * \brief Class that represents "to-one" database relationships
 *
 * "To-one" means that an entity relates to another (and only one) entity in the same database. It
 * can happen that the foreign key represented by the relationship allows NULL, in which case we say
 * that the relationship has cardinality (or multiplicity) 0..1. Otherwise it has cardinality 1
 * exactly. By design, every to-one relationship has a counter-part: the "to-many" relationship.
 * This reciprocal relationship may be omitted if required, by just removing the code declaring it.
 *
 * An example might clarify how it works:
 *
 * > Suppose a table named **Car** relates to a table named **Tire** by means of a foreign key in
 * > the Tire table, linking to an entry in the Car table. The column names could be *id* for the
 * > Car identifier and *car_id* for the foreign key in the Tire table, the latter allowing NULL
 * > values (to cover the case wherepon a tire is not yet part of a car).
 * > In this situation, the mapped C++ class Tire will have a to-one relationship pointing to Car,
 * > while the Car class will have a to-many relationship pointing to Tire. The relationship which
 * > relates Tire to Car has cardinality 0..1, while its reciprocal has cardinality 1..*.
 * > This means that a tire may be part of only one car (or none) and a car may be composed of
 * > several tires. That is why the to-many relationship is implemented as a list of pointers that
 * > can be loaded on demand and iterated using a special *for* loop.
 *
 * \see ToManyRelationship
 */
class CPPORM_EXPORT ToOneRelationship : public Relationship, private std::shared_ptr<Entity>
{
    using Relationship::Relationship;

public:
    /*!
     * \brief Check whether the related entity is not NULL
     */
    explicit operator bool();

    /*!
     * \brief Check whether two relationships point to the same entity
     * \param[in] other The other relationship
     * \return True if the pointers are equal; false otherwise
     */
    bool operator==(const ToOneRelationship &other);

    /*!
     * \brief Check whether two relationships point to different entities
     * \param[in] other The other relationship
     * \return True if the pointers are different; false otherwise
     */
    bool operator!=(const ToOneRelationship &other);

    /*!
     * \brief Check whether the related entity is the same as that pointed to by `pointer`
     * \param[in] pointer The pointer
     * \return True if the pointers are equal; false otherwise
     */
    template <typename T>
    bool operator==(const std::shared_ptr<T> &pointer)
    {
        Load();
        return get() == pointer.get();
    }

    /*!
     * \brief Check whether the related entity is different from that pointed to by `pointer`
     * \param[in] pointer The pointer
     * \return True if the pointers are different; false otherwise
     */
    template <typename T>
    bool operator!=(const std::shared_ptr<T> &pointer)
    {
        Load();
        return get() != pointer.get();
    }

protected:
    /*!
     * \brief Get the related entity
     * \return The result of dereferencing the stored pointer
     */
    template <typename T>
    T *Get()
    {
        Load();
        assert(dynamic_cast<T *>(get()));
        return static_cast<T *>(get());
    }

    /*!
     * \brief Invalidate relationship
     */
    void Invalidate() override;

    /*!
     * \brief Unrelate
     */
    void Unrelate() override;

    /*!
     * \brief Load related entity
     */
    virtual void Load();

private:
    /*!
     * \brief Befriend class Entity
     */
    friend class Entity;

    /*!
     * \brief Set foreign key null
     */
    void SetForeignKeyNull();

    /*!
     * \brief Check whether the foreign is NULL
     * \return True if the foreign key is null; false otherwise
     */
    bool IsForeignKeyNull() const;

    /*!
     * \brief Check whether the foreign key was updated
     * \return True if the foreign key was updated; false otherwise
     */
    bool WasForeignKeyUpdated() const;

    /*!
     * \brief The invalidated flag
     */
    bool mInvalidated = true;
};

/*!
 * \brief Class that represents "to-many" database relationships
 *
 * \see ToOneRelationship
 */
class CPPORM_EXPORT ToManyRelationship : public Relationship,
                                         private std::vector<std::shared_ptr<Entity>>
{
    using Relationship::Relationship;

public:
    /*!
     * \brief Loop through each related entity and execute custom procedure
     * \param[in] function The function to execute
     * \param[in] args The function arguments
     * \return True if all related entities were processed successfully; false otherwise
     */
    template <typename F, typename... Args>
    bool ForEach(F &&function, Args &&... args)
    {
        typedef typename detail::function_traits<typename std::decay<F>::type>::template arg<0>
            FirstArg;
        typedef typename std::decay<typename FirstArg::type>::type T;
        Load(false);
        for (auto &pointer : *this)
        {
            assert(dynamic_cast<T *>(pointer.get()));
            if (!std::forward<F>(function)(static_cast<T &>(*pointer), std::forward<Args>(args)...))
            {
                clear();
                return false;
            }
        }
        clear();
        return true;
    }

protected:
    /*!
     * \brief Dissolve relationship
     */
    void Dissolve() override;

    /*!
     * \brief Load related entities
     * \param[in] cachedOnly A flag to indicate whether to search only already cached entities
     */
    virtual void Load(bool cachedOnly);
};

/*!
 * \example cpporm/relationship.cpp
 *
 * This is an example of how to use the various Relationship classes.
 */

CPPORM_END_NAMESPACE
