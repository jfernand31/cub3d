# close

## Prototype

```c
#include <unistd.h>

int close(int fd);
```

## Description

Closes an open file descriptor, releasing the associated resource.

After calling `close`, the file descriptor can no longer be used.

## Parameters

- `fd`: File descriptor to close
    

## Return Value

- `0` on success
    
- `-1` on error
    

## Errors

- `EBADF`: Invalid or already closed file descriptor
    
- `EINTR`: Interrupted by a signal before completion
    

## Example

```c
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    // use file...

    if (close(fd) == -1)
        return (1);

    return (0);
}
```

## Notes

- Always close file descriptors to avoid **resource leaks**
    
- After closing, the descriptor becomes invalid:
    

```c
close(fd);
read(fd, buf, 10); // ❌ undefined behavior
```

- File descriptors are reused by the system:
    

```c
int fd1 = open("a.txt", O_RDONLY);
close(fd1);
int fd2 = open("b.txt", O_RDONLY);
// fd2 may have the same value as fd1
```

- Closing standard descriptors:
    
    - `0` → stdin
        
    - `1` → stdout
        
    - `2` → stderr
        

Be careful when closing them in programs like minishell