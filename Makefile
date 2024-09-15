CC=g++
CFLAGS=-Wall -Werror -O2
CLIBS=-lcurses -lform -lcaca

all: Array BubbleTh CacaTest CacaSort

Array: main.o 
	$(CC) $(CFLAGS) -o Array main.o $(CLIBS)

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

BubbleTh: bubbleth.o
	$(CC) $(CFLAGS) -o BubbleTh bubbleth.o $(CLIBS)

bubbleth.o: bubbleth.cpp
	$(CC) $(CFLAGS) -c bubbleth.cpp


CacaTest: cacatest.o
	$(CC) $(CFLAGS) -o CacaTest cacatest.o $(CLIBS)

cacatest.o: cacatest.cpp
	$(CC) $(CFLAGS) -c cacatest.cpp

CacaSort: cacasort.o
	$(CC) $(CFLAGS) -o CacaSort cacasort.o $(CLIBS)

cacasort.o: cacasort.cpp
	$(CC) $(CFLAGS) -c cacasort.cpp


.PHONY: clean

clean:
	-rm -f *.o Array BubbleTh CacaTest CacaSort
