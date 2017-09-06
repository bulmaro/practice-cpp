#include "isPrime.cpp"
#include "gtest/gtest.h"
namespace {

	class PrimeTest{};

	TEST(PrimeTest, failsAlways) {
		EXPECT_EQ(0,1);
	};

};


/* 
 * Test runner. Entry point.
 */
int main (int argc, char** argv) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}

