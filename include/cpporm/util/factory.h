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
 * \brief Factory register
 */
template <typename T, typename U>
struct FactoryRegister
{
    template <class... Args>
    FactoryRegister(Args &&... keys)
    {
        T::GetInstance().template Register<U>(std::forward<Args>(keys)...);
    }
};

/*!
 * \brief Factory
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
     * \param[in] keys The set of keys associated with the object type
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
     * \param[in] rawCreator The raw-pointer creator function
     * \param[in] smartCreator The smart-pointer creator function
     * \param[in] keys The set of keys associated with the object type
     */
    template <class... FArgs>
    void Register(RawCreator rawCreator, SmartCreator smartCreator, FArgs &&... keys)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        CPPORM_UNPACK(mCreators[keys] = std::make_pair(rawCreator, smartCreator));
    }

    /*!
     * \brief Create unique pointer
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
     * \brief Constructor
     */
    Factory()
    {
    }

    /*!
     * \brief The map of creators
     */
    std::map<Key, std::pair<RawCreator, SmartCreator>, Comp> mCreators;

    /*!
     * \brief The mutual exclusion device
     */
    mutable std::mutex mMutex;
};

/*!
 * \brief Case-insensitive string factory
 */
template <typename F, typename Base, typename... Args>
using CaseInsensitiveFactory = Factory<F, Base, std::string, CaseInsensitiveLess, Args...>;

CPPORM_END_SUB_NAMESPACE
