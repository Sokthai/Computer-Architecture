all: ps2
ps2: main.o
	g++ main.o -o hw2 -Wall -ansi -pedantic -Werror
main.o: main.cpp
	g++ -c -Wall -ansi -pedantic -Werror main.cpp
clean:
	rm *.o hw2
