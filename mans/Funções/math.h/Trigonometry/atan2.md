# atan2

#math/trig
## Prototype

```c
#include <math.h>

double atan2(double y, double x);
```

## Description

Computes the **arc tangent of y/x**, taking into account the signs of both `x` and `y` to determine the correct quadrant of the result.

Unlike `atan(y/x)`, this function correctly handles all quadrants and avoids division by zero.

## Parameters

- `y`: y-coordinate (or vertical component)
    
- `x`: x-coordinate (or horizontal component)
    

## Return Value

- Returns the angle in **radians** between the positive x-axis and the point `(x, y)`
    
- Range:
    
    - `[-π, π]`
        

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double y = 1.0;
    double x = 1.0;

    double angle = atan2(y, x);

    printf("atan2(1, 1) = %f radians\n", angle);
    return (0);
}
```

## Notes

- Preferred over `atan(y / x)` because:
    
    - avoids division by zero
        
    - correctly determines quadrant
        

```c
atan(1/0);     // ❌ undefined
atan2(1, 0);   // ✅ returns π/2
```

- Quadrant behavior:
    
    - `x > 0` → normal atan(y/x)
        
    - `x < 0` → adjusts angle by ±π
        
    - `x = 0` → returns ±π/2 depending on `y`
        
- Common use cases:
    
    - converting Cartesian coordinates → angles
        
    - rotations in graphics
        
    - robotics and physics
        
    - computing direction vectors