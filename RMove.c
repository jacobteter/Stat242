#include "Move.h"

/* For a .Call (NOT .C) routine, this is the wrapper that has pointers, so that the traffic1 function is extensible? */
void
traffic1(int *n, int *ans)
{
    *ans = traffic1(*n);
    /* No return as we are returning nothing - void.
       Not like R which would return the last value */
}



