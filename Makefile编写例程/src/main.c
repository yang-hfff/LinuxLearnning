#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(void)
{
#ifdef __XXX__
    printf("%d\n",add(1,2));
#else
    printf("%d\n",sub(100,2));
#endif
    return 0;
}