# fmin

#math/misc

## Prototype

```c
#include <math.h>

double fmin(double x, double y);
```

## Description

Returns the **minimum value** between two floating-point numbers.

It compares `x` and `y` and returns the smaller one.

## Parameters

- `x`: First value
    
- `y`: Second value
    

## Return Value

- Returns the smaller of `x` and `y`
    
- If one value is NaN, the other value is returned
    
- If both are NaN, result is NaN
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 10.5;
    double b = 20.3;

    double result = fmin(a, b);

    printf("fmin(10.5, 20.3) = %f\n", result);
    return (0);
}
```

## Notes

- Simple comparison:
    

```c
fmin(x, y) = (x < y) ? x : y
```

- NaN handling:
    

```c
fmin(NAN, 5.0) = 5.0
```

- Related functions:
    
    - `fmax(x, y)` → maximum value
        
    - `fdim(x, y)` → positive difference
        
    - `fminf`, `fminl` → float and long double versions
        
- Common use cases:
    
    - clamping values to lower bounds
        
    - constraints in simulations
        
    - boundary checking