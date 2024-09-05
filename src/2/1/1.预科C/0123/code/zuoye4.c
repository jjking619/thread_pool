#include <stdio.h>


int main()
{
    int a,n;
    scanf("%d%d",&a,&n);

    int sn = 0;
    int an = 0;

    int i;
    for(i = 0;i<n;i++)
    {
        an = an*10 + a;
        sn = sn + an;
    }

    printf("%d\n",sn);
    return 0;
}