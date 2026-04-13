# nexttoward

#math/misc
## Prototype

```c
#include <math.h>

double nexttoward(double x, long double y);
```

## Description

Computes the **next representable floating-point value** after `x` in the direction of `y`, using **higher precision for the target direction** (`long double`).

It is similar to `nextafter`, but the destination value has greater precision.

## Parameters

- `x`: Starting floating-point value (`double`)
    
- `y`: Target value (`long double`) indicating direction
    

## Return Value

- Returns the next representable `double` after `x` toward `y`
    
- If `x == y`, returns `y` (converted to `double`)
    
- If overflow occurs, returns `HUGE_VAL` or `-HUGE_VAL`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0;
    long double y = 2.0L;

    double result = nexttoward(x, y);

    printf("nexttoward(1.0, 2.0L) = %.20f\n", result);
    return (0);
}
```

## Notes

- Similar to `nextafter`, but:
    
    - `nextafter(x, y)` → both `double`
        
    - `nexttoward(x, y)` → `y` is `long double` (more precise direction)
        

```c
nexttoward(1.0, 2.0L)
```

- Moves by **one representable step in IEEE 754 space**
    
- Direction behavior:
    

```c
nexttoward(1.0, 0.0L) // moves downward
nexttoward(1.0, 10.0L) // moves upward
```

- Common use cases:
    
    - high-precision numerical analysis
        
    - floating-point edge-case testing
        
    - scientific computing
        
    - debugging precision errors