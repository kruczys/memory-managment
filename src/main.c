#include <stdio.h>
#include "malloc.h"
#include "free.h"

int main() {
    char *hello = malloc(6);
    char *world = malloc(6);

    hello[0] = 'H';
    hello[1] = 'e';
    hello[2] = 'l';
    hello[3] = 'l';
    hello[4] = 'o';
    hello[5] = '\0';

    world[0] = 'W';
    world[1] = 'o';
    world[2] = 'r';
    world[3] = 'l';
    world[4] = 'd';
    world[5] = '\0';
    
    printf("%s %s!\n", hello, world);

    free(hello);
    free(world);

    return 0;
}
