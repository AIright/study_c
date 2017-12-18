//
// Created by alright on 12.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/EvenNumbers.h"

TEST(EvenNumbersTest, BasicTests) {

    EXPECT_EQ("2 4 6 8 10 ", even_numbers(1, 10));
    EXPECT_EQ("2 ", even_numbers(2, 3));
    EXPECT_EQ("10 ", even_numbers(9, 11));

}
