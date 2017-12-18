//
// Created by alright on 12.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/SecondEntrance.h"

TEST(SecondEntranceTest, BasicTests) {
    EXPECT_EQ(-1, second_entrance("comfort"));
    EXPECT_EQ(-2, second_entrance("car"));
    EXPECT_EQ(3, second_entrance("coffe"));
}
