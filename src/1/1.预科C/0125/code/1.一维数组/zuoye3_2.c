#include <stdio.h>


int main()
{
    int a[10];
    int i,j;
    for(j = 0;j < 10;j++)
    {
        scanf("%d",&a[j]);
    }


    //当i在j的左边,交换才是正确的
    for(i = 0,j = 9;i < j;)
    {
        while(i < 9 && a[i] < 0)//用来找非负数,找到了i就会停在那里
        {
            i++;//
        }
        while(j > 0 && a[j] >= 0)//用来找负数,找到了j停在那里
        {
            j--;
        }

        //看i是否在j的左边
        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    for(j = 0;j < 10;j++)
    {
        printf("%d ",a[j]);
    } 

    printf("\n");
    return 0;
}
