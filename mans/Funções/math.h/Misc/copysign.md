# copysign

#math/misc
## Prototype

```c
#include <math.h>

double copysign(double x, double y);
```

## Description

Returns a value with the **magnitude of `x`** and the **sign of `y`**.

It does not perform arithmetic — it only manipulates the sign bit.

## Parameters

- `x`: Value providing the magnitude
    
- `y`: Value providing the sign
    

## Return Value

- Returns a `double` with:
    
    - absolute value of `x`
        
    - sign of `y`
        

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 5.0;
    double b = -2.0;

    double r1 = copysign(a, b);
    double r2 = copysign(b, a);

    printf("copysign(5, -2) = %f\n", r1);
    printf("copysign(-2, 5) = %f\n", r2);

    return (0);
}
```

## Notes

- It only changes the **sign**, not the value:
    

```c
copysign(5.0, -1.0) = -5.0
copysign(5.0,  1.0) =  5.0
```

- Useful distinction:
    
    - `fabs(x)` → removes sign
        
    - `copysign(x, y)` → replaces sign
        
- Works with zero and negative zero:
    

```c
copysign(0.0, -1.0) = -0.0
```

- Related functions:
    
    - `fabs(x)` → absolute value
        
    - `signbit(x)` → checks sign
        
    - `nextafter(x, y)` → moves in direction of y
        
- Common use cases:
    
    - physics simulations
        
    - numerical stability control
        
    - restoring sign after computations