#include <stdio.h>


int main()
{
    int a[10];
    int i,j;
    for(j = 0;j < 10;j++)
    {
        scanf("%d",&a[j]);
    }
    int sum;
    int max = a[0];

    for(j = 0;j < 10;j++)//第一个加的数是数组的第几个元素
    {
        sum = 0;
        for(i = j;i < 10;i++)
        {
            sum += a[i];
            if(sum > max)
            {
                max = sum;
            }
        }
    }

    printf("%d\n",max);
    return 0;
}