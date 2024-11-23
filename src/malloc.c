#include <unistd.h>
#include "malloc.h"

void *global_base = NULL; 

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

void *malloc(size_t size) {
    header *block;

    if (size <= 0) {
        return NULL;
    }
    
    if (!global_base) {
        block = request_space(NULL, size);
        if (!block) {
            return NULL;
        }
        global_base = block;
    } else {
        header *last = global_base;
        block = find_free_block(&last, size);
        if (!block) {
            block = request_space(last, size);
            if (!block) {
                return NULL;
            }
        } else {
            block->free = 0;
        }
    }
    return (block + 1);
}

void free(void *ptr) {
    if (!ptr) {
        return;
    }

    header *block_ptr = (header* )ptr - 1;
    block_ptr->free = 1;
}
