#include <aio.h>
#include <unistd.h>
#include "malloc.h"

typedef char ALIGN[16];

union header {
    struct {
        size_t size;
        unsigned is_free;
        union header *next;
    } s;
    ALIGN stub;
};

typedef union header header_t;

void *malloc(size_t size) {
    void *block;
    block = sbrk(size);
    if (block == (void*) - 1) {
        return NULL;
    }
    return block;
}
