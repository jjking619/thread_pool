#include <stdio.h>


int main()
{
    int a[10] = {1,3,5,7,9,11,13,15,17,19};
    int i;
    int x;
    scanf("%d",&x);
    for(i = 0;i < 10;i++)
    {
        if(a[i] = x)
        {
            printf("%d\n",x);
            return 0;
        }
    }
    printf("-1\n");  
    return 0; 
}