#include <stdio.h>


int main()
{
    int a[5];
    int i;
    //输入
    for(i = 0;i < 5;i++)
    {
        scanf("%d",&a[i]);
    }

    //输出
    for(i = 0;i < 5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}