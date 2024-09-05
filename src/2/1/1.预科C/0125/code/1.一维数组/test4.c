#include <stdio.h>
#include <limits.h>

int main()
{

    int a[10];
    int i;
    for(i = 0;i < 10;i++)
    {
        scanf("%d",&a[i]);
    } 
    int max = a[0];
    int second = INT_MIN;   //第二大的数
    for(i = 0;i < 10;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    for(i = 0;i < 10;i++)
    {
        //要小于我们的second并且不是最大值,那么就是第二大的数
        if(a[i] > second && a[i]!=max)
        {
            second = a[i];
        }
    }
    printf("第二大的数是%d\n",second);

    return 0;
}