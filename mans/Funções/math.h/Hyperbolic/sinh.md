# sinh

#math/hyperbolic
## Prototype

```c
#include <math.h>

double sinh(double x);
```

## Description

Computes the **hyperbolic sine** of `x`.

It is the hyperbolic analogue of the sine function.

Mathematically:  
[  
\sinh(x) = \frac{e^x - e^{-x}}{2}  
]

## Parameters

- `x`: A real number (double)
    

## Return Value

- Returns the hyperbolic sine of `x`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0;
    double result = sinh(x);

    printf("sinh(1.0) = %f\n", result);
    return (0);
}
```

## Notes

- Can return positive or negative values depending on input
    

```c
sinh(-x) = -sinh(x)
```

- Grows rapidly for large `|x|`
    
- Relationship to exponential function:
    

```c
sinh(x) = (exp(x) - exp(-x)) / 2
```

- Common use cases:
    
    - physics (wave equations, relativity)
        
    - hyperbolic geometry
        
    - differential equations