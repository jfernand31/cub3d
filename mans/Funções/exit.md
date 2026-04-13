# exit

## Prototype

```c
#include <stdlib.h>

void exit(int status);
```

## Description

Terminates the current program immediately.

Before exiting, it performs cleanup:

- Flushes all open output streams (`printf`, etc.)
    
- Closes all open files
    
- Calls functions registered with `atexit()`
    

## Parameters

- `status`: Exit status code returned to the operating system
    

## Return Value

- This function **does not return**
    

## Exit Status

- `0` → Success
    
- Non-zero (e.g., `1`) → Error
    

Common macros:

- `EXIT_SUCCESS` (usually 0)
    
- `EXIT_FAILURE` (usually 1)
    

## Example

```c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    printf("Exiting program...\n");
    exit(EXIT_SUCCESS);
}
```

## Notes

- Code after `exit()` will **never run**
    

```c
printf("Hello\n");
exit(0);
printf("This will NOT print\n");
```

- `exit()` vs `return` in `main`:
    
    - `return (0);` in `main` is equivalent to `exit(0);`
        
    - But `exit()` can be called from **any function**
        
- In low-level projects (like 42), sometimes `exit()` is **forbidden** — you may need to:
    
    - Free memory manually
        
    - Return control properly instead of exiting
        
- If you want to exit **without cleanup**, use:
    
    ```c
    _exit(status);
    ```
    
    (used in forked processes)