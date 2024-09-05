#include <stdio.h>


int main()
{
    int a = ;  //0x1000
    int *p;
    char *q;
    p = &a;
    q = (char *)&a;

    printf("%p\n",p);   //0x1000
    printf("%p\n",p+1); //0x1008   /  
    printf("%p\n",q);   //0x1000
    printf("%p\n",q+1); //0x1008
}