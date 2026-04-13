# acos

#math/trig
## Prototype

```c
#include <math.h>

double acos(double x);
```

## Description

Computes the **arc cosine** (inverse cosine) of `x`.

It returns the angle whose cosine is `x`.

## Parameters

- `x`: Value in the range `[-1, 1]`
    

## Return Value

- Returns the angle in **radians** such that:
    

```c
cos(result) = x
```

- Result is in the range:
    
    - `[0, π]`
        

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double value = 0.5;
    double angle = acos(value);

    printf("acos(0.5) = %f radians\n", angle);
    return (0);
}
```

## Notes

- Input must be in range:
    
    - `-1 ≤ x ≤ 1`
        

```c
acos(2.0); // ❌ undefined (out of domain)
```

- Output is in **radians**, convert if needed:
    

```c
degrees = radians * (180.0 / M_PI);
```

- Relationship:
    

```c
acos(x) is the inverse of cos(x)
```

- Common use cases:
    
    - finding angles from dot product (geometry / 3D math)
        
    - physics calculations
        
    - vector operations