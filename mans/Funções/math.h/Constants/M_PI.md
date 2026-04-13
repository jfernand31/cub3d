# M_PI

#math/constants
## Prototype

```c
#define M_PI 3.14159265358979323846
```

## Description

`M_PI` is a mathematical constant defined in `<math.h>` representing the value of π (pi), the ratio of a circle’s circumference to its diameter.

It is used in geometry, trigonometry, and many mathematical computations involving circles and angles.

## Value

- Approximate value: `3.14159265358979323846`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double radius = 5.0;
    double area = M_PI * radius * radius;

    printf("Area: %f\n", area);
    return (0);
}
```

## Notes

- It is a **macro**, not a function.
    
- Not part of the C standard in strict ISO C, but widely supported (POSIX / GNU / most compilers).
    
- If unavailable, you can define it manually:
    

```c
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
```

- Often used with:
    
    - `sin`, `cos`, `tan`
        
    - circle calculations
        
    - angle conversions:
        

```c
radians = degrees * (M_PI / 180.0);
```