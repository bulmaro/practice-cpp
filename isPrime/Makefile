GTEST=/Users/esteban/Dev/practice-cpp/isPrime/gtest

test :
	g++ tests.cpp $(GTEST)/src/gtest-all.cc \
		-isystem $(GTEST) -pthread \
		-o tests
	./tests

