# acosh

#math/hyperbolic
## Prototype

```c
#include <math.h>

double acosh(double x);
```

## Description

Computes the **inverse hyperbolic cosine** of `x`.

It returns the value whose hyperbolic cosine is `x`.

Mathematically:  
[  
\operatorname{acosh}(x) = \ln\left(x + \sqrt{x^2 - 1}\right)  
]

## Parameters

- `x`: A real number in the range `x ≥ 1`
    

## Return Value

- Returns the value in **radians-like hyperbolic space** such that:
    

```c
cosh(result) = x
```

- Result is always **≥ 0**
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 2.0;
    double result = acosh(x);

    printf("acosh(2.0) = %f\n", result);
    return (0);
}
```

## Notes

- Domain restriction:
    
    - `x ≥ 1`
        

```c
acosh(0.5); // ❌ undefined (out of domain)
```

- Relationship:
    

```c
acosh(x) is the inverse of cosh(x)
```

- Output is always non-negative
    
- Common use cases:
    
    - physics (relativity calculations)
        
    - hyperbolic geometry
        
    - advanced mathematical modeling