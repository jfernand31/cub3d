# trunc

#math/rounding
## Prototype

```c
#include <math.h>

double trunc(double x);
```

## Description

Removes the fractional part of `x`, effectively **truncating it toward zero**.

Unlike `floor` or `ceil`, it does not round up or down — it simply cuts off the decimal part.

## Parameters

- `x`: A floating-point number (double)
    

## Return Value

- Returns the integer part of `x` as a `double`, truncated toward zero
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.7;
    double y = -3.7;

    printf("trunc(3.7) = %f\n", trunc(x));
    printf("trunc(-3.7) = %f\n", trunc(y));

    return (0);
}
```

## Notes

- Always rounds **toward 0**
    

```c
trunc(3.7)  = 3
trunc(3.0)  = 3
trunc(-3.7) = -3
```

- Difference from other rounding functions:
    
    - `floor(x)` → towards −∞
        
    - `ceil(x)` → towards +∞
        
    - `trunc(x)` → towards 0
        
- Related functions:
    
    - `round(x)` → nearest integer
        
- Common use cases:
    
    - removing decimal part without rounding bias
        
    - integer conversion in math logic
        
    - graphics and coordinate systems