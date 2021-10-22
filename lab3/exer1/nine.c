#include <stdio.h>

void main()
{
    int a[2]={11,12};
    // gdybym chciał dwie tablice, tu zadeklarowałbym int b[2]={0,0};
    printf("Przed wykonaniem instrukcji a[0]=%d, a[1]=%d\n",a[0],a[1]);
    asm volatile(

        "lea %0,%%edx\n\t"
        // tutaj dodałbym leal %1,%%ebx
        "pushl (%%edx)\n\t"
        "pushl 4(%%edx)\n\t"
        //i wtedy dwie następne linijki zamieniłbym %%edx na %%ebx
        "popl (%%edx)\n\t"
        "popl 4(%%edx)\n\t"
        : "=g" (a) // tu dodałbym "=g" (b)
        ::"dx" // a tu dodałby, "bx"

    );
    printf("Po wykonaniu instrukcji a[0]=%d, a[1]=%d\n",a[0],a[1]);
}