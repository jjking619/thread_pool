#include <stdio.h>
void xxxx(int *x,int *y);


int main()
{
    int a = 5;
    int b = 6;
    xxxx(&a,&b);

    printf("a = %d\n",a);
    printf("b = %d\n",b);
}


void xxxx(int *x,int *y)
{
    int t;
    t = *y;
    *y = *x;
    *x = t;
}