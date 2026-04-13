# nextafter

#math/misc
## Prototype

```c
#include <math.h>

double nextafter(double x, double y);
```

## Description

Computes the **next representable floating-point value** after `x` in the direction of `y`.

It moves `x` by **one step in IEEE floating-point representation** toward `y`.

## Parameters

- `x`: Starting floating-point value
    
- `y`: Target value (direction of movement)
    

## Return Value

- Returns the next representable double after `x` toward `y`
    
- If `x == y`, returns `y`
    
- If an overflow occurs, returns `HUGE_VAL` or `-HUGE_VAL`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0;
    double y = 2.0;

    double result = nextafter(x, y);

    printf("nextafter(1.0, 2.0) = %.20f\n", result);
    return (0);
}
```

## Notes

- Moves by **1 floating-point step**, not a mathematical increment
    

```c
nextafter(1.0, 2.0) // slightly bigger than 1.0
```

- Works in both directions:
    

```c
nextafter(1.0, 0.0) // slightly smaller than 1.0
```

- Important properties:
    
    - Precision-aware stepping
        
    - Depends on IEEE 754 representation
        
- Related functions:
    
    - `nexttoward()` → same idea but with `long double` precision target
        
- Common use cases:
    
    - numerical stability testing
        
    - floating-point precision debugging
        
    - simulation step control