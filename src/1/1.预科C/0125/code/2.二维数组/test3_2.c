#include <stdio.h>
#include <limits.h>

int main()
{
    int x = INT_MIN;//注意头文件
    int a[4][4] = {1,9,-8,7,11,-12,3,1,10,6,4,5,1,0,3,8};
    int b[6][6] = {0};//尽量先把这个数组初始化一下

    //扩充原数组
    int i,j;
    int count = 0;

    for(i = 0;i < 6;i++)
    {
        for(j = 0;j < 6;j++)
        {
            //当是我们新数组的边界的时候,给一个极小值
            if(i == 0||i == 5||j == 0||j == 5)
            {
                b[i][j] = x;
            }
            else
            {
                b[i][j] = a[i-1][j-1];//原数组和他比较一下就知道了
            }
        }
    }

    //只需要去判断原数组的数据部分就好了
    for(i = 1;i < 5;i++)
    {
        for(j = 1;j < 5;j++)
        {
            if(b[i][j] > b[i-1][j] & b[i][j] > b[i+1][j] && b[i][j] > b[i][j-1]
                & b[i][j] > b[i][j+1])
            {
                printf("%d ",b[i][j]);
                count++;
            }
        }
    }
    printf("\n");
    printf("山顶元素有%d个\n",count);
    return 0;
}