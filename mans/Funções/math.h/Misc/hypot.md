# hypot

#math/misc
## Prototype

```c
#include <math.h>

double hypot(double x, double y);
```

## Description

Computes the **Euclidean distance** from the origin to the point `(x, y)`.

Mathematically:  
[  
\text{hypot}(x, y) = \sqrt{x^2 + y^2}  
]

## Parameters

- `x`: horizontal component
    
- `y`: vertical component
    

## Return Value

- Returns ( \sqrt{x^2 + y^2} ) as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.0;
    double y = 4.0;

    double result = hypot(x, y);

    printf("hypot(3, 4) = %f\n", result);
    return (0);
}
```

## Notes

- Safe version of manual computation:
    

```c
sqrt(x*x + y*y); // can overflow/underflow
hypot(x, y);     // safer and more accurate
```

- Works for all real values:
    

```c
hypot(-3, 4); // same as hypot(3, 4)
```

- Special cases:
    

```c
hypot(0, 0) = 0
```

- Common use cases:
    
    - distance calculations in 2D
        
    - physics (vector magnitude)
        
    - graphics and game development