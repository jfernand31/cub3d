# exp

#math/exponential
## Prototype

```c
#include <math.h>

double exp(double x);
```

## Description

Computes the exponential function of `x`, i.e. ( e^x ), where ( e ) is Euler’s number.

## Parameters

- `x`: Exponent value (double)
    

## Return Value

- Returns ( e^x ) as a `double`
    
- On overflow, returns `+HUGE_VAL`
    
- On underflow, returns `0`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 2.0;
    double result = exp(x);

    printf("exp(2.0) = %f\n", result);
    return (0);
}
```

## Notes

- Equivalent to:
    

```c
exp(x) = M_E ^ x
```

- Special cases:
    

```c
exp(0) = 1
exp(1) = M_E
```

- Very fast growth for positive `x`
    
- Approaches `0` for large negative `x`
    
- Common use cases:
    
    - growth/decay models
        
    - probability and statistics
        
    - physics (continuous processes)
        
    - neural networks