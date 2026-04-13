# asinh

#math/hyperbolic
## Prototype

```c
#include <math.h>

double asinh(double x);
```

## Description

Computes the **inverse hyperbolic sine** of `x`.

It returns the value whose hyperbolic sine is `x`.

Mathematically:  
[  
\operatorname{asinh}(x) = \ln\left(x + \sqrt{x^2 + 1}\right)  
]

## Parameters

- `x`: A real number (double)
    

## Return Value

- Returns the value such that:
    

```c
sinh(result) = x
```

- Result can be positive or negative
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0;
    double result = asinh(x);

    printf("asinh(1.0) = %f\n", result);
    return (0);
}
```

## Notes

- Defined for all real numbers:
    
    - `(-∞, +∞)`
        
- Odd function:
    

```c
asinh(-x) = -asinh(x)
```

- Relationship:
    

```c
asinh(x) is the inverse of sinh(x)
```

- Common use cases:
    
    - physics (wave equations, relativity)
        
    - signal processing
        
    - mathematical transformations