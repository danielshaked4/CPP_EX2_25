# Email: sone0149@gmail.com

CXX = g++
CXXFLAGS = -Wall -g

all: Main test

Main: SquareMat.o Main.o
	$(CXX) SquareMat.o Main.o -o Main

test: SquareMat.o Tests.o
	$(CXX) SquareMat.o Tests.o -o Tests
	./Tests

SquareMat.o: SquareMat.cpp SquareMat.h
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

Main.o: Main.cpp SquareMat.h
	$(CXX) $(CXXFLAGS) -c Main.cpp

Tests.o: Tests.cpp SquareMat.h doctest.h
	$(CXX) $(CXXFLAGS) -c Tests.cpp

valgrind: Main
	valgrind --leak-check=full ./Main

clean:
	rm -f *.o Main Tests