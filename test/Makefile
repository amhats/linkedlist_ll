CC = g++
INCLUDE = -I ../gtest/include
LIBS = -L ../gtest
FLAGS = -lgtest -lgtest_main -pthread

all: linkedlisttest

linkedlisttest.o : linkedlisttest.cpp
	$(CC) -o $@  $(INCLUDE) -c $<

linkedlisttest : linkedlisttest.o
	$(CC)  $< -o $@ $(LIBS) $(FLAGS)



clean:
	rm *.o *~ linkedlisttest
