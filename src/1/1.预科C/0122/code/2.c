#include <stdio.h>


int main()
{
    //S1:从键盘输入输入三条边,整数
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    //S2:判断是否能够组成三角形 
    if((a + b > c) && (a + c > b) && (b + c > a))//组成三角形的条件
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
