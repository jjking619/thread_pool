#include <stdio.h>
int jiec(int n);

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",jiec(n));
    return 0;
}




int jiec(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else if(n > 1)
    {
        return jiec(n-1)*n;//函数在这里先展开,得到明确的值之后,在一步一步返回给值
    }
}