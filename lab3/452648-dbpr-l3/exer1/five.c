#include <stdio.h>

void main()
{
    int a=0;
    int b=0;
    printf("Wartość a: %d b: %d przed wykonaniem \n",a,b);
    asm (

        " xor %0,%0\n"
        "movw $1,%0\n"
        " movw %0,%1\n"
        : "=r" (b), "=r" (a)
        :

    );
    printf("I wartość tych samych zmiennych po wykonaniu a: %d b: %d\n",a,b);
}