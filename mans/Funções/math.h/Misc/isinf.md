# isinf

#math/misc
## Prototype

```c
#include <math.h>

int isinf(double x);
```

## Description

Checks whether a floating-point number is **infinite**.

It detects both positive and negative infinity.

## Parameters

- `x`: A floating-point value (double)
    

## Return Value

- Returns a non-zero value if `x` is:
    
    - `+∞` → positive infinity
        
    - `-∞` → negative infinity
        
- Returns `0` otherwise
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 1.0 / 0.0;
    double b = -1.0 / 0.0;
    double c = 42.0;

    printf("isinf(+inf) = %d\n", isinf(a));
    printf("isinf(-inf) = %d\n", isinf(b));
    printf("isinf(42)   = %d\n", isinf(c));

    return (0);
}
```

## Notes

- Detects both:
    

```c
INFINITY
-INFINITY
```

- Does NOT detect NaN:
    

```c
isinf(NAN) = 0
```

- Related functions:
    
    - `isfinite(x)` → checks if value is not Inf or NaN
        
    - `isnan(x)` → checks NaN values
        
- Common use cases:
    
    - preventing overflow propagation
        
    - validating numeric results
        
    - scientific computing safety checks