# malloc

## Prototype

```c
#include <stdlib.h>

void *malloc(size_t size);
```

## Description

Allocates a block of memory of `size` bytes on the heap and returns a pointer to it.

The memory is **uninitialized** (contains garbage values).

## Parameters

- `size`: Number of bytes to allocate
    

## Return Value

- Returns a pointer to the allocated memory
    
- Returns `NULL` if allocation fails
    

## Example

```c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *arr = malloc(sizeof(int) * 5);
    if (!arr)
        return (1);

    for (int i = 0; i < 5; i++)
        arr[i] = i * 2;

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    free(arr);
    return (0);
}
```

## Notes

- Always check for `NULL`
    

```c
int *ptr = malloc(sizeof(int));
if (!ptr)
    return (1);
```

- Memory is **not initialized**
    

```c
int *x = malloc(sizeof(int));
// *x contains garbage
```

- Use `sizeof` to avoid mistakes
    

```c
int *arr = malloc(sizeof(int) * 10);
```

- Avoid casting in C
    

```c
int *arr = malloc(sizeof(int) * 10); // ✅
int *arr = (int *)malloc(sizeof(int) * 10); // ❌ unnecessary in C
```

- Must be freed
    

```c
free(ptr);
```

- Common mistake: forgetting to allocate enough memory
    

```c
char *s = malloc(10); // only 10 bytes
```

- Common mistake: memory leak
    

```c
char *s = malloc(10);
s = malloc(20); // ❌ lost first allocation
```

- If you want zero-initialized memory, use `calloc`