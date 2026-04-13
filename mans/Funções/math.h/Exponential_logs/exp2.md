# exp2

#math/exponential
## Prototype

```c
#include <math.h>

double exp2(double x);
```

## Description

Computes the exponential function with base 2, i.e. ( 2^x ).

## Parameters

- `x`: Exponent value (double)
    

## Return Value

- Returns ( 2^x ) as a `double`
    
- On overflow, returns `+HUGE_VAL`
    
- On underflow, returns `0`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.0;
    double result = exp2(x);

    printf("exp2(3.0) = %f\n", result);
    return (0);
}
```

## Notes

- Equivalent to:
    

```c
exp2(x) = 2^x
```

- Relationship to `exp`:
    

```c
exp2(x) = exp(x * log(2))
```

- Special cases:
    

```c
exp2(0) = 1
exp2(1) = 2
exp2(10) = 1024
```

- Common use cases:
    
    - computer science (binary systems)
        
    - memory / data scaling
        
    - graphics and performance calculations
        
    - fast power-of-two computations