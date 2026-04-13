# tan

#math/trig
## Prototype

```c
#include <math.h>

double tan(double x);
```

## Description

Computes the tangent of an angle `x`.

The input must be in **radians**, not degrees.

Mathematically:  
[  
\tan(x) = \frac{\sin(x)}{\cos(x)}  
]

## Parameters

- `x`: Angle in radians
    

## Return Value

- Returns the tangent of `x` as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double angle = M_PI / 4; // 45 degrees in radians
    double result = tan(angle);

    printf("tan(45°) = %f\n", result);
    return (0);
}
```

## Notes

- Input must be in **radians**
    

```c
tan(45); // ❌ wrong (45 radians, not degrees)
```

- Convert degrees to radians:
    

```c
radians = degrees * (M_PI / 180.0);
```

- Output behavior:
    
    - Can grow very large near values where `cos(x) = 0`
        
    - Undefined at:
        
        - ( x = \frac{\pi}{2} + k\pi )
            
- Range:
    
    - All real numbers ((-\infty, +\infty))
        
- Common use cases:
    
    - slopes and angles
        
    - physics (motion, forces)
        
    - geometry calculations