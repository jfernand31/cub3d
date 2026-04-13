# isnan

#math/misc
## Prototype

```c
#include <math.h>

int isnan(double x);
```

## Description

Checks whether a floating-point number is **Not-a-Number (NaN)**.

NaN is produced when a computation is undefined or invalid.

## Parameters

- `x`: A floating-point value (double)
    

## Return Value

- Returns a non-zero value if `x` is NaN
    
- Returns `0` otherwise
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 0.0 / 0.0;
    double b = 1.0 / 0.0;
    double c = 42.0;

    printf("isnan(nan) = %d\n", isnan(a));
    printf("isnan(inf) = %d\n", isnan(b));
    printf("isnan(42)  = %d\n", isnan(c));

    return (0);
}
```

## Notes

- NaN is produced by invalid operations:
    

```c
0.0 / 0.0
sqrt(-1.0)
```

- Key property:
    

```c
NaN != NaN   // always true
```

- Related functions:
    
    - `isinf(x)` → checks infinity
        
    - `isfinite(x)` → checks if not Inf or NaN
        
- Common use cases:
    
    - error detection in calculations
        
    - validating sensor or simulation data
        
    - debugging numerical instability