# llround

#math/rounding
## Prototype

```c
#include <math.h>

long long int llround(double x);
```

## Description

Rounds `x` to the **nearest integer value**, using the same rules as `round`, but returns a `long long int`.

If `x` is exactly halfway between two integers, it is rounded **away from zero**.

## Parameters

- `x`: A floating-point number (double)
    

## Return Value

- Returns the nearest integer as a `long long int`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 4.5;
    double y = -4.5;

    long long int a = llround(x);
    long long int b = llround(y);

    printf("llround(4.5) = %lld\n", a);
    printf("llround(-4.5) = %lld\n", b);

    return (0);
}
```

## Notes

- Same rounding rules as `round()`:
    

```c
llround(4.4)  = 4
llround(4.5)  = 5
llround(-4.5) = -5
```

- Difference from related functions:
    
    - `round()` → returns `double`
        
    - `lround()` → returns `long int`
        
    - `llround()` → returns `long long int`
        
- Why use `llround()`:
    
    - safer for large numbers
        
    - avoids overflow when `long int` is too small
        
- Common use cases:
    
    - large-scale indexing
        
    - simulations
        
    - high-range numerical computations