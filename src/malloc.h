#include <unistd.h>
#include "memhead.h"

header *find_free_block(header **last, size_t size);
header *request_space(header *last, size_t size);
void *malloc(size_t size);
