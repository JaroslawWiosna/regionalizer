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

#include "ProgressBar.hpp"
#include <gtest/gtest.h>

TEST(progressbar, dummyTest) {
    ASSERT_TRUE(true);
}

TEST(progressbar, ProgressBarCtorNoArgs) {
    ProgressBar progressbar{};
    ASSERT_TRUE(true);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
