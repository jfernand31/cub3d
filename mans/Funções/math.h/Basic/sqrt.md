# sqrt

#math/basic
## Prototype

```c
#include <math.h>

double sqrt(double x);
```

## Description

Computes the **square root** of `x`.

Mathematically:  
[  
\sqrt{x}  
]

## Parameters

- `x`: A non-negative real number
    

## Return Value

- Returns the square root of `x`
    
- If `x < 0`, the result is undefined (domain error)
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 16.0;
    double result = sqrt(x);

    printf("sqrt(16) = %f\n", result);
    return (0);
}
```

## Notes

- Domain restriction:
    

```c
sqrt(-1); // ❌ undefined in real numbers
```

- Special cases:
    

```c
sqrt(0) = 0
sqrt(1) = 1
```

- Relationship:
    

```c
sqrt(x) = pow(x, 0.5)
```

- Common use cases:
    
    - geometry (distance formula)
        
    - physics (magnitude calculations)
        
    - statistics (standard deviation)