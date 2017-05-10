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
 * \brief %Relationship
 */
class CPPORM_EXPORT Relationship
{
public:
    /*!
     * \brief Destructor
     */
    virtual ~Relationship();

    /*!
     * \brief Constructor
     * \param[in] parent The parent entity
     */
    Relationship(Entity &parent);

    Relationship(const Relationship &other) = delete;

    /*!
     * \brief Copy assignemnt
     * \param[in] other The other relationship
     */
    Relationship &operator=(const Relationship &other);

    /*!
     * \brief Get name
     * \return The relationship name
     */
    virtual const std::string &GetName() const = 0;

    /*!
     * \brief Get properties
     * \return The relationship properties
     */
    virtual const PropertyMap &GetProperties() const = 0;

    /*!
     * \brief Get foreign key names
     * \return The list of foreign key names
     */
    virtual const std::vector<std::string> &GetForeignKeyNames() const = 0;

    /*!
     * \brief Get referenced names
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
     * \brief Get reciprocal name
     * \return The relationship reciprocal name
     */
    virtual const std::string &GetReciprocalName() const = 0;

    /*!
     * \brief Get prototype
     * \return The related type prototype
     */
    virtual Entity &GetPrototype() const = 0;

    /*!
     * \brief Unrelate
     */
    virtual void Unrelate();

    /*!
     * \brief Invalidate
     */
    virtual void Invalidate();

    /*!
     * \brief Dissolve
     */
    virtual void Dissolve();

    /*!
     * \brief Get session
     * \return The database session
     */
    db::Session *GetSession() const;

    /*!
     * \brief Remove parent
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
 * \brief To-one relationship
 */
class CPPORM_EXPORT ToOneRelationship : public Relationship, private std::shared_ptr<Entity>
{
    using Relationship::Relationship;

public:
    /*!
     * \brief operator bool
     */
    explicit operator bool();

    /*!
     * \brief operator ==
     * \param[in] other The other relationship
     * \return True, if the pointers are equal; false otherwise
     */
    bool operator==(const ToOneRelationship &other);

    /*!
     * \brief operator !=
     * \param[in] other The other relationship
     * \return True, if the pointers are different; false otherwise
     */
    bool operator!=(const ToOneRelationship &other);

    /*!
     * \brief operator ==
     * \param[in] pointer The pointer
     * \return True, if the pointers are equal; false otherwise
     */
    template <typename T>
    bool operator==(const std::shared_ptr<T> &pointer)
    {
        Load();
        return get() == pointer.get();
    }

    /*!
     * \brief operator !=
     * \param[in] pointer The pointer
     * \return True, if the pointers are different; false otherwise
     */
    template <typename T>
    bool operator!=(const std::shared_ptr<T> &pointer)
    {
        Load();
        return get() != pointer.get();
    }

protected:
    /*!
     * \brief Get
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
     * \brief Invalidate
     */
    void Invalidate() override;

    /*!
     * \brief Unrelate
     */
    void Unrelate() override;

    /*!
     * \brief Load
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
     * \brief Is foreign key null?
     * \return True, if the foreign key is null; false otherwise
     */
    bool IsForeignKeyNull() const;

    /*!
     * \brief Was foreign key updated?
     * \return True, if the foreign key was updated; false otherwise
     */
    bool WasForeignKeyUpdated() const;

    /*!
     * \brief Invalidated flag
     */
    bool mInvalidated = true;
};

/*!
 * \brief To-many relationship
 */
class CPPORM_EXPORT ToManyRelationship : public Relationship,
                                         private std::vector<std::shared_ptr<Entity>>
{
    using Relationship::Relationship;

public:
    /*!
     * \brief For each
     * \param[in] function The function
     * \param[in] args The function arguments
     * \return True, if all related entities were processed successfully; false otherwise
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
     * \brief Dissolve
     */
    void Dissolve() override;

    /*!
     * \brief Load
     * \param[in] cachedOnly A flag to indicate whether to search only already cached entities
     */
    virtual void Load(bool cachedOnly);
};

CPPORM_END_NAMESPACE
