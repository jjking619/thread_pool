#include <stdio.h>

int main()
{
    int a,b;
    int sum = 0;

    //从键盘输入两个数 scanf
    scanf("%d %d",&a,&b);

    sum = a+b;
    printf("%d + %d = %d\n",a,b,sum);
    return 0;
}