# ceil

#math/rounding
## Prototype

```c
#include <math.h>

double ceil(double x);
```

## Description

Rounds `x` **upward** to the smallest integer value greater than or equal to `x`.

## Parameters

- `x`: A floating-point number (double)
    

## Return Value

- Returns the smallest integer value ≥ `x`, as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.2;
    double y = -3.2;

    printf("ceil(3.2) = %f\n", ceil(x));
    printf("ceil(-3.2) = %f\n", ceil(y));

    return (0);
}
```

## Notes

- Always rounds **towards +∞**
    

```c
ceil(3.2)  = 4
ceil(3.0)  = 3
ceil(-3.2) = -3
```

- Important behavior with negatives:
    
    - “up” means toward **positive infinity**, not larger magnitude
        
- Related functions:
    
    - `floor(x)` → rounds down
        
    - `round(x)` → nearest integer
        
    - `trunc(x)` → removes decimal part
        
- Common use cases:
    
    - pagination (rounding pages up)
        
    - memory allocation sizing
        
    - grid/tiles calculations in graphics