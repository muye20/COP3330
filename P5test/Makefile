big: main.o myint.o
	g++ -o big main.o myint.o

main.o: myint.h main.cpp
	g++ -c main.cpp

myint.o: myint.h myint.cpp
	g++ -c myint.cpp

clean:
	rm *.o big

