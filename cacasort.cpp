#include <caca.h>
#include <cstdlib>
#include <utility>
#include <stdio.h>

caca_canvas_t *cv; caca_display_t *dp; caca_event_t ev;
int x, y;
int sz = 0;
unsigned char *array;

void dispArray()
{
    int k = 0;
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            caca_put_char(cv, i, j, (unsigned char) array[k++]);
        }
    }
    caca_refresh_display(dp);
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


int main(void)
{

    dp = caca_create_display(NULL);
    if(!dp) return 1;
    cv = caca_get_canvas(dp);
    x = caca_get_canvas_width(cv);
    y = caca_get_canvas_height(cv);
    sz = x * y;

    array = new unsigned char[sz];
    for (int i = 0; i < sz; i++) {
        array[i] = (rand() % 94) + 33;
    }

    caca_set_display_title(dp, "CacaSort");
    caca_set_color_ansi(cv, CACA_BLACK, CACA_WHITE);

    dispArray();
    /* caca_refresh_display(dp); */
    caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, -1); 

    bubbleSort();
    caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, -1); 

    caca_free_display(dp);
    return 0;
}
