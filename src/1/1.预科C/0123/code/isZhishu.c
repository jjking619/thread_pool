#include <stdio.h>

int main()
{
    int flag = 1;//标志位 1是一个质数 0不是一个质数

    int n;//每次判断的那一个数
    scanf("%d",&n);
    if(n == 2)
    {
        printf("%d是质数\n",n);
        return 0;
    }     
    int i;//判断它是不是n的质数
    for(i = 2;i <= n-1;i++)
    {
        if(n % i == 0)//找到另外一个因数
        {
            flag = 0;
            break;//跳出循环 
        }
    }

    //判断标志位
    if(flag == 1)
    {
        printf("%d是质数\n",n);
    }
    else
    {
        printf("%d不是质数\n",n);
    }
    return 0;
}