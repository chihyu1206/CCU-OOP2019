all: intset.o main.o
	g++ -o main.out intset.o main.o
intset.o: intset.cpp intset.h
	g++ intset.cpp -c
main.o: main.cpp intset.h
	g++ main.cpp -c
clean:
	rm *.o main.out
