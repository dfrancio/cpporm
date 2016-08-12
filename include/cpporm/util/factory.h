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
 * \brief Factory register for the default behaviour of object construction (new Derived(...))
 */
template <typename T, typename U>
struct DefaultFactoryRegister
{
    template <class... Args>
    DefaultFactoryRegister(Args &&... keys)
    {
        T::GetInstance().template Register<U>(std::forward<Args>(keys)...);
    }
};

/*!
 * \brief Factory register for custom constructed objects (providing a creator function)
 */
template <typename T>
struct CustomFactoryRegister
{
    template <class... Args>
    CustomFactoryRegister(typename T::CreatorFunction creator, Args &&... keys)
    {
        T::GetInstance().Register(creator, std::forward<Args>(keys)...);
    }
};

/*!
 * \brief Factory
 */
template <typename F, typename Base, typename Key, typename Ptr = std::unique_ptr<Base>,
          typename Comp = std::less<Key>, typename... Args>
class Factory
{
public:
    /*!
     * \brief Creator function
     */
    typedef std::function<Base *(Args...)> CreatorFunction;

    /*!
     * \brief Destructor
     */
    virtual ~Factory()
    {
    }

    /*!
     * \brief Get instance
     * \return The factory instance
     */
    static F &GetInstance()
    {
        static F instance;
        return instance;
    }

    /*!
     * \brief Register
     * \tparam Derived The object type to be registered
     * \tparam FArgs The types of the key arguments
     * \param[in] keys The set of keys associated with the object type
     */
    template <class Derived, class... FArgs>
    void Register(FArgs &&... keys)
    {
        auto creator = [](Args &&... args) { return new Derived(std::forward<Args>(args)...); };
        Register(creator, std::forward<FArgs>(keys)...);
    }

    /*!
     * \brief Register
     * \param[in] creator The creator function
     * \param[in] keys The set of keys associated with the creator function
     */
    template <class... FArgs>
    void Register(CreatorFunction creator, FArgs &&... keys)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        CPPORM_UNPACK(mCreators[keys] = creator);
    }

    /*!
     * \brief Create object
     * \param[in] key The key to determine which kind of object should be created
     * \param[in] args The constructor arguments
     * \return The object pointer
     */
    template <class... FArgs>
    Ptr Create(const Key &key, FArgs &&... args)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        const auto it = mCreators.find(key);
        if (it == mCreators.end())
            throw EntryNonExistentError(key);
        return Ptr(it->second(std::forward<FArgs>(args)...));
    }

protected:
    /*!
     * \brief The map of creator functions
     */
    std::map<Key, CreatorFunction, Comp> mCreators;

    /*!
     * \brief The mutual exclusion device
     */
    mutable std::mutex mMutex;
};

CPPORM_END_SUB_NAMESPACE
