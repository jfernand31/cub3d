# sin

#math/trig
## Prototype

```c
#include <math.h>

double sin(double x);
```

## Description

Computes the sine of an angle `x`.

The input angle must be given in **radians**, not degrees.

## Parameters

- `x`: Angle in radians
    

## Return Value

- Returns the sine of `x` as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double angle = M_PI / 2; // 90 degrees in radians
    double result = sin(angle);

    printf("sin(90°) = %f\n", result);
    return (0);
}
```

## Notes

- Input must be in **radians**
    

```c
sin(90); // ❌ incorrect (90 radians, not 90 degrees)
```

- Convert degrees to radians:
    

```c
radians = degrees * (M_PI / 180.0);
```

- Output range:
    
    - `[-1, 1]`
        
- Common use cases:
    
    - wave functions
        
    - rotations and geometry
        
    - physics simulations
        
    - circular motion