#include <stdio.h>

void main()
{
    int a=0;
    int b=0;
    printf("Wartość a: %d b: %d przed wykonaniem \n",a,b);
    a=b=1;
    printf("I wartość tych samych zmiennych po wykonaniu a: %d b: %d\n",a,b);
}