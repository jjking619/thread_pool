#include <stdio.h>


int main()
{
    int l;//一个是第一个开始加的一个数
    int r;//一个是当前加的数
    int n,k;//n用来输入的数 k用来帮助打印
    scanf("%d",&n);
    int sum = 1;//每次已经加了1
    for(l = 1,r = 1;l <= n/2;)
    {
        if(sum < n)//和小于这个数
        {
            r++;//每次要加的数先加1在加上去
            sum += r;//1 + 2
        }
        else if(sum == n)//找到了这个数
        {
            //打印出结果 
            printf("%d = %d",n,l);
            for(k = l+1;k <= r;k++)//打印我们的这个序列,r是保存了最后一次加的那个数的
            {
                printf(" + %d",k);
            }
            printf("\n");

            //要找一个序列了
            sum = sum - l;//把最前面那个数剔除我们的序列
            l++;//把第一个数变成它后面一个
        }
        else    //sum > n 
        {
            sum = sum - l;//剔除第一个数
            l++;//l向后加一个
        }
    }

    return 0;
}