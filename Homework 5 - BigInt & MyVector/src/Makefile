all:BigInt.o MyVector.o main.o 
	g++ -g -o main.out main.o BigInt.o MyVector.o
BigInt.o: BigInt.cpp BigInt.h
	g++ -c BigInt.cpp
MyVector.o: MyVector.cpp MyVector.h
	g++ -c MyVector.cpp
main.o: main.cpp BigInt.h MyVector.h
	g++ -c main.cpp
clean:
	rm -f *.o*
