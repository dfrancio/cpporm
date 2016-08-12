/*!
 * \file
 * \brief     ormc regression tests - MySQL
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */

// C library includes
#include <cstdlib>

// C++ library includes
#include <string>

// External library includes
#include <gtest/gtest.h>

/*!
 * \details
 */
TEST(DISABLED_Ormc_Regression_MySql, TestSet1)
{
    std::string command = DATADIR;
    command += "/../bin/ormc ";
    command += "--input_format=mysql ";
    command += DATADIR;
    command += "/sample1.mysql.sql";
    ASSERT_EQ(std::system(command.c_str()), 0);
}
