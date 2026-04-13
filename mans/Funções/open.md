# open

## Prototype

```c
#include <fcntl.h>
#include <sys/stat.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

## Description

Opens a file and returns a file descriptor that can be used for reading, writing, or both.

If the file does not exist, it can be created using specific flags.

## Parameters

- `pathname`: Path to the file.
    
- `flags`: Controls how the file is opened (read, write, create, etc.).
    
- `mode`: Permissions for the file **(only used when creating a file)**.
    

## Common Flags

- `O_RDONLY` → Open for reading only
    
- `O_WRONLY` → Open for writing only
    
- `O_RDWR` → Open for reading and writing
    
- `O_CREAT` → Create file if it doesn’t exist
    
- `O_TRUNC` → Truncate file to 0 length
    
- `O_APPEND` → Write at end of file
    

Flags are combined using `|`:

```c
O_WRONLY | O_CREAT | O_TRUNC
```

## Return Value

- Returns a **file descriptor (int ≥ 0)** on success
    
- Returns **-1** on error
    

## Errors

- `ENOENT`: File does not exist (without `O_CREAT`)
    
- `EACCES`: Permission denied
    
- `EISDIR`: Trying to open a directory as a file
    
- `EMFILE`: Too many open files
    

## Example

```c
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (1);

    write(fd, "Hello\n", 6);
    close(fd);
    return (0);
}
```

## Notes

- File descriptors:
    
    - `0` → stdin
        
    - `1` → stdout
        
    - `2` → stderr
        
- Always `close(fd)` when you're done.
    
- `mode` is written in **octal** (e.g., `0644`)