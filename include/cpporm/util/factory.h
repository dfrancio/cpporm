/*!
 * \file
 * \brief     Builder class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/error.h>

CPPORM_BEGIN_SUB_NAMESPACE(util)

/*!
 * \brief Helper class to register a key with a derived class in a factory
 *
 * \tparam T The Factory type
 * \tparam U The derived type
 */
template <typename T, typename U>
struct FactoryRegister
{
    /*!
     * \brief Constructor
     * \param[in] keys The set of keys associated with the object type
     */
    template <class... Args>
    FactoryRegister(Args &&... keys)
    {
        T::GetInstance().template Register<U>(std::forward<Args>(keys)...);
    }
};

/*!
 * \brief A class to create polymorphic objects by means of keys
 *
 * Factories serve to instantiate a derived class using a key that is known only at run-time. It is
 * a singleton class. One can register a key with a derived type in three different forms:
 *  1. in the factory's constructor;
 *  2. by accessing the singleton instance directly; or
 *  3. using a helper register class
 *
 * \tparam The Factory type (CRTP)
 * \tparam Base The base class of the polymorphic type
 * \tparam Key The type of the keys
 * \tparam Comp The type of the comparator used in the ordering of the keys
 * \tparam Args The types of the arguments passed as parameters to the object constructor
 */
template <typename F, typename Base, typename Key, typename Comp = std::less<Key>, typename... Args>
class Factory
{
public:
    /*!
     * \brief The raw-pointer creator function type
     */
    typedef std::function<Base *(Args...)> RawCreator;

    /*!
     * \brief The smart-pointer creator function type
     */
    typedef std::function<std::shared_ptr<Base>(Args...)> SmartCreator;

    Factory(Factory &&) = delete;
    Factory(Factory const &) = delete;
    Factory &operator=(Factory &&) = delete;
    Factory &operator=(Factory const &) = delete;

    /*!
     * \brief Destructor
     */
    virtual ~Factory()
    {
    }

    /*!
     * \brief Get factory instance
     * \return The factory instance
     */
    static F &GetInstance()
    {
        static F instance;
        return instance;
    }

    /*!
     * \brief Register
     *
     * \tparam Derived The derived type
     * \tparam FArgs The types of the function arguments
     *
     * \param[in] keys The set of keys associated with the derived object type
     */
    template <class Derived, class... FArgs>
    void Register(FArgs &&... keys)
    {
        auto rawCreator = [](Args &&... args) { return new Derived(std::forward<Args>(args)...); };
        auto smartCreator = [](Args &&... args) -> std::shared_ptr<Base> {
            return std::make_shared<Derived>(std::forward<Args>(args)...);
        };
        Register(rawCreator, smartCreator, std::forward<FArgs>(keys)...);
    }

    /*!
     * \brief Register
     *
     * \tparam FArgs The types of the function arguments
     *
     * \param[in] rawCreator The raw-pointer creator function
     * \param[in] smartCreator The smart-pointer creator function
     * \param[in] keys The set of keys associated with the derived object type
     */
    template <class... FArgs>
    void Register(RawCreator rawCreator, SmartCreator smartCreator, FArgs &&... keys)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        CPPORM_UNPACK(mCreators[keys] = std::make_pair(rawCreator, smartCreator));
    }

    /*!
     * \brief Create unique pointer
     *
     * \tparam FArgs The types of the function arguments
     *
     * \param[in] key The key to determine which kind of object should be created
     * \param[in] args The constructor arguments
     * \return The unique pointer
     */
    template <class... FArgs>
    std::unique_ptr<Base> CreateUnique(const Key &key, FArgs &&... args) const
    {
        std::lock_guard<std::mutex> lock(mMutex);
        const auto it = mCreators.find(key);
        if (it == mCreators.end())
            throw EntryNonExistentError(key);
        return std::unique_ptr<Base>(it->second.first(std::forward<FArgs>(args)...));
    }

    /*!
     * \brief Create shared pointer
     *
     * \tparam FArgs The types of the function arguments
     *
     * \param[in] key The key to determine which kind of object should be created
     * \param[in] args The constructor arguments
     * \return The shared pointer
     */
    template <class... FArgs>
    std::shared_ptr<Base> CreateShared(const Key &key, FArgs &&... args) const
    {
        std::lock_guard<std::mutex> lock(mMutex);
        const auto it = mCreators.find(key);
        if (it == mCreators.end())
            throw EntryNonExistentError(key);
        return it->second.second(std::forward<FArgs>(args)...);
    }

protected:
    /*!
     * \brief Construct a new Factory
     */
    Factory()
    {
    }

    /*!
     * \brief The map of creator functions
     */
    std::map<Key, std::pair<RawCreator, SmartCreator>, Comp> mCreators;

    /*!
     * \brief The mutual exclusion device
     */
    mutable std::mutex mMutex;
};

/*!
 * \brief Specialized Factory for case-insensitive string keys
 */
template <typename F, typename Base, typename... Args>
using CaseInsensitiveFactory = Factory<F, Base, std::string, CaseInsensitiveLess, Args...>;

CPPORM_END_SUB_NAMESPACE
