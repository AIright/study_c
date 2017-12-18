//
// Created by alright on 12.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/MaxCommonDivisor.h"

TEST(MaxCommonDivisorTest, BasicTests) {

    EXPECT_EQ(1, max_common_divisor(25, 27));
    EXPECT_EQ(4, max_common_divisor(12, 16));
    EXPECT_EQ(13, max_common_divisor(13, 13));
    EXPECT_EQ(48, max_common_divisor(384, 48));

}