#include "bada_context.h"
#include "bada.h"
#include "status.h"
#include "conf.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

// The fixture for testing class Foo.
class BadaTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        BadaTest() {
            // You can do set-up work for each test here.
        }

        virtual ~BadaTest() {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        virtual void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
};

TEST_F(BadaTest, CheckTest) {
    const char* hostname = "127.0.0.1";
    const char* table = "vrs";
    Status s;
    BadaClient *b = new BadaClient(hostname, 9166, table);
    s = b->Connect();
    EXPECT_TRUE(s.ok());
}

TEST_F(BadaTest, GetAndSet) {
    const char* hostname = "127.0.0.1";
    const char* table = "vrs";
    Status s;
    BadaClient *b = new BadaClient(hostname, 9166, table);
    s = b->Connect();
    EXPECT_TRUE(s.ok());
    s = b->badaContext()->SetBlockType(kBlock);
    EXPECT_TRUE(s.ok());
    string key = "key";
    string value = "value";
    s = b->Set(key, value);
    EXPECT_TRUE(s.ok());
    string result;
    s = b->Get(key, &result);
    EXPECT_EQ(result, value);
}