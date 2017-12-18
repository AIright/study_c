//
// Created by alright on 17.12.17.
//
#include <gtest/gtest.h>
#include <iostream>
#include <../src/headers/Maximizator.h>

class TestMaximizator : public ::testing::Test {
public:
    void SetUp() {
//        int a, b;
    }
    void TearDown() {
//        delete(a);
//        delete(b);
    }

protected:
    /* none yet */
};

TEST_F(TestMaximizator, Lower) {
    int a = 3;
    int b = 6;
    UpdateIfGreater(a, b);
    ASSERT_GT(b, a);
}

TEST_F(TestMaximizator, Greater) {
    int c = 6;
    int d = 3;
    UpdateIfGreater(c, d);
    ASSERT_EQ(d, c);
}

TEST_F(TestMaximizator, Equal) {
    int e = 3;
    int f = 3;
    UpdateIfGreater(e, f);
    ASSERT_EQ(f, e);
}

