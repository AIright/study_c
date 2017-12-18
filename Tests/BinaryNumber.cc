//
// Created by alright on 14.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/BinaryNumber.h"
using namespace std;

TEST(BinaryNumber, BasicTests) {
    EXPECT_EQ("101", binary_number(5));
    EXPECT_EQ("100000", binary_number(32));
    EXPECT_EQ("1", binary_number(1));
    EXPECT_EQ("0", binary_number(0));
}