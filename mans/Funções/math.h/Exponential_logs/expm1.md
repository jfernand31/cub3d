# expm1

#math/exponential
## Prototype

```c
#include <math.h>

double expm1(double x);
```

## Description

Computes ( e^x - 1 ) in a way that is more accurate for small values of `x`.

It is designed to avoid precision loss when `x` is close to 0.

## Parameters

- `x`: Exponent value (double)
    

## Return Value

- Returns ( e^x - 1 ) as a `double`
    
- On overflow, returns `+HUGE_VAL`
    
- On underflow, returns `-1`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 0.001;
    double result = expm1(x);

    printf("expm1(0.001) = %f\n", result);
    return (0);
}
```

## Notes

- Equivalent to:
    

```c
expm1(x) = exp(x) - 1
```

- Why it exists:
    
    - `exp(x) - 1` loses precision when `x ≈ 0`
        
    - `expm1(x)` is numerically stable
        

Example problem:

```c
exp(1e-8) - 1   // may lose precision
expm1(1e-8)     // accurate result
```

- Special cases:
    

```c
expm1(0) = 0
```

- Common use cases:
    
    - numerical analysis
        
    - financial calculations (small growth rates)
        
    - scientific computing