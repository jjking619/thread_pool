#include <stdio.h>

int main()
{
    long s = 1;//定义结果
    int n;
    scanf("%d",&n);
    int i = 1;

    //判断它是0或者是1
    if(n == 0 || n == 1)
    {
        printf("%d! = 1\n",n);
        return 0;//让主函数在这里就结束了
    }

    //现在n不是0或者1
    do
    {
        s = s * i;
        i++;    
    }while(i <= n);
    printf("%d! = %ld\n",n,s);
    return 0;
}