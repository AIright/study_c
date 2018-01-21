//
// Created by alright on 15/01/2018.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../src/headers/FinalTask.cpp"

using namespace std;

TEST(Positive, DatabaseFind) {
    testing::internal::CaptureStdout();
    Database testdb;
    testdb.AddEvent(Date(0,1,2), "event1");
    testdb.AddEvent(Date(0,1,2), "event2");
    testdb.AddEvent(Date(0,1,3), "event3");
    testdb.Find(Date(0,1,2));
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("event1\nevent2\n", output);
};

TEST(Positive, DatabasePrint) {
    testing::internal::CaptureStdout();
    Database testdb;
    testdb.AddEvent(Date(0,1,2), "event1");
    testdb.AddEvent(Date(0,1,2), "event2");
    testdb.AddEvent(Date(0,1,1), "event3");
    testdb.Print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0000-01-01 event3\n0000-01-02 event1\n0000-01-02 event2\n", output);
}

