#include <unistd.h>

typedef struct header {
    size_t size;
    struct header *next;
    int free;
} header;

#define HEADER_SIZE sizeof(header)

header *find_free_block(header **last, size_t size);
header *request_space(header *last, size_t size);
void *malloc(size_t size);
