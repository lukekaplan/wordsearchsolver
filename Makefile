#Luke Kaplan
#sjd7wr
#10-17-22
#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Ofast -Wall
DEBUG=-g

a.out: wordPuzzle.o hashTable.o timer.o
	$(CXX) wordPuzzle.o hashTable.o timer.o -o a.out

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
