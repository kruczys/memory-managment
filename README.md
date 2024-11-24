# Memory Manager

A simple implementation of memory allocation functions in C. This project includes custom implementations of malloc, free, calloc, and realloc functions.

## Features

- `malloc`: Basic memory allocation
- `free`: Memory deallocation
- `calloc`: Allocation with zero initialization
- `realloc`: Memory block resizing

## Building and running

The project uses Make for compilation. To build:

```bash
make            # Compile the project
make clean # Remove build files
./bin/main # Run example program which can be seen below
```

## Project Structure

```
project/
├── Makefile
└── src/
    ├── main.c         # Main program and tests
    ├── malloc.c       # Malloc implementation
    ├── free.c         # Free implementation
    ├── realloc.c      # Realloc implementation
    ├── calloc.c       # Calloc implementation
    └── malloc.h       # Header file with declarations
```

## Usage Example

Here's a simple "Hello World" program using our custom memory allocator:

```c
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
```

## Implementation Details

The allocator uses a linked list of memory blocks, with each block containing:
- Size of the block
- Whether the block is free
- Pointer to the next block

Key functionalities:
1. `malloc`: Searches for a free block or requests new memory using sbrk
2. `free`: Marks blocks as available for reuse
3. `calloc`: Like malloc but initializes memory to zero values
4. `realloc`: Resizes memory blocks, combining adjacent free blocks when possible

## Notes

- Educational implementation of memory allocation
- Uses sbrk() for requesting memory from the system
- Implements basic block splitting and merging

## Limitations

- No memory alignment implementation
- Basic memory fragmentation handling
- No thread safety
- Limited error checking

