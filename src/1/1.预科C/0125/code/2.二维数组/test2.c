#include <stdio.h>


int main()
{
    int a[3][4];

    int i,j;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("原来输入的数组是:\n");
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 4;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    //直接定义一个四行三列的数组
    int b[4][3];
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 4;j++)
        {
            b[j][i] = a[i][j];
        }
    }
    
    printf("经过转换后的数组是:\n");
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 3;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    return 0;


}