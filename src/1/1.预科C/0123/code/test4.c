#include <stdio.h>


int main()
{
    // int a;
    // printf("请输入您要操作的这个数:\n");
    // scanf("%d",&a);
    // int an;//保存每次取余的余数

    // while(a)//当a不等于0的时候就进入的循环
    // {
    //     an = a%10;//取出我们的个位数
    //     printf("%d ",an);
    //     a = a/10;//a进行取整 当a == 0的时候不进入循环
    // }
    // printf("\n");
    // return 0;

    
    int a;
    printf("请输入您要操作的这个数:\n");
    scanf("%d",&a);
    int new_a = 0;
    int an;//保存每次取余的余数

    while(a)//当a不等于0的时候就进入的循环
    {
        an = a%10;//取出我们的个位数
        new_a = new_a*10 + an;//每次确保我们这个数能够大一位(个十百千这个位)
        a = a/10;//a进行取整 当a == 0的时候不进入循环
    }
    printf("%d\n",new_a);
    return 0;
}