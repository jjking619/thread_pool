#include <stdio.h>
#include <limits.h>
int main()
{
    int a[4][4]={1,9,-8,7,11,-12,3,1,10,6,4,5,1,0,3,8};
    int b[6][6]={{},{0,1,9,-8,7,0},{0,11,-12,3,1,0},{0,10,6,4,5,0},{0,1,0,3,8,0},{}};
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(i==0||j==0||i==5||j==5)
            {
                b[i][j]=INT_MIN;
            }
    }
    }
    printf("山顶元素有\n");
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            if(b[i][j]>b[i+1][j]&&b[i][j]>b[i-1][j]&&b[i][j]>b[i][j+1]&&b[i][j]>b[i][j-1])
            {
                printf("%d\n",b[i][j]);
            }
        }
    }
    printf("\n");
}