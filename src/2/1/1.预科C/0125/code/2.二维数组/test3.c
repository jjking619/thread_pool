#include <stdio.h>


int main()
{
    int a[4][4] = {1,9,-8,7,11,-12,3,1,10,6,4,5,1,0,3,8};

    int i,j;
    int count = 0;//计算山顶元素的个数

    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            if((i == 0 ||a[i][j] > a[i-1][j]) && (i == 3 || a[i][j] > a[i+1][j]) 
                && (j == 0 || a[i][j] > a[i][j-1]) && (j == 3 || a[i][j] > a[i][j+1]))
            {
                printf("%d ",a[i][j]);
                count++;
            }
        }
    }
    printf("\n");
    printf("山顶元素有%d个\n",count);

    return 0;
}