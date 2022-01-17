all: cpphw1 javahw1.class
cpphw1: cpphw1.o
	g++ cpphw1.o -o cpphw1
cpphw1.o: cpphw1.cpp
	g++ -c -g cpphw1.cpp
javahw1.class: javahw1.java
	javac javahw1.java
clean:cpphw1 cpphw1.o javahw1.class
	rm cpphw1 cpphw1.o javahw1.class
