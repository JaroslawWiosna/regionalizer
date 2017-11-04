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
    progressbar.printBar(50);
    ASSERT_TRUE(true);
}

TEST(progressbar, ProgressBarCtorWithArg) {
    ProgressBar progressbar{"something"};
    progressbar.printBar(50);
    ASSERT_TRUE(true);
}

/*
TEST(progressbar, ProgressBarCtorNoArgs) {
    ProgressBar *progressbar = new ProgressBar{};
    progressbar->printBar(50);
    delete progressbar;
    ASSERT_TRUE(true);
}

TEST(progressbar, ProgressBarCtorWithArg) {
    ProgressBar *progressbar = new ProgressBar{"something"};
    progressbar->printBar(50);
    delete progressbar;
    ASSERT_TRUE(true);
}
*/
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
