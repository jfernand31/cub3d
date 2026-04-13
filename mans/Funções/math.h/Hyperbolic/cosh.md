# cosh

#math/hyperbolic
## Prototype

```c
#include <math.h>

double cosh(double x);
```

## Description

Computes the **hyperbolic cosine** of `x`.

It is the hyperbolic analogue of the cosine function.

Mathematically:  
[  
\cosh(x) = \frac{e^x + e^{-x}}{2}  
]

## Parameters

- `x`: A real number (double)
    

## Return Value

- Returns the hyperbolic cosine of `x`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0;
    double result = cosh(x);

    printf("cosh(1.0) = %f\n", result);
    return (0);
}
```

## Notes

- Always returns a value **≥ 1**
    

```c
cosh(0); // = 1
```

- Symmetry:
    

```c
cosh(-x) = cosh(x)
```

- Related to exponential growth:
    
    - grows very fast for large `|x|`
        
- Common use cases:
    
    - physics (relativity, wave equations)
        
    - hyperbolic geometry
        
    - differential equations