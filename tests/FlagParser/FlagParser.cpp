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

#include "FlagParser.hpp"
#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>

TEST(DatabaseReader, dummyTest) {
    char program_name[] = "name";
    char flag1[] = "-flag1";
    char flag2[] = "-flag2";
    char message1v0[] = "message0";
    char message1v1[] = "message1";
    char message1v2[] = "message2";
    char message1v3[] = "message3";
    char empty_string[] = "";
    char *argv[] = {program_name};
    FlagParser Parser_parse0(1, argv);
    // testing parse function
    std::vector<std::string> vec;
    // testing with only the flags
    vec.push_back(program_name);
    vec.push_back(flag1);
    vec.push_back(flag2);
    Parser_parse0.parse(vec);
    ASSERT_TRUE(Parser_parse0.getFlags().size() == 2)
        << "We should have two flags but we have "
        << Parser_parse0.getFlags().size() << " of them";
    ASSERT_EQ(1, Parser_parse0.getFlags().count(flag1))
        << "We should have one " << vec[1] << " flag but we have "
        << Parser_parse0.getFlags().count(flag1) << " of them";
    ASSERT_EQ(1, Parser_parse0.getFlags().count(flag2))
        << "We should have one " << vec[2] << " flag but we have "
        << Parser_parse0.getFlags().count(flag2) << " of them";
    ASSERT_EQ(empty_string, Parser_parse0.getFlags().find(flag1)->second)
        << "Because we have only flags their message should be an empty string "
           "but for the first flag we have: "
        << Parser_parse0.getFlags().find(flag1)->second;
    ASSERT_EQ(empty_string, Parser_parse0.getFlags().find(flag2)->second)
        << "Because we have only flags their message should be an empty string "
           "but for the first flag we have: "
        << Parser_parse0.getFlags().find(flag2)->second;

    // testing with flags and messages
    vec.clear();
    vec.push_back(program_name);
    vec.push_back(flag1);
    vec.push_back(message1v0);
    vec.push_back(flag2);
    vec.push_back(message1v1);
    Parser_parse0.parse(vec);
    ASSERT_TRUE(Parser_parse0.getFlags().size() == 2)
        << "We should have two flags but we have "
        << Parser_parse0.getFlags().size() << " of them";
    ASSERT_EQ(1, Parser_parse0.getFlags().count(flag1))
        << "We should have one " << vec[1] << " flag but we have "
        << Parser_parse0.getFlags().count(flag1) << " of them";
    ASSERT_EQ(vec[2], Parser_parse0.getFlags().find(flag1)->second)
        << "We should have for flag " << vec[1] << " a message: " << vec[2]
        << " but we a following message: "
        << Parser_parse0.getFlags().find(flag1)->second;
    ASSERT_EQ(1, Parser_parse0.getFlags().count(flag2))
        << "We should have one " << vec[3] << " flag but we have "
        << Parser_parse0.getFlags().count(flag1) << " of them";
    ASSERT_EQ(vec[4], Parser_parse0.getFlags().find(flag2)->second)
        << "We should have for flag " << vec[3] << " a message: " << vec[4]
        << " but we a following message: "
        << Parser_parse0.getFlags().find(flag2)->second;

    /*we have already checked that parse function is working
     *now we check if we get correct flags and messages to them or empty string
     *in case of no flags we do not check scenario when we start from not a flag
     *because we always starts from none flag that is program name and
     *everything works fine
     */

    // 2 flags with no information
    char *argv1[] = {program_name, flag1, flag2};
    int argc1 = (int)(sizeof(argv1) / sizeof(argv1[0]));
    FlagParser Parser1(argc1, argv1);
    ASSERT_TRUE(Parser1.getFlags().size() == 2)
        << "We should have two flags but we have " << Parser1.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser1.getFlags().count(flag1))
        << "We should have one " << argv1[1] << " flag but we have "
        << Parser1.getFlags().count(flag1) << " of them";
    ASSERT_EQ(1, Parser1.getFlags().count(flag2))
        << "We should have one " << argv1[2] << " flag but we have "
        << Parser1.getFlags().count(flag2) << " of them";
    ASSERT_EQ(empty_string, Parser1.getFlags().find(flag1)->second)
        << "Because we have only flags their message should be an empty string "
           "but for the first flag we have: "
        << Parser1.getFlags().find(flag1)->second;
    ASSERT_EQ(empty_string, Parser1.getFlags().find(flag2)->second)
        << "Because we have only flags their message should be an empty string "
           "but for the first flag we have: "
        << Parser1.getFlags().find(flag2)->second;

    // flag + info for the flag with one word
    char *argv2[] = {program_name, flag1, message1v0};
    int argc2 = (int)(sizeof(argv2) / sizeof(argv2[0]));
    FlagParser Parser2(argc2, argv2);
    ASSERT_TRUE(Parser2.getFlags().size() == 1)
        << "We should have one flag but we have " << Parser2.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser2.getFlags().count(flag1))
        << "We should have one " << argv2[1] << " flag but we have "
        << Parser2.getFlags().count(flag1) << " of them";
    ASSERT_NE(1, Parser2.getFlags().count(message1v0))
        << "We should have none  " << argv2[2] << " flag but we have "
        << Parser2.getFlags().count(message1v0) << " of them";
    ASSERT_EQ(argv2[2], Parser2.getFlags().find(flag1)->second)
        << "We should have a message: " << argv2[2]
        << " but we a following message: "
        << Parser2.getFlags().find(flag1)->second;
    ;

    // flag +info for the flag with more than one word
    char *argv3[] = {program_name, flag1, message1v0, message1v0};
    int argc3 = (int)(sizeof(argv3) / sizeof(argv3[0]));
    FlagParser Parser3(argc3, argv3);
    ASSERT_TRUE(Parser3.getFlags().size() == 1)
        << "We should have one flag but we have " << Parser3.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser3.getFlags().count(flag1))
        << "We should have one " << argv3[1] << " flag but we have "
        << Parser3.getFlags().count(flag1) << " of them";
    ASSERT_NE(1, Parser3.getFlags().count(message1v1))
        << "We should have none " << argv3[2] << " flag but we have "
        << Parser3.getFlags().count(message1v1) << " of them";
    ASSERT_EQ(argv3[2], Parser3.getFlags().find(flag1)->second)
        << "We should have a message: " << argv3[2]
        << " but we a following message: "
        << Parser3.getFlags().find(flag1)->second;

    // one flags with in case there are two messages after the flag
    char *argv4[] = {program_name, flag1, message1v0, flag2, message1v1};
    int argc4 = (int)(sizeof(argv4) / sizeof(argv4[0]));
    FlagParser Parser4(argc4, argv4);
    ASSERT_TRUE(Parser4.getFlags().size() == 2)
        << "We should have two flags but we have " << Parser4.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser4.getFlags().count(flag1))
        << "We should have one " << argv4[1] << " flag but we have "
        << Parser4.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv4[2], Parser4.getFlags().find(flag1)->second)
        << "We should have for flag " << argv4[1] << " a message: " << argv4[2]
        << " but we a following message: "
        << Parser4.getFlags().find(flag1)->second;
    ASSERT_EQ(1, Parser4.getFlags().count(flag2))
        << "We should have one " << argv4[3] << " flag but we have "
        << Parser4.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv4[4], Parser4.getFlags().find(flag2)->second)
        << "We should have for flag " << argv4[3] << " a message: " << argv4[4]
        << " but we a following message: "
        << Parser4.getFlags().find(flag2)->second;

    // first flag has empty string as a value, the secon flag has a message as a
    // value
    char *argv5[] = {program_name, flag1, flag2, message1v0};
    int argc5 = (int)(sizeof(argv5) / sizeof(argv5[0]));
    FlagParser Parser5(argc5, argv5);
    ASSERT_TRUE(Parser5.getFlags().size() == 2)
        << "We should have two flags but we have " << Parser5.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser5.getFlags().count(flag1))
        << "We should have one " << argv5[1] << " flag but we have "
        << Parser5.getFlags().count(flag1) << " of them";
    ASSERT_EQ(empty_string, Parser5.getFlags().find(flag1)->second)
        << "Because we have only flags their message should be an empty string "
           "but for the first flag we have: "
        << Parser5.getFlags().find(flag1)->second;
    ASSERT_EQ(1, Parser5.getFlags().count(flag2))
        << "We should have one " << argv5[1] << " flag but we have "
        << Parser5.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv5[3], Parser5.getFlags().find(flag2)->second)
        << "We should have a message: " << argv5[3]
        << " but we a following message: "
        << Parser5.getFlags().find(flag2)->second;

    // no flags
    char *argv6[] = {program_name};
    int argc6 = (int)(sizeof(argv6) / sizeof(argv6[0]));
    FlagParser Parser6(argc6, argv6);
    ASSERT_TRUE(Parser6.getFlags().size() == 0)
        << "We should have zero flags but we have " << Parser6.getFlags().size()
        << " of them";

    // two flags, the first is with more than one word message(2 argvs) and the
    // second is the flag with one word message(1 argv)
    char *argv7[] = {program_name, flag1, message1v0,
                     message1v1,   flag2, message1v2};
    int argc7 = (int)(sizeof(argv7) / sizeof(argv7[0]));
    FlagParser Parser7(argc7, argv7);
    ASSERT_TRUE(Parser7.getFlags().size() == 2)
        << "We should have two flags but we have " << Parser7.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser7.getFlags().count(flag1))
        << "We should have one " << argv7[1] << " flag but we have "
        << Parser7.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv7[2], Parser7.getFlags().find(flag1)->second)
        << "We should have for flag " << argv7[1] << " a message: " << argv7[2]
        << " but we a following message: "
        << Parser7.getFlags().find(flag1)->second;
    ASSERT_EQ(1, Parser7.getFlags().count(flag2))
        << "We should have one " << argv7[3] << " flag but we have "
        << Parser7.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv7[5], Parser7.getFlags().find(flag2)->second)
        << "We should have for flag " << argv7[4] << " a message: " << argv7[5]
        << " but we a following message: "
        << Parser7.getFlags().find(flag2)->second;

    // two flags, the first is the flag with one word message(1 argv) and the
    // second is with more than one word message(2 argvs)
    char *argv8[] = {program_name, flag1,      message1v0,
                     flag2,        message1v1, message1v2};
    int argc8 = (int)(sizeof(argv8) / sizeof(argv8[0]));
    FlagParser Parser8(argc8, argv8);
    ASSERT_TRUE(Parser8.getFlags().size() == 2)
        << "We should have two flags but we have " << Parser8.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser8.getFlags().count(flag1))
        << "We should have one " << argv8[1] << " flag but we have "
        << Parser8.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv8[2], Parser8.getFlags().find(flag1)->second)
        << "We should have for flag " << argv8[1] << " a message: " << argv8[2]
        << " but we a following message: "
        << Parser8.getFlags().find(flag1)->second;
    ASSERT_EQ(1, Parser8.getFlags().count(flag2))
        << "We should have one " << argv8[3] << " flag but we have "
        << Parser8.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv8[4], Parser8.getFlags().find(flag2)->second)
        << "We should have for flag " << argv8[3] << " a message: " << argv8[4]
        << " but we a following message: "
        << Parser8.getFlags().find(flag2)->second;

    // two flags, both are with more than one word message(2 argvs)
    char *argv9[] = {program_name, flag1,      message1v0, message1v1,
                     flag2,        message1v2, message1v3};
    int argc9 = (int)(sizeof(argv9) / sizeof(argv9[0]));
    FlagParser Parser9(argc9, argv9);
    ASSERT_TRUE(Parser9.getFlags().size() == 2)
        << "We should have two flags but we have " << Parser9.getFlags().size()
        << " of them";
    ASSERT_EQ(1, Parser9.getFlags().count(flag1))
        << "We should have one " << argv9[1] << " flag but we have "
        << Parser9.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv9[2], Parser9.getFlags().find(flag1)->second)
        << "We should have for flag " << argv9[1] << " a message: " << argv9[2]
        << " but we a following message: "
        << Parser9.getFlags().find(flag1)->second;
    ASSERT_EQ(1, Parser9.getFlags().count(flag2))
        << "We should have one " << argv9[3] << " flag but we have "
        << Parser9.getFlags().count(flag1) << " of them";
    ASSERT_EQ(argv9[5], Parser9.getFlags().find(flag2)->second)
        << "We should have for flag " << argv9[4] << " a message: " << argv9[5]
        << " but we a following message: "
        << Parser9.getFlags().find(flag2)->second;

    // Since we know what values map flags has we can check if hasKey works
    // correctly
    ASSERT_TRUE(Parser1.hasKey(flag1))
        << "We should have a flag " << flag1 << " but it seems missing";
    ASSERT_TRUE(Parser1.hasKey(flag2))
        << "We should have a flag " << flag2 << " but it seems missing";
    ASSERT_TRUE(Parser2.hasKey(flag1))
        << "We should have a flag " << flag1 << " but it seems missing";
    ASSERT_FALSE(Parser2.hasKey(flag2)) << "We can NOT have a flag " << flag2;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
