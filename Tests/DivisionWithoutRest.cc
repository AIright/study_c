#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/DivisionWithoutRest.h"
using namespace std;


TEST(DivisionWithoutRestTest, BasicTests) {

    EXPECT_EQ("5", division_without_rest(10, 2));
    EXPECT_EQ("0", division_without_rest(3, 5));
    EXPECT_EQ("Impossible", division_without_rest(11, 0));

}

