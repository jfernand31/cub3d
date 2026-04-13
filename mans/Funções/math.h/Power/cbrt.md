# cbrt

#math/power
## Prototype

```c
#include <math.h>

double cbrt(double x);
```

## Description

Computes the **cube root** of `x`.

Mathematically:  
[  
\sqrt[3]{x}  
]

## Parameters

- `x`: A real number (can be positive, negative, or zero)
    

## Return Value

- Returns the cube root of `x` as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 27.0;
    double result = cbrt(x);

    printf("cbrt(27) = %f\n", result);
    return (0);
}
```

## Notes

- Works with negative numbers:
    

```c
cbrt(-8); // = -2
```

- Special cases:
    

```c
cbrt(0) = 0
cbrt(1) = 1
```

- Relationship:
    

```c
cbrt(x) = pow(x, 1.0/3.0)
```

- Common use cases:
    
    - 3D geometry
        
    - physics (volume ↔ length conversions)
        
    - mathematical modeling