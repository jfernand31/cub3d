# lround

#math/rounding
## Prototype

```c
#include <math.h>

long int lround(double x);
```

## Description

Rounds `x` to the **nearest integer value**, using the same rules as `round`, but returns a `long int` instead of a `double`.

If `x` is exactly halfway between two integers, it is rounded **away from zero**.

## Parameters

- `x`: A floating-point number (double)
    

## Return Value

- Returns the nearest integer as a `long int`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.6;
    double y = -3.6;

    long int a = lround(x);
    long int b = lround(y);

    printf("lround(3.6) = %ld\n", a);
    printf("lround(-3.6) = %ld\n", b);

    return (0);
}
```

## Notes

- Same rounding rules as `round()`:
    

```c
lround(3.4)  = 3
lround(3.5)  = 4
lround(-3.5) = -4
```

- Difference from `round()`:
    
    - `round()` → returns `double`
        
    - `lround()` → returns `long int`
        
- Related functions:
    
    - `round()` → returns `double`
        
    - `llround()` → returns `long long int`
        
- Common use cases:
    
    - converting floating-point math to integer indices
        
    - array indexing
        
    - discrete systems (graphics, physics)