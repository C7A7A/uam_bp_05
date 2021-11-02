#include <stdio.h>
#include <sys/time.h>

void main()
{
    int a[2]={11,12};
    struct timeval t1,t2;
    int i;
    #ifndef ASMx86
    int tmp;
    #endif
    printf("Przed wykonaniem instrukcji a[0]=%d, a[1]=%d\n",a[0],a[1]);
    gettimeofday(&t1,NULL);
    for (i=0;i<1000;i++)
    #ifdef ASMx86
    asm volatile(

        "lea %0,%%edx\n\t"
        "pushl (%%edx)\n\t"
        "pushl 4(%%edx)\n\t"
        "popl (%%edx)\n\t"
        "popl 4(%%edx)\n\t"
        : "=g" (a)
        ::"ax" , "cx" , "dx"

    );
    #else
    tmp=a[0];
    a[0]=a[1];
    a[1]=tmp;
    #endif
    
    gettimeofday(&t2,NULL);
    printf("czas sec: %d, microsec : %d\n",t2.tv_sec-t1.tv_sec,t2.tv_usec-t1.tv_usec);
    printf("Po wykonaniu instrukcji a[0]=%d, a[1]=%d\n",a[0],a[1]);
}