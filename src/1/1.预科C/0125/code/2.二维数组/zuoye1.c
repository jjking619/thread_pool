#include <stdio.h>



int main()
{
    int a[4][4]={1,13,2,3,4,12,5,8,14,11,15,16,9,10,7,6};

    
    
    int i,j,k;//循环变量
    int max;//保存最大值,同时也要用来判断是否是列最小值
    int max_i;//最大值所在的列下标

    int flag;//标志位,用来判断是否为鞍点

    for(i = 0;i < 4;i++)//遍历所有行
    {
        max = a[i][0];//每次最大值都初始化为该行第一个
        flag = 1;
        for(j = 0;j < 4;j++)//找这一行的最大值
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
                max_i = j;
            }
        }

        //判断是否这个行最大值是这一列的最小值
        for(k = 0;k < 4;k++)
        {
            if(a[k][max_i] < max)//如果在这一列找到一个比行最大值小的值,那么就不是鞍点 
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            printf("%d\n",max);
        }
    }

    return 0;
}