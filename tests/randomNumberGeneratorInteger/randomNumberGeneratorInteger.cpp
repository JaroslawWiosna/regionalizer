/**
 * @file progressbar.cpp
 *
 * @author Jaroslaw Wiosna
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "RandomNumberGeneratorInteger.hpp"
#include <gtest/gtest.h>

TEST(randomNumberGeneratorInteger, dummyTest) {
    constexpr unsigned floor{1};
    constexpr unsigned ceil{1000};
    constexpr unsigned size{1000};

    RandomNumberGeneratorInteger generator{floor, ceil};
    auto vec = generator.generateRandomVectorWithoutRepetition(size);

    for (auto number : vec) {
        ASSERT_TRUE(number >= floor)
            << "Each number in vector should be greater or equal than floor";
        ASSERT_TRUE(number <= ceil)
            << "Each number in vector should be less or equal than ceil";
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
