#include <stdio.h>


int main()
{
    int n,m,k;//分别定义了我们这个行 列 要占的座位数
    scanf("%d%d%d",&n,&m,&k);
    int a[n][m];
    int i,j;//循环变量

    //输入数组
    for(i = 0; i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    int zero_num = 0;//记录连续的0的个数
    int count = 0;//可以坐的位置数
    //遍历数组找位置坐
    for(i = 0;i < n;i++)
    {
        zero_num = 0;//每一行都要重新记录连续位置的个数
        for(j = 0;j < m;j++)//找一行的空座位
        {
            if(a[i][j] == 0)
            {
                zero_num++;//连续的座位就+1
            }
            else
            {
                zero_num = 0;//否则就-1
            }

            //当空座>=要占座位数的时候, count++
            if(zero_num >= k)
            {
                count++;
            }
        }
    }

    printf("有%d种的坐法\n",count);
    return 0;
}