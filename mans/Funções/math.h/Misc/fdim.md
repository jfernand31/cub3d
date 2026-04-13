# fdim

#math/misc
## Prototype

```c
#include <math.h>

double fdim(double x, double y);
```

## Description

Computes the **positive difference** between two floating-point numbers.

It returns:  
[  
\max(x - y, 0)  
]

So it gives the amount by which `x` is greater than `y`, but never negative.

## Parameters

- `x`: First value
    
- `y`: Second value
    

## Return Value

- Returns `x - y` if `x > y`
    
- Returns `0` if `x ≤ y`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 10.0;
    double b = 3.0;
    double c = 20.0;
    double d = 25.0;

    printf("fdim(10, 3)  = %f\n", fdim(a, b));
    printf("fdim(20, 25) = %f\n", fdim(c, d));

    return (0);
}
```

## Notes

- Equivalent logic:
    

```c
fdim(x, y) = (x > y) ? (x - y) : 0
```

- Always non-negative:
    

```c
fdim(3, 10) = 0
```

- Difference from normal subtraction:
    
    - `x - y` can be negative
        
    - `fdim(x, y)` clamps to zero
        
- Related functions:
    
    - `fmax(x, y)` → maximum value
        
    - `fmin(x, y)` → minimum value
        
- Common use cases:
    
    - physics (distance thresholds)
        
    - optimization problems
        
    - bounding/clamping values