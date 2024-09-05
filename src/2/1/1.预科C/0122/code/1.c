#include <stdio.h>


int main()
{
    //S1:定义两个数 从键盘输入 
    int a,b;
    scanf("%d %d",&a,&b);

    //S2:比较大小
    if(a > b)
    {
        printf("%d  %d\n",a,b);
    }
    else
    {
        printf("%d  %d\n",b,a);
    }

    return 0;
}


