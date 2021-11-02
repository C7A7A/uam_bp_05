#include <stdio.h>

void main()
{
    int a[2]={11,12};
    int c[2];
    printf("Przed wykonaniem instrukcji a[0]=%d, a[1]=%d",a[0],a[1]);
    asm volatile(

        "leal %0,%%edx\n\t"
        "leal %1,%%ebx\n\t"
        "movl $1,%%eax\n\t"
        "movl $2,%%ecx\n\t"
        "petla1:\n\t"
        "pushl %%eax\n\t"
        "pushl %%ecx\n\t"
        "movl $2,%%ecx\n\t"
        "pushl %%edx\n\t"
        "mull %%ecx\n\t"
        "popl %%edx\n\t"
        "movl (%%edx,%%eax,2),%%ecx\n\t"
        "pushl %%ebx\n\t"
        "movl $2,%%ebx\n\t"
        "subl %%eax,%%ebx\n\t"
        "movl %%ebx,%%eax\n\t"
        "popl %%ebx\n\t"
        "movl %%ecx,(%%ebx,%%eax,2)\n\t"
        "popl %%ecx\n\t"
        "popl %%eax\n\t"
        "decl %%eax\n\t"
        "loop petla1\n\t"
        : "=g" (a) , "=g" (c)
        :: "ax", "cx", "dx" , "memory"


    );
    printf("Po wykonaniu instrukcji c[0]=%d, c[1]=%d\n",c[0],c[1]);
}
