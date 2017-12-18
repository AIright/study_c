//
// Created by alright on 12.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/Discount.h"
using namespace std;

TEST(Discount, BasicTests) {
    EXPECT_EQ(100, discount(100, 110, 120, 5, 10));
    EXPECT_EQ(109.25, discount(115, 110, 120, 5, 10));
    EXPECT_EQ(131.25, discount(150, 110, 120, 5, 12.5));
}