#include <stdio.h>


int main()
{   
    int m,n;//从键盘输入的两个数
    scanf("%d%d",&m,&n);

    int x,y;//x就是最大公约数 y是最小公倍数

    //最大公约数,x一开始等于两个中小的那一个
    for(x=(m>n? n:m);x>=1;x--)
    {
        if((m%x == 0) && (n%x == 0))
        {
            printf("最大公约数为%d\n",x);
            break;
        }
    }

    //最小公倍数,y一开始等于两个中大的那一个
    for(y=(m>n? m:n);y <= m*n;y++)
    {
        if((y%m == 0) && (y%n == 0))
        {
            printf("最小公约数为%d\n",y);
            break;
        }
    }
    return 0;
}