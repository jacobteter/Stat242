#include "Move.h"

/* For a .C routine, this is the wrapper that has pointers, so that the traffic1 function is extensible? */
void
traffic1(int *map, int *ans)
{
    *ans = traffic1(*map);
    /* No return as we are returning nothing - void.
       Not like R which would return the last value */
}
