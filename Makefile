CC=g++
CFLAGS=-Wall -Werror -O2
CLIBS=-lcurses -lform

all: Array

Array: main.o 
	$(CC) $(CFLAGS) -o Array main.o $(CLIBS)

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 


.PHONY: clean

clean:
	-rm -f *.o Array
