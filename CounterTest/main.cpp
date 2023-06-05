#include <UnitTest++/UnitTest++.h>
#include "Counter.h"
#include <iostream>
#include <string>

using namespace std;


SUITE(meanTest)
{
	TEST(Default) {
		std::vector<int64_t> arr ={10, 20 ,30 ,40, 50};
		CHECK_EQUAL(5500,*( Counter().squares(arr)));
	}
	TEST(DefaultPlus) {
		std::vector<int64_t> arr ={20, 30 ,60};
		CHECK_EQUAL(4900,*( Counter().squares(arr)));
	}
	TEST(Negative) {
		std::vector<int64_t> arr ={-10, -20 ,-30 ,-40, -50};
		CHECK_EQUAL(5500,*( Counter().squares(arr)));
	}
	TEST(MaximumPositive) {
		std::vector<int164_t> arr ={32767, 32767 ,32767};
		CHECK_EQUAL(32767,*( Counter().squares(arr)));
	}
	TEST(MaximumNegative) {
		std::vector<int64_t> arr ={-32768, -32768 ,-32768};
		CHECK_EQUAL(32767,*( Counter().squares(arr)));
	}
	TEST(Different) {
		std::vector<int64_t> arr ={10, -20 ,30 ,-40};
		CHECK_EQUAL(3000,*( Counter().squares(arr)));
	}
	TEST(Owerflow) {
			std::vector<int64_t> arr ={};
		CHECK_THROW(Counter().mean(arr),server_error);
	}
}


int main()
{
	return UnitTest::RunAllTests();
}
