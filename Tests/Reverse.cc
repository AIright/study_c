//
// Created by alright on 17.12.17.
//
#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "../src/headers/Reverse.h"

using namespace std;

class TestReverse : public ::testing::Test {
public:
    void SetUp() {  }
    void TearDown() {  }

protected:
    /* none yet */
};

TEST_F(TestReverse, BasicTestReverse) {
    vector<int> a = {1, 5, 3, 4, 2};
    Reverse(a);
    EXPECT_EQ((vector<int> {2, 4, 3, 5, 1}), a);
}

TEST_F(TestReverse, BasicTestReversed) {
    vector<int> a = {1, 5, 3, 4, 2};
    EXPECT_EQ((vector<int> {2, 4, 3, 5, 1}), Reversed(a));
}