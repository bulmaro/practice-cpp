#include "isPrime.cpp"
#include "gtest/gtest.h"

namespace {
	class PrimeTest{};

	TEST(PrimeTest, neg) {
		EXPECT_FALSE(isPrime(-1));
	};
	TEST(PrimeTest, zero) {
		EXPECT_FALSE(isPrime(0));
	};
	TEST(PrimeTest, n1) {
		EXPECT_TRUE(isPrime(1));
	};
	TEST(PrimeTest, n2) {
		EXPECT_TRUE(isPrime(2));
	};
	TEST(PrimeTest, n3) {
		EXPECT_TRUE(isPrime(3));
	};
	TEST(PrimeTest, n4) {
		EXPECT_FALSE(isPrime(4));
	};
	TEST(PrimeTest, n5) {
		EXPECT_TRUE(isPrime(5));
	};
	TEST(PrimeTest, n6) {
		EXPECT_FALSE(isPrime(6));
	};
}

/* 
 * Test runner. Entry point.
 */
int main (int argc, char** argv) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}

