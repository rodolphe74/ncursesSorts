CC=g++
CFLAGS=-Wall -Werror -O2
CLIBS=-lcurses -lform

all: SudokuResolver

SudokuResolver: main.o 
	$(CC) $(CFLAGS) -o Array main.o $(CLIBS)

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp $(CLIBS)


.PHONY: clean

clean:
	-rm -f *.o Array
