# gettimeofday

## Prototype

```c
#include <sys/time.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);
```

## Description

Gets the current time with microsecond precision.

The time is returned as the number of seconds and microseconds since the Unix Epoch  
(January 1, 1970).

## Parameters

- `tv`: Pointer to a `struct timeval` where the time will be stored
    
- `tz`: Timezone information (**deprecated, should be NULL**)
    

### struct timeval

```c
struct timeval
{
    time_t      tv_sec;   // seconds
    suseconds_t tv_usec;  // microseconds (0–999999)
};
```

## Return Value

- `0` on success
    
- `-1` on error
    

## Example

```c
#include <sys/time.h>
#include <stdio.h>

int main(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (1);

    printf("Seconds: %ld\n", tv.tv_sec);
    printf("Microseconds: %ld\n", tv.tv_usec);

    return (0);
}
```

## Measuring Execution Time

```c
#include <sys/time.h>
#include <stdio.h>

long get_time_in_us(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000L + tv.tv_usec);
}

int main(void)
{
    long start = get_time_in_us();

    // code to measure
    for (int i = 0; i < 1000000; i++);

    long end = get_time_in_us();

    printf("Elapsed: %ld us\n", end - start);
    return (0);
}
```

## Notes

- Microsecond precision ≠ guaranteed accuracy (depends on system)
    
- `tz` should always be `NULL`
    
- Commonly used in 42 projects (e.g., Philosophers) for timing
    
- For more modern timing, consider `clock_gettime()` (more precise)