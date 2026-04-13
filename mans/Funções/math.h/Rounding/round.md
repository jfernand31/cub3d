# round

#math/rounding
## Prototype

```c
#include <math.h>

double round(double x);
```

## Description

Rounds `x` to the **nearest integer value**.

If `x` is exactly halfway between two integers, it is rounded **away from zero**.

## Parameters

- `x`: A floating-point number (double)
    

## Return Value

- Returns the nearest integer value to `x`, as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.5;
    double y = -3.5;

    printf("round(3.5) = %f\n", round(x));
    printf("round(-3.5) = %f\n", round(y));

    return (0);
}
```

## Notes

- Rounding rules:
    

```c
round(3.4)  = 3
round(3.5)  = 4
round(-3.5) = -4
round(-3.4) = -3
```

- Halfway cases go **away from zero**
    
    - `0.5 → 1`
        
    - `-0.5 → -1`
        
- Related functions:
    
    - `floor(x)` → always down (−∞)
        
    - `ceil(x)` → always up (+∞)
        
    - `trunc(x)` → toward 0
        
- Common use cases:
    
    - user-facing calculations
        
    - physics approximations
        
    - numerical formatting