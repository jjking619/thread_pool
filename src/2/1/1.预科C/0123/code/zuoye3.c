#include <stdio.h>


int main()
{
    int n;
    scanf("%d",&n);

    int sum = 0;//求连续序列之和,需要重新赋值

    int i,j,k;//i是表示从i开始找序列,j每次保存i的值,开始加,k就是找到了复合条件的序列,帮助打印
    for(i = 1;i <= n/2;i++)
    {
        sum = 0;//每次sum重新清0
        for(j = i;sum <= n;j++)
        {
            sum = sum + j;
            if(sum == n)//找到了所需要的序列
            {
                //打印出结果 
                printf("%d = %d",n,i);
                for(k = i+1;k <= j;k++)//打印我们的这个序列
                {
                    printf(" + %d",k);
                }
                printf("\n");
            }
        }
    }

    return 0;
}