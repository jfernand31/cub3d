# isfinite

#math/misc
## Prototype

```c
#include <math.h>

int isfinite(double x);
```

## Description

Checks whether a floating-point number is **finite**, meaning it is neither infinity nor NaN.

A value is finite if it is:

- a normal number
    
- zero
    
- subnormal number
    

## Parameters

- `x`: A floating-point value (double)
    

## Return Value

- Returns a non-zero value (true) if `x` is finite
    
- Returns `0` if `x` is:
    
    - `+∞`
        
    - `-∞`
        
    - `NaN`
        

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 1.0 / 0.0;
    double b = 0.0 / 0.0;
    double c = 42.0;

    printf("isfinite(inf) = %d\n", isfinite(a));
    printf("isfinite(nan) = %d\n", isfinite(b));
    printf("isfinite(42)  = %d\n", isfinite(c));

    return (0);
}
```

## Notes

- Finite values include:
    
    - normal floats
        
    - subnormal floats
        
    - zero
        
- Not finite:
    

```c
INFINITY
NAN
```

- Related functions:
    
    - `isinf(x)` → checks infinity
        
    - `isnan(x)` → checks NaN
        
    - `finite()` → older alternative (POSIX)
        
- Common use cases:
    
    - validating computations
        
    - preventing propagation of NaN/Inf
        
    - numerical stability checks