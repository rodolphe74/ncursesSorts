#include <curses.h>
#include <form.h>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime> 
#include <utility>

int x, y;
int sz = 0;
unsigned char *array;

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
                dispArray();
            }
        }
    }
}

void optBubbleSort()
{
    bool sorted; 
    for (int i = sz - 1; i >= 1; i--) {
        sorted = true;
        for (int j = 0; j <= i - 1; j++) {
            if (array[j + 1] < array[j]) {
                std::swap(array[j + 1], array[j]);
                sorted = false;
                dispArray();
            }
        }
        if (sorted)
            return;
    }
}


void jumpDownSort()
{
    for (int i = sz - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (array[i] < array[j]) {
                std::swap(array[i], array[j]);
                dispArray();
            }
        }
    }

}



int main(int argc, char *argv[])
{
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
    dispArray();
    getch();

    jumpDownSort();
    getch();

    delete[] array;
    endwin();			/* End curses mode		  */
    return 0;
}

