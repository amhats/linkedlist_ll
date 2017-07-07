CC = g++
INCLUDE = -I~/Desktop/googletest/googletest/include
LIBS = -L~/Desktop/googletest/googletest
FLAGS = -lgtest -lgtest_main

all: linkedlist

linkedlist.o : linkedlist.cpp
	$(CC) -o $@ -c $< $(LIBS) $(FLAGS)

linkedlist : linkedlist.o
	$(CC) $< -o $@ $(INCLUDE)



clean:
	rm *.o *~ linkedlist
