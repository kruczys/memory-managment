#include <stdio.h>
#include "malloc.h"

int main() {
    char *hewwo, *wowwd;

    hewwo = malloc(6);

    hewwo[0] = 'H';
    hewwo[1] = 'e';
    hewwo[2] = 'l';
    hewwo[3] = 'l';
    hewwo[4] = 'o';
    hewwo[5] = '\0';


    printf("%s %s!\n", hewwo, wowwd);

    free(hewwo);

    wowwd = malloc(6);
    wowwd[0] = 'W';
    wowwd[1] = 'o';
    wowwd[2] = 'r';
    wowwd[3] = 'l';
    wowwd[4] = 'd';
    wowwd[5] = '\0';

    printf("%s %s!\n", hewwo, wowwd);

    return 0;
}
