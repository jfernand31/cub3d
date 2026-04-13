# write

## Prototype

```c
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
```

## Description

Writes data from a buffer to a file descriptor.

It attempts to write up to `count` bytes from `buf` into the file, terminal, pipe, or socket.

## Parameters

- `fd`: File descriptor to write to (file, stdout, stderr, etc.)
    
- `buf`: Pointer to the data to write
    
- `count`: Number of bytes to write
    

## Return Value

- `> 0` → Number of bytes actually written
    
- `-1` → Error occurred
    

## Example

```c
#include <unistd.h>
#include <string.h>

int main(void)
{
    char *msg = "Hello, world!\n";

    write(1, msg, strlen(msg)); // 1 = stdout
    return (0);
}
```

## Writing to a file

```c
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (1);

    write(fd, "42 school\n", 10);
    close(fd);
    return (0);
}
```

## Notes

- Does **not guarantee writing all bytes**
    

```c
write(fd, buf, 100); // may write less than 100 bytes
```

- Always check return value in critical code
    
- Common file descriptors:
    
    - `0` → stdin
        
    - `1` → stdout
        
    - `2` → stderr
        
- Unlike `printf`, `write` is:
    
    - unformatted
        
    - low-level
        
    - more predictable
        
- Very important in 42 projects (`libft`, `ft_printf`, `minishell`)
    
- Can be used safely in signal handlers (unlike many stdlib functions)