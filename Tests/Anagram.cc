//
// Created by alright on 18.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/Anagram.h"
using namespace std;

TEST(Anagram, BasicTests) {
    EXPECT_EQ("YES", Anagram("joyson", "yojnos"));
    EXPECT_EQ("NO", Anagram("kill", "me"));
    EXPECT_EQ("NO", Anagram("foo", "bar"));
    EXPECT_EQ("YES", Anagram("", ""));
}
