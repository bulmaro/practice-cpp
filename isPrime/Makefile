GTEST=./gtest

test :
	g++ tests.cpp $(GTEST)/src/gtest-all.cc \
		-isystem $(GTEST) -pthread \
		-o tests.o
	./tests.o

