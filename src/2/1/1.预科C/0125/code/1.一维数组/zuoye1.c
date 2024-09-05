#include <stdio.h>


int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    //对第一项第二项进行1赋值
    a[0] = 1;
    a[1] = 1;
    int i;
    //求数列的每一项
    for(i = 2;i < n;i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    int sum = 0;
    //求和
    for(i = 0;i < 20;i++)
    {
        sum += a[i];
    }
    printf("%d\n",sum);
    return 0;
}