# read

## Prototype

```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
```

## Description

Reads data from a file descriptor into a buffer.

It tries to read up to `count` bytes and stores them in `buf`.

## Parameters

- `fd`: File descriptor to read from (file, stdin, pipe, etc.)
    
- `buf`: Memory buffer where data will be stored
    
- `count`: Maximum number of bytes to read
    

## Return Value

- `> 0` → Number of bytes actually read
    
- `0` → End of file (EOF)
    
- `-1` → Error occurred
    

## Example

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    char buf[100];
    ssize_t bytes = read(fd, buf, sizeof(buf) - 1);

    if (bytes == -1)
    {
        perror("read");
        close(fd);
        return (1);
    }

    buf[bytes] = '\0';
    printf("Read: %s\n", buf);

    close(fd);
    return (0);
}
```

## Notes

- Does **not guarantee reading all requested bytes**
    

```c
read(fd, buf, 100); // may read 10, 50, or 100 bytes
```

- You often need a loop to read everything
    
- Returns `0` when file is fully read (EOF)
    
- Works with:
    
    - files
        
    - stdin
        
    - pipes
        
    - sockets
        
- Very important in 42 projects (e.g. `get_next_line`)
    
- Always check return value before using buffer
    
- Buffer is NOT null-terminated automatically