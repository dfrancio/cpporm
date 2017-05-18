/*!
 * \file
 * \brief     String map class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#pragma once

#include <cpporm/error.h>

CPPORM_BEGIN_SUB_NAMESPACE(util)

/*!
 * \brief Provide a high-level interface to map strings to objects of a generic type
 *
 * \tparam T The type of the mapped objects
 */
template <typename T>
class StringMap : public std::unordered_map<std::string, T>
{
    using std::unordered_map<std::string, T>::unordered_map;

public:
    /*!
     * \brief Check if an entry exists
     * \param[in] name The entry name
     * \return True if the map has the entry; false otherwise
     */
    bool Has(const std::string &name) const
    {
        return this->find(name) != this->end();
    }

    /*!
     * \brief Get entry value
     * \param[in] name The entry name
     * \return The mapped value
     */
    T &Get(const std::string &name)
    {
        auto it = this->find(name);
        if (it == this->end())
            throw EntryNonExistentError(name);
        else
            return it->second;
    }

    /*!
     * \brief Get entry value (const version)
     * \param[in] name The entry name
     * \return The mapped value
     */
    const T &Get(const std::string &name) const
    {
        auto it = this->find(name);
        if (it == this->end())
            throw EntryNonExistentError(name);
        else
            return it->second;
    }

    /*!
     * \brief Get entry value (with default)
     * \param[in] name The entry name
     * \param[in] def The default value
     * \return The mapped value if it exists; else the default value
     */
    const T &Get(const std::string &name, const std::string &def) const
    {
        auto it = this->find(name);
        if (it == this->end())
            return def;
        else
            return it->second;
    }
};

CPPORM_END_SUB_NAMESPACE
