#include "test.h"
#include <stdio.h>


/*
    array_input:输入一个数组的元素
    参数列表:
        int b[]:数组元素的类型 
        int n:数组元素的个数 
    返回值:
        void 不需要返回值
*/
void array_input(int b[],int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        scanf("%d",&b[i]);
    }
    return ;
}

void array_output(int b[],int n)
{
    int i;
    for(i = 0;i < 10;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
    return ;
}




/*
    array_input:输入一个二维数组的元素
    参数列表:
        int b[][3]:数组元素的类型 
        int n:数组元素的个数(把二维数组看做一维数组,里面的每一个元素是一个一维数组)
    返回值:
        void 不需要返回值
*/
void array_input2(int b[][3],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < 3;j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }
    return ;
}

void array_output2(int b[][3],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for( j = 0;j < 3;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return ;
}



/*
    is_sort:判断一个数组是否有序
    参数:
        int a[]:要输入的数组
        int n:数组元素的个数
    返回值:
        int
            1:表示数组有序
            0:表示数组无序
*/
int is_sort(int a[],int n)
{
    int flag = 1;//标志位,1表示升序,0表示无序

    //遍历数组,判断是否有序
    int i;
    for(i = 0;i < n-1;i++)
    {
        if(a[i] > a[i+1])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}