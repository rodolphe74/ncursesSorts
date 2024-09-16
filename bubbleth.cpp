#include <curses.h>
#include <form.h>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime> 
#include <type_traits>
#include <utility>
#include <math.h>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int x, y;
int sz = 0;
unsigned char *array;
bool loop = true;

void dispArray()
{
    // wclear(stdscr);
    mvwaddch(stdscr, 0, 0, array[0]);
    for (int i = 0; i < sz; i++)
        waddch(stdscr, array[i]);
    refresh();
}

void bubbleSort()
{
    for (int i = sz - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (array[j + 1] < array[j]) {
                std::swap(array[j + 1], array[j]);
                //dispArray();
            }
        }
        std::this_thread::sleep_for(1ms);
    }
    loop = false;
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    initscr();			/* Start curses mode 		  */
    x = getmaxx(stdscr);
    y = getmaxy(stdscr);
    printw("%d x %d", x, y);
    sz = x * y;
    refresh();
    getch();			/* Wait for user input */

    array = new unsigned char[x * y];
    for(int i = 0; i < sz; i++)
        array[i] = (rand() % 94) + 33; 

    std::thread sortThread(bubbleSort);
    while(loop) {
        dispArray();
        std::this_thread::sleep_for(20ms);
    }
    sortThread.join();
    getch();

    delete[] array;
    endwin();			/* End curses mode		  */
    return 0;
}

