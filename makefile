test: test.o
	g++ test.o -o test
	rm test.o

test.o:
	g++ test.cpp -ansi -Wall -pedantic -pedantic-errors -c