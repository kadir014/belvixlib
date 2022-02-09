#include <stdio.h>
#include "belvixlib.h"


int main() {
    bv_DateTime dt1 = bv_DateTime_new(2015, 6, 12, 17, 19, 0);

    printf("new datetime: %d.%d.%d %d:%d:%d\n", dt1.year, dt1.month, dt1.day, dt1.hour, dt1.minute, dt1.second);


    bv_DateTime dt2 = bv_DateTime_now();

    printf("now: %d.%d.%d %d:%d:%d\n", dt2.year, dt2.month, dt2.day, dt2.hour, dt2.minute, dt2.second);


    printf("datetime less than: %d\n", bv_DateTime_lt(dt1, dt2));
}