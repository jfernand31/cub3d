# floor

#math/rounding
## Prototype

```c
#include <math.h>

double floor(double x);
```

## Description

Rounds `x` **downward** to the largest integer value less than or equal to `x`.

## Parameters

- `x`: A floating-point number (double)
    

## Return Value

- Returns the largest integer value ≤ `x`, as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.7;
    double y = -3.7;

    printf("floor(3.7) = %f\n", floor(x));
    printf("floor(-3.7) = %f\n", floor(y));

    return (0);
}
```

## Notes

- Always rounds **towards -∞**
    

```c
floor(3.7)  = 3
floor(3.0)  = 3
floor(-3.7) = -4
```

- Important behavior with negatives:
    
    - “down” means toward **negative infinity**, not just removing decimals
        
- Related functions:
    
    - `ceil(x)` → rounds up
        
    - `round(x)` → nearest integer
        
    - `trunc(x)` → removes decimal part
        
- Common use cases:
    
    - indexing arrays
        
    - grid/coordinate systems
        
    - discretizing continuous values