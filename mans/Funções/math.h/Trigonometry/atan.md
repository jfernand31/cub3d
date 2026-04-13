# atan

#math/trig
## Prototype

```c
#include <math.h>

double atan(double x);
```

## Description

Computes the **arc tangent** (inverse tangent) of `x`.

It returns the angle whose tangent is `x`.

## Parameters

- `x`: A real number (slope)
    

## Return Value

- Returns the angle in **radians** such that:
    

```c
tan(result) = x
```

- Result is in the range:
    
    - `(-π/2, π/2)`
        

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double value = 1.0;
    double angle = atan(value);

    printf("atan(1.0) = %f radians\n", angle);
    return (0);
}
```

## Notes

- No restricted input range (unlike `asin` and `acos`)
    

```c
atan(1000); // valid
atan(-5.2); // valid
```

- Output is in **radians**, convert if needed:
    

```c
degrees = radians * (180.0 / M_PI);
```

- Relationship:
    

```c
atan(x) gives the angle of a line with slope x
```

- Common use cases:
    
    - converting slope to angle
        
    - geometry and robotics
        
    - vector direction calculations