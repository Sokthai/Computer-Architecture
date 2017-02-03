all: ps1
ps1: main.o
	g++ main.o -o hw1 -Wall -ansi -pedantic -Werror
main.o: main.cpp
	g++ -c -Wall -ansi -pedantic -Werror main.cpp
clean:
	rm *.o hw1
