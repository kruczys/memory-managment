#include <unistd.h>

typedef struct header {
    size_t size;
    struct header *next;
    int free;
} header;

#define HEADER_SIZE sizeof(header)

void *malloc(size_t size);
