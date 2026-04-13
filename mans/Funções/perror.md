# perror

## Prototype

```c
#include <stdio.h>

void perror(const char *s);
```

## Description

Prints a descriptive error message to **stderr** based on the current value of `errno`.

The output format is:

```
s: <error message>
```

## Parameters

- `s`: Custom message (usually the function or context name)
    

## Return Value

- This function **does not return a value**
    

## Example

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("missing.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    close(fd);
    return (0);
}
```

### Output

```
open: No such file or directory
```

## Notes

- Uses the global variable `errno`
    
- Should be called **immediately after an error**
    

```c
if (fd == -1)
    perror("open"); // ✅ correct
```

- `errno` may change if you call other functions before `perror`
    

```c
if (fd == -1)
{
    printf("error\n");
    perror("open"); // ⚠️ errno might be modified
}
```

- Prints to **file descriptor 2 (stderr)**
    
- Equivalent manual version:
    

```c
#include <string.h>
#include <errno.h>
#include <stdio.h>

printf("open: %s\n", strerror(errno));
```

- Very useful for debugging system calls (`open`, `read`, `fork`, etc.)