//
// Created by alright on 17.12.17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "../src/headers/MoveStrings.h"

using namespace std;

class TestMoveStrings : public ::testing::Test {
public:
    void SetUp() {  }
    void TearDown() {  }

protected:
    /* none yet */
};

TEST_F(TestMoveStrings, Positive) {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    EXPECT_EQ(source, (vector<string> {}));
    EXPECT_EQ((vector<string> {"z", "a", "b", "c"}), destination);
}
