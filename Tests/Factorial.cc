//
// Created by alright on 16.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/Factorial.h"
using namespace std;

TEST(Factorial, BasicTests) {
    EXPECT_EQ(1, factorial(1));
    EXPECT_EQ(1, factorial(-2));
    EXPECT_EQ(24, factorial(4));
    EXPECT_EQ(1, factorial(0));
}