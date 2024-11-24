#include <unistd.h>
#include <string.h>
#include "malloc.h"

void *calloc(size_t amount, size_t size) {
    size_t total_size;

    if (amount != 0 && size > HEADER_SIZE / amount) {
        return NULL;
    }

    total_size = amount * size;

    void *ptr = malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}
