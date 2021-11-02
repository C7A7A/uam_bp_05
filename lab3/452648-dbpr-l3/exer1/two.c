#include <stdio.h>

void main()
{
    int a=0;
    printf("Wartość a: %d przed wykonaniem \n",a);
    asm (

        " movw $1,%0"
        :
        : "r" (a)

    );
    printf("I wartość tej samej zmiennej po wykonaniu %d\n",a);
}