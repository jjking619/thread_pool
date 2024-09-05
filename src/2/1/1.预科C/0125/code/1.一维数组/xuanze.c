#include <stdio.h>



int main()
{
    int a[10] = {4,2,3,5,3,1,9,3,6,8};//以升序为例
    int i,j;
    int max;//最大值
    int max_i;//最大值下标 

    for(j = 0;j < 9;j++)//选择的次数
    {
        max = a[0];
        max_i = 0;
        for(i = 0;i < 10-j;i++)//找当前数组里的最大值
        {
            if(a[i] > max)
            {
                max = a[i];
                max_i = i;
            }
        }
        //判断是否位置已经对了
        if(max_i != 9-j)
        {
            int temp = a[9-j];
            a[9-j] = a[max_i];
            a[max_i] = temp;
        }

    }

    for(i = 0;i < 10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;


}