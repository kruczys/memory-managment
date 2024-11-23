#include <unistd.h>
#include "malloc.h"

void *global_base = NULL; // pierwszy wskaznik na kopcu, inicjalizowany przy pierwszym callu do malloca

header *find_free_block(header **last, size_t size) {
    header *current = global_base;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

header *request_space(header *last, size_t size) {
    header *block;
    block = sbrk(0);
    void *request = sbrk(size + HEADER_SIZE);
    if (request == (void*) -1) {
        return NULL;
    }

    if (last) {
        last->next = block; 
    }

    block->size = size;
    block->next = NULL;
    block->free = 0;
    return block;
}
