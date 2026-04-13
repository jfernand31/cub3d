# strerror

## Prototype

```c
#include <string.h>

char *strerror(int errnum);
```

## Description

Returns a pointer to a string describing the error code passed in `errnum`.

These error codes are usually taken from the global variable `errno`.

## Parameters

- `errnum`: Error number (typically `errno`)
    

## Return Value

- Pointer to a **static string** describing the error
    

## Example

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("missing.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error: %s\n", strerror(errno));
        return (1);
    }
    close(fd);
    return (0);
}
```

## Example Output

```id="t2v9ln"
Error: No such file or directory
```

## Notes

- Uses global `errno` values
    
- Must include `<errno.h>` to access `errno`
    
- The returned string is:
    
    - **static**
        
    - should NOT be freed
        
    - may be overwritten by subsequent calls
        
- Equivalent to `perror`, but:
    
    - `strerror` returns a string
        
    - `perror` prints directly to stderr
        

```c
perror("open");              // prints immediately
printf("%s\n", strerror(errno)); // you control formatting
```

- Thread-safe version exists on some systems:
    
    - `strerror_r` (preferred in multi-threaded code)