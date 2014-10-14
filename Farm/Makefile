farm: farm.o main.o
        g++ -o farm farm.o main.o

farm.o: farm.h farm.cpp
        g++ -c farm.cpp

main.o: farm.h main.cpp
        g++ -c main.cpp

clean:
        rm *.o farm