#include <stdio.h>



int main()
{
    int a[10] = {4,2,3,5,3,1,9,3,6,8};//以升序为例
    int i,j;
    for(j = 0;j < 9;j++)//控制比较的趟数
    {
        for(i = 0;i < 9-j;i++)//控制每趟比较多少次,次数跟趟数有关的
        {
            if(a[i] > a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }  
        }
    }

    for(i = 0;i < 10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;


}