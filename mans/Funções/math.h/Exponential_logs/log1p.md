# log1p

#math/exponential
## Prototype

```c
#include <math.h>

double log1p(double x);
```

## Description

Computes the natural logarithm of **(1 + x)** in a way that is more accurate for small values of `x`.

Mathematically:  
[  
\log1p(x) = \ln(1 + x)  
]

## Parameters

- `x`: A real number where `x > -1`
    

## Return Value

- Returns ( \ln(1 + x) )
    
- If `x ≤ -1`, the result is undefined (domain error)
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 0.001;
    double result = log1p(x);

    printf("log1p(0.001) = %f\n", result);
    return (0);
}
```

## Notes

- Equivalent to:
    

```c
log1p(x) = log(1 + x)
```

- Why it exists:
    
    - `log(1 + x)` loses precision when `x` is very small
        
    - `log1p(x)` is numerically stable
        

Example:

```c
log(1 + 1e-10)   // may lose precision
log1p(1e-10)     // accurate result
```

- Special values:
    

```c
log1p(0) = 0
```

- Common use cases:
    
    - financial calculations (small interest rates)
        
    - probability/statistics
        
    - numerical analysis