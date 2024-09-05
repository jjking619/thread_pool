#include <stdio.h>


int main()
{
    int a[10];
    int j;
    for(j = 0;j < 10;j++)
    {
        scanf("%d",&a[j]);
    }
    int i = 0;//每次用来交换的位置
    int k;//哨兵,找负数的 
    for(k = 0;k < 10;k++)
    {
        if(a[k] < 0)//找到了一个负数
        {
            //交换位置
            int temp = a[k];
            a[k] = a[i];
            a[i] = temp;
            i++;//交换完了之后我们就要往后挪一个
        }
    }

    for(j = 0;j < 10;j++)
    {
        printf("%d ",a[j]);
    } 

    printf("\n");
    return 0;
}
