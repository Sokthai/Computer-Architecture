all: ps1
ps1: main.o hw1.o
	g++ -std=c++11 main.o hw1.o -o hw1 -Wall -ansi -pedantic -Werror
main.o: main.cpp
	g++ -std=c++11 -c -Wall -ansi -pedantic -Werror main.cpp
hw1.o: hw1.cpp hw1.hpp
	g++ -std=c++11 -c -Wall -ansi -pedantic -Werror hw1.cpp
clean:
	rm *.o hw1
