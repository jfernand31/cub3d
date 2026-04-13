# cos

#math/trig
## Prototype

```c
#include <math.h>

double cos(double x);
```

## Description

Computes the cosine of a given angle `x`.

The input `x` is in **radians**, not degrees.

## Parameters

- `x`: Angle in radians
    

## Return Value

- Returns the cosine of `x` as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double angle = M_PI / 3; // 60 degrees in radians
    double result = cos(angle);

    printf("cos(60°) = %f\n", result);
    return (0);
}
```

## Notes

- Input must be in **radians**
    

```c
cos(180); // ❌ wrong (180 radians, not degrees)
```

- Convert degrees to radians:
    

```c
radians = degrees * (M_PI / 180.0);
```

- Output range:
    
    - `[-1, 1]`
        
- Common use cases:
    
    - geometry (right triangles, circles)
        
    - physics (waves, oscillations)
        
    - rotations and graphics