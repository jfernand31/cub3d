# signbit

#math/misc
## Prototype

```c
#include <math.h>

int signbit(double x);
```

## Description

Checks whether the **sign bit** of a floating-point number is set.

This tells you if the number is **negative**, including negative zero (`-0.0`).

## Parameters

- `x`: A floating-point value (double)
    

## Return Value

- Returns a non-zero value if the sign bit of `x` is set
    
- Returns `0` if the sign bit is not set
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 3.0;
    double b = -3.0;
    double c = -0.0;
    double d = 0.0;

    printf("signbit(3.0)  = %d\n", signbit(a));
    printf("signbit(-3.0) = %d\n", signbit(b));
    printf("signbit(-0.0) = %d\n", signbit(c));
    printf("signbit(0.0)  = %d\n", signbit(d));

    return (0);
}
```

## Notes

- Detects **sign bit only**, not magnitude:
    

```c
signbit(-0.0) = 1
signbit(0.0)  = 0
```

- Useful distinction:
    
    - `x < 0` → checks mathematical negativity
        
    - `signbit(x)` → checks IEEE representation
        
- Special case:
    

```c
-0.0 is considered negative in signbit
```

- Related functions:
    
    - `copysign(x, y)` → applies sign of `y` to `x`
        
    - `fabs(x)` → removes sign
        
- Common use cases:
    
    - floating-point bit-level behavior
        
    - numerical analysis
        
    - debugging IEEE 754 edge cases