/**
 * @file databaseReader.cpp
 *
 * @author Jaroslaw Wiosna
 * @author Wojciech Mielczarek
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "DatabaseReader.hpp"
#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>

TEST(DatabaseReader, dummyTest) {
    std::string path = "../../../database/Poland-Cities010-Top10-mock.txt";
    auto vec = DatabaseReader::readCitiesFromFile(path);
    // check if we have all cities, and the number if 10 indicates also not
    // including lines with #
    ASSERT_EQ(10, vec.size());

    // in case there will be error in readCitiesFromFile we will know if they
    // are not caused by split function
    std::string city_data = "Aleksandrow Kujawski|7.23|12335|52.8833|18.7";
    std::vector<std::string> vec2;
    DatabaseReader::split(city_data, "|", vec2);
    ASSERT_EQ(5, vec2.size());
    ASSERT_EQ("Aleksandrow Kujawski", vec2[0]);
    ASSERT_EQ("7.23", vec2[1]);
    ASSERT_EQ("12335", vec2[2]);
    ASSERT_EQ("52.8833", vec2[3]);
    ASSERT_EQ("18.7", vec2[4]);

    // check spaces, if we have all elements, if they have right values and if
    // they were pushed in constructor in the right order
    ASSERT_EQ("Warsaw", vec[0].getName());
    ASSERT_EQ(517, (unsigned int)vec[0].getArea());
    ASSERT_EQ(1702139, vec[0].getPopulation());
    ASSERT_EQ("52.23", vec[0].getLatitude());
    ASSERT_EQ("21.012", vec[0].getLongitude());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
