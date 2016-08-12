/*!
 * \file
 * \brief     Connection string class
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All Rights Reserved
 */
#include <cpporm/db/connectionstring.h>

CPPORM_BEGIN_SUB_NAMESPACE(db)

/*!
 * \details
 */
ConnectionString::ConnectionString()
{
}

/*!
 * \details
 */
ConnectionString &ConnectionString::SetSeparator(char separator)
{
    mSeparator = separator;
    return *this;
}

/*!
 * \details
 */
ConnectionString &ConnectionString::SetParameters(
    const std::map<std::string, std::string> &parameters)
{
    for (const auto &pair : parameters)
        SetParameter(pair.first, pair.second);
    return *this;
}

/*!
 * \details
 */
ConnectionString &ConnectionString::SetParameter(const std::string &name, const std::string &value)
{
    if (!mProduct.empty())
        mProduct += mSeparator;
    if (!name.empty())
        mProduct += name + "=";
    if (value.empty() || value.front() == '\''
        || value.find_first_of(mSeparator) != std::string::npos)
        mProduct += "\"" + value + "\"";
    else if (value.front() == '"')
        mProduct += "'" + value + "'";
    else
        mProduct += value;
    return *this;
}

/*!
 * \details
 */
const std::string &ConnectionString::Get() const
{
    return mProduct;
}

/*!
 * \details
 */
ConnectionString &ConnectionString::Reset()
{
    mProduct.clear();
    return *this;
}

CPPORM_END_SUB_NAMESPACE
