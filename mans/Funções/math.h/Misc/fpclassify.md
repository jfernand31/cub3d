# fpclassify

#math/misc
## Prototype

```c
#include <math.h>

int fpclassify(double x);
```

## Description

Classifies a floating-point value into one of the IEEE-754 categories:

- NaN
    
- Infinity
    
- Normal number
    
- Subnormal number
    
- Zero
    

## Parameters

- `x`: A floating-point value (double)
    

## Return Value

Returns one of the following macros:

- `FP_NAN` → Not a Number
    
- `FP_INFINITE` → Positive or negative infinity
    
- `FP_NORMAL` → Normalized finite number
    
- `FP_SUBNORMAL` → Denormalized number
    
- `FP_ZERO` → +0 or -0
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 0.0 / 0.0;
    double b = 1.0 / 0.0;
    double c = 42.0;
    double d = 0.0;

    printf("a = %d\n", fpclassify(a));
    printf("b = %d\n", fpclassify(b));
    printf("c = %d\n", fpclassify(c));
    printf("d = %d\n", fpclassify(d));

    return (0);
}
```

## Notes

- This is a **low-level classification tool** for IEEE floating-point values.
    
- Equivalent checks:
    

```c
isnan(x)      → FP_NAN
isinf(x)      → FP_INFINITE
x == 0        → FP_ZERO
```

- Subnormal numbers:
    
    - Very small numbers closer to 0 than the normal floating-point range
        
    - Still valid, but less precise
        
- Related functions:
    
    - `isnan(x)` → checks NaN only
        
    - `isinf(x)` → checks infinity only
        
    - `isfinite(x)` → checks normal/subnormal/zero
        
- Common use cases:
    
    - numerical debugging
        
    - scientific computing
        
    - floating-point validation systems