/**
 * @file region.cpp
 *
 * @author Jaroslaw Wiosna
 * @author Wojciech Mielczarek
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "Region.hpp"
#include <cmath>
#include <gtest/gtest.h>

/**
 * This test should cover operator+= and operator+ as well
 */
TEST(Region, OperatorPlusTest) {
    Region region{};

    City a{"Aleksandrow Kujawski", "7.23", "12335", "52.8833", "18.7"};
    City b{"Aleksandrow Lodzki", "13.82", "21380", "51.8167", "19.3167"};
    City c{"Alwernia", "8.88", "3402", "50.0667", "19.5333"};

    region += a;
    ASSERT_EQ(region.getPopulation(), a.getPopulation())
        << "Population of region consists of one city should be equal to the "
           "population of this city.";

    region += b;
    ASSERT_EQ(region.getPopulation(), a.getPopulation() + b.getPopulation())
        << "Population of region consists of two cities should be equal to the "
           "sum of population of those cities";

    region += c;
    ASSERT_EQ(region.getPopulation(),
              a.getPopulation() + b.getPopulation() + c.getPopulation())
        << "Population of region consists of three cities should be equal to "
           "the sum of population of those cities";
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
