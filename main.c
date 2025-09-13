#include <stdio.h>
#include "ArrayList.h"

int main() {
    PArrayList arraylist = newArrayList();
    for (int i = 0; i < 10000; i++) {
        Value a = { .Integer = 50 + i };
        ArrayList_add(arraylist, a);
    }
    printf("=================================\n");
    for (int i = 0; i < 10000; i++) {
        Value a = ArrayList_get(arraylist, i);
        printf("%d\t", a.Integer);
        if ((i + 1) % 7 == 0) printf("\n");
    }
    printf("\nHello world");
    Value a = { .Integer = 50 };
    printf("\nfirst=%d", ArrayList_firstOf(arraylist, a, type_int));
    NULL;
    a.Integer = 200;
    printf("\nfirst=%d", ArrayList_lastOf(arraylist, a, type_int));
    ArrayList_free(&arraylist);
    return 0;
}