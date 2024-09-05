#include <stdio.h>


int main()
{
    int i;//要判断的那个数
    int j;//用来找i的因数
    int sum = 0;//每次的因数之和
    for(i = 1;i <= 1000;i++)
    {
        sum = 0;//每次判断一个新的数字的时候,sum都要清0
        for(j = 1;j <= i/2;j++)
        {
            if(i % j == 0)//j是i的因数
            {
                sum += j;
            }
        }
        if(sum == i)
        {
            printf("%d\n",i);
        }
    }


    return 0;
}