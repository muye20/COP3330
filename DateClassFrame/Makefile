Date: main.o date.o
	g++ -o Date main.o date.o

main.o: date.h main.cpp
	g++ -c main.cpp
	
date.o: date.h date.cpp
	g++ -c date.cpp
	
clean:
	rm *.o Date