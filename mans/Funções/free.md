# free

## Prototype

```c
#include <stdlib.h>

void free(void *ptr);
```

## Description

Releases memory previously allocated with `malloc`, `calloc`, or `realloc`.

This memory is returned to the system and can be reused later.

## Parameters

- `ptr`: Pointer to the memory to free
    

## Return Value

- This function **does not return a value**
    

## Example

```c
#include <stdlib.h>

int main(void)
{
    int *arr = malloc(sizeof(int) * 5);
    if (!arr)
        return (1);

    // use memory...

    free(arr);
    return (0);
}
```

## Notes

- **Only free what was allocated**
    

```c
int x = 10;
free(&x); // ❌ WRONG (not malloc'd)
```

- **Free only once**
    

```c
free(ptr);
free(ptr); // ❌ DOUBLE FREE (undefined behavior)
```

- **Safe to free NULL**
    

```c
free(NULL); // ✅ does nothing
```

- **Pointer is NOT set to NULL automatically**
    

```c
free(ptr);
// ptr is now a dangling pointer!
```

Good practice:

```c
free(ptr);
ptr = NULL;
```

- **Common mistake: memory leak**
    

```c
char *s = malloc(10);
s = malloc(20); // ❌ lost reference to first allocation
```

- In complex programs (like 42 projects), always:
    
    - Track your allocations
        
    - Free everything before exit