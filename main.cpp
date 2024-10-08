#include <curses.h>
#include <form.h>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime> 
#include <type_traits>
#include <utility>
#include <math.h>

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

void combSort()
{
    float interval = sz;
    int iinterval;
    bool swap = false;
    int i = 0;
    while (interval > 1 || swap == true) {
        interval = interval / 1.3f;
        if (interval < 1)
            interval = 1;

        i = 0;
        swap = false;
        iinterval = (int) roundf(interval);

        while (i < (sz - iinterval)) {
            if (array[i] > array[i + iinterval]) {
                std::swap(array[i], array[i + iinterval]);
                swap = true;
                dispArray();
            }
            i++;
        }
    }
}


int partition(int first, int last, int pivot)
{
    std::swap(array[pivot], array[last]);
    int j = first;
    for (int i = first; i < last; i++) {
        if (array[i] <= array[last]) {
            std::swap(array[i], array[j]);
            // dispArray();
            j++;
        }
    }
    std::swap(array[last], array[j]);
    dispArray();
    return j;
}

void quickSort(int first, int last)
{
    if (first < last) {
        int pivot = (rand() % (last - first)) + first;
        pivot = partition(first, last, pivot);
        quickSort(first, pivot - 1);
        quickSort(pivot + 1, last);
    }
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
    dispArray();
    getch();

    //jumpDownSort();
    //combSort();
    //bubbleSort();
    quickSort(0, sz - 1);
    getch();

    delete[] array;
    endwin();			/* End curses mode		  */
    return 0;
}

