#include <string.h>
#include <unistd.h>
#include "realloc.h"
#include "malloc.h"
#include "free.h"

void *realloc(void *ptr, size_t size) {
    if (ptr == NULL) 
        return malloc(size);
    
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    header *block = (header*) ptr - 1;

    if (block->size >= size) {
        return ptr;
    }

    if (block->next && block->next->free && block->size + block->next->size >= size) {
        block->size = block->size + block->next->size;
        block->next = block->next->next;
        return ptr;
    }

    void *new_ptr = malloc(size);

    if (new_ptr == NULL) {
        return NULL;
    }

    memcpy(new_ptr, ptr, block->size);
    free(ptr);

    return new_ptr;
}
