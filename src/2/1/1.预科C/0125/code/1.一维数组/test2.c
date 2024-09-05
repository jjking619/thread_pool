#include <stdio.h>


int main()
{
    int a[10];
    int i;
    for(i = 0;i < 10;i++)
    {
        scanf("%d ",&a[i]);
    }      
    int max = a[0];
    int min = a[0];
    int sum = 0;

    for(i = 0;i < 10;i++)
    {
        //求和
        sum = sum + a[i];

        if(a[i] > max)
        {
            max = a[i];
        }

        if(a[i] < min)
        {
            min = a[i];
        }
    } 

    printf("该数组的和为%d,最大值是%d,最小值是%d\n",sum,max,min);
    return 0;
}