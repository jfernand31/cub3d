# printf

## Prototype

```c
#include <stdio.h>

int printf(const char *format, ...);
```

## Description

Prints formatted output to **stdout** (file descriptor `1`).

It interprets the `format` string and replaces format specifiers (`%d`, `%s`, etc.) with the provided arguments.

## Parameters

- `format`: String containing text and format specifiers
    
- `...`: Additional arguments corresponding to the specifiers
    

## Return Value

- Returns the number of characters printed
    
- Returns a negative value on error
    

## Common Format Specifiers

- `%d` / `%i` → int
    
- `%u` → unsigned int
    
- `%c` → char
    
- `%s` → string
    
- `%p` → pointer
    
- `%x` / `%X` → hexadecimal
    
- `%f` → float/double
    
- `%%` → literal `%`
    

## Example

```c
#include <stdio.h>

int main(void)
{
    int age = 25;
    char *name = "Joao";

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Pointer: %p\n", (void *)&age);

    return (0);
}
```

## Notes

- Arguments must match specifiers:
    

```c
printf("%d", "hello"); // ❌ undefined behavior
```

- Strings must be null-terminated:
    

```c
char str[] = {'H', 'i'};
printf("%s", str); // ❌ undefined behavior
```

- Does **not automatically flush output** (important for buffering)
    
- Writing to stdout:
    
    - `printf` → formatted
        
    - `write` → raw
        
- In 42 projects, you may need to implement your own `printf` (`ft_printf`)