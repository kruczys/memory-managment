#include "memblock.h"
#include "free.h"

void free(void *ptr) {
    if (!ptr) {
        return;
    }

    header *block_ptr = (header* )ptr - 1;
    block_ptr->free = 1;
}
