#include<stdio.h>
int main()
{
    int a[6][6]={0};
    int i,j,k=0;
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1])
        {
            printf("%d ",a[i][j]);
            k++;
        }
        }
    }
    printf("\n山顶元素有%d个\n",k);
    return 0;
}