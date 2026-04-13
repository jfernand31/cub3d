# fabs

#math/misc
## Prototype

```c
#include <math.h>

double fabs(double x);
```

## Description

Computes the **absolute value** of a floating-point number.

It removes the sign of `x`, always returning a non-negative value.

## Parameters

- `x`: A floating-point number (double)
    

## Return Value

- Returns the absolute value of `x` as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = -3.14;
    double y = 3.14;

    printf("fabs(-3.14) = %f\n", fabs(x));
    printf("fabs(3.14) = %f\n", fabs(y));

    return (0);
}
```

## Notes

- Always returns a **non-negative value**
    

```c
fabs(-5.0) = 5.0
fabs(5.0)  = 5.0
```

- Related functions:
    
    - `abs()` → integer absolute value
        
    - `fabsf()` → float version
        
    - `fabsl()` → long double version
        
- Difference from `abs()`:
    
    - `abs()` works on integers
        
    - `fabs()` works on floating-point numbers
        
- Common use cases:
    
    - distance calculations
        
    - error margins in comparisons
        
    - physics and simulations