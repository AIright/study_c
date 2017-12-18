//
// Created by alright on 16.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "../src/headers/Palindrom.h"
using namespace std;


TEST(IsPalindrom, BasicTests) {
    EXPECT_EQ(true, IsPalindrom("madam"));
    EXPECT_EQ(false, IsPalindrom("gentleman"));
    EXPECT_EQ(true, IsPalindrom("X"));
    EXPECT_EQ(true, IsPalindrom(""));
}

TEST(PalindromFilter, BasicTests) {
    EXPECT_EQ(vector<string> {"abacaba"}, PalindromFilter(vector<string> {"abacaba", "aba"}, 5));
    EXPECT_EQ((vector<string> {"abacaba", "aba"}), PalindromFilter(vector<string> {"abacaba", "aba"}, 2));
    EXPECT_EQ((vector<string> {"weew"}), PalindromFilter(vector<string> {"weew", "bro", "code"}, 4));
}