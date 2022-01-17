all: main.o Portfolio.o Account.o Checking.o Investment.o Savings.o
	g++ -std=c++11 -o main.out main.o Portfolio.o Account.o Checking.o Investment.o Savings.o
main.o: main.cpp
	g++ -c main.cpp
Portfolio.o: Portfolio.cpp Portfolio.h
	g++ -c Portfolio.cpp
Account.o: Account.cpp Account.h
	g++ -c Account.cpp
Checking.o: Checking.cpp Checking.h
	g++ -c Checking.cpp
Investment.o: Investment.cpp Investment.h
	g++ -c Investment.cpp
Savings.o: Savings.cpp Savings.h
	g++ -c Savings.cpp
clean:
	rm *.o main.out 
