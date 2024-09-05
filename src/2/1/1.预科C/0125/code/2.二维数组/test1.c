#include <stdio.h>



int main()
{
    int a[3][3];

    int i,j;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }


    int max = a[0][0];
    int min = a[0][0];
    int sum = 0;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
            }
            if(a[i][j] < min)
            {
                min = a[i][j];
            }
            sum += a[i][j];
        }
    }


    printf("max:%d min:%d sum:%d\n",max,min,sum);

    return 0;
}