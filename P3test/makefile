main: main.o distance.o
	g++ -o main main.o distance.o
distance.o: distance.cpp distance.h
	g++ -c distance.cpp
main.o: main.cpp distance.h
	g++ -c main.cpp
clean:
	rm -f *.o main
