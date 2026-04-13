# remainder

#math/rounding
## Prototype

```c
#include <math.h>

double remainder(double x, double y);
```

## Description

Computes the **IEEE floating-point remainder** of `x / y`.

It returns:  
[  
x - (n \times y)  
]  
where `n` is the **nearest integer to x / y** (with ties rounded to even).

This is different from `fmod`, which truncates toward zero.

## Parameters

- `x`: Dividend
    
- `y`: Divisor (must not be 0)
    

## Return Value

- Returns the remainder of `x / y`
    
- If `y == 0`, result is undefined
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 10.5;
    double y = 3.0;

    double result = remainder(x, y);

    printf("remainder(10.5, 3.0) = %f\n", result);
    return (0);
}
```

## Notes

- Key difference from `fmod`:
    

|Function|Rounding method|
|---|---|
|`fmod`|truncates toward 0|
|`remainder`|nearest integer (IEEE)|

```c
remainder(10.5, 3.0)
fmod(10.5, 3.0)
```

- Sign follows the mathematical result (not just `x`)
    
- Can return negative or positive values depending on closest quotient
    
- Special cases:
    

```c
remainder(x, 0) // ❌ invalid
```

- Common use cases:
    
    - numerical analysis
        
    - IEEE-compliant computations
        
    - scientific computing where rounding behavior matters