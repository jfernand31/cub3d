# pow

#math/power
## Prototype

```c
#include <math.h>

double pow(double x, double y);
```

## Description

Computes `x` raised to the power of `y`.

Mathematically:  
[  
pow(x, y) = x^y  
]

## Parameters

- `x`: base value
    
- `y`: exponent value
    

## Return Value

- Returns ( x^y ) as a `double`
    
- Special cases depend on domain (see Notes)
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 2.0;
    double y = 3.0;

    double result = pow(x, y);

    printf("pow(2, 3) = %f\n", result);
    return (0);
}
```

## Notes

- Equivalent to:
    

```c
pow(x, y) = x^y
```

- Common cases:
    

```c
pow(x, 1) = x
pow(x, 0) = 1   (for x ≠ 0)
pow(2, 3) = 8
```

- Important rules:
    
    - `pow(0, 0)` is undefined or implementation-defined
        
    - Negative bases with fractional exponents may produce complex results (or domain errors in C)
        

```c
pow(-2, 0.5); // ❌ may be domain error in C
```

- Common use cases:
    
    - geometry (areas, volumes)
        
    - physics formulas
        
    - scaling and transformations