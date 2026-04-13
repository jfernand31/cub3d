# asin

#math/trig
## Prototype

```c
#include <math.h>

double asin(double x);
```

## Description

Computes the **arc sine** (inverse sine) of `x`.

It returns the angle whose sine is `x`.

## Parameters

- `x`: Value in the range `[-1, 1]`
    

## Return Value

- Returns the angle in **radians** such that:
    

```c
sin(result) = x
```

- Result is in the range:
    
    - `[-π/2, π/2]`
        

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double value = 0.5;
    double angle = asin(value);

    printf("asin(0.5) = %f radians\n", angle);
    return (0);
}
```

## Notes

- Input must be in range:
    
    - `-1 ≤ x ≤ 1`
        

```c
asin(2.0); // ❌ undefined (out of domain)
```

- Output is in **radians**, convert if needed:
    

```c
degrees = radians * (180.0 / M_PI);
```

- Relationship:
    

```c
asin(x) is the inverse of sin(x)
```

- Common use cases:
    
    - angle recovery from ratios
        
    - physics and wave calculations
        
    - geometry and vector math