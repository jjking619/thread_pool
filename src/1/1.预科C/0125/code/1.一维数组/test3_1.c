#include <stdio.h>


int main()
{
    int a[10];
    int i;
    for(i = 0;i < 10;i++)
    {
        scanf("%d",&a[i]);
    }  
    int flag = 1;//标志位,如果是1就递增,如果是0就不是
    //比较数组中的元素
    for(i = 0;i < 9;i++)//因为每次都和后一位比较,所以只需要访问到倒数第二个就好了
    {
        if(a[i] >= a[i+1])
        {
            flag = 0;
            break;
        }
    }

    //判断标志位
    if(flag == 1)
    {
        printf("该数组是递增数组\n");
    }
    else
    {
        printf("该数组不是递增数组\n");
    }

    return 0;
}