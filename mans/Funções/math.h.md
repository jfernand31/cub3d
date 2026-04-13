# math.h

## Overview

The `<math.h>` library provides mathematical functions for floating-point calculations (trigonometry, exponentials, rounding, powers, etc.).

Include it with:

```c
#include <math.h>
```

Compile with:

```bash
gcc main.c -lm
```

---

## Constants

- [[M_PI]]
    
- [[M_E]]
    

---

## Trigonometric functions

- [[cos]]
    
- [[sin]]
    
- [[tan]]
    
- [[acos]]
    
- [[asin]]
    
- [[atan]]
    
- [[atan2]]
    

---

## Hyperbolic functions

- [[cosh]]
    
- [[sinh]]
    
- [[tanh]]
    
- [[acosh]]
    
- [[asinh]]
    
- [[atanh]]
    

---

## Exponential & logarithmic

- [[exp]]
    
- [[exp2]]
    
- [[expm1]]
    
- [[log]]
    
- [[log10]]
    
- [[log2]]
    
- [[log1p]]
    

---

## Power & root

- [[pow]]
    
- [[sqrt]]
    
- [[cbrt]]
    
- [[hypot]]
    

---

## Rounding & absolute value

- [[ceil]]
    
- [[floor]]
    
- [[trunc]]
    
- [[round]]
    
- [[lround]]
    
- [[llround]]
    
- [[fabs]]
    

---

## Remainder / modulo

- [[fmod]]
    
- [[remainder]]
    
- [[remquo]]
    

---

## Floating-point manipulation

- [[frexp]]
    
- [[ldexp]]
    
- [[modf]]
    
- [[nextafter]]
    
- [[nexttoward]]
    

---

## Classification

- [[isfinite]]
    
- [[isinf]]
    
- [[isnan]]
    
- [[signbit]]
    
- [[fpclassify]]
    

---

## Other

- [[copysign]]
    
- [[fdim]]
    
- [[fmax]]
    
- [[fmin]]
    
- [[fma]]
    

---

## Notes

- Functions operate mainly on `double`
    
- Use suffixes:
    
    - `f` → float version
        
    - `l` → long double version
        
- Link math library with `-lm`