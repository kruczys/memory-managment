#include <stdio.h>
#include "malloc.h"
#include "calloc.h"

int main() {
    int *arr;

    arr = calloc(6, sizeof(char));

    for (int i; i < 6; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
