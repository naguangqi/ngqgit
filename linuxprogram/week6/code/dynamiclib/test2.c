#include "lib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
    
    int a[10];
    urand(a,10);
    printf("max=%d",max(a,10));
    printf("sum=%d\n",sum(a,10));
}
