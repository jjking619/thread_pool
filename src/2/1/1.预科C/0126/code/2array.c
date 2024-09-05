#include <stdio.h>
void array_input(int b[][4],int n);
void array_output(int b[][4],int n);
int is_duichen(int m,int n,int a[][n]);

int main()
{
    int a[4][4];
    array_input(a,4);
    array_output(a,4);

    int x = is_duichen(4,4,a);

    if(x == 1)
    {
        printf("该数组对称\n");
    }
    else
    {   
        printf("该数组不对称\n");
    }

    return 0;
}


/*
    array_input:输入一个二维数组的元素
    参数列表:
        int b[][3]:数组元素的类型 
        int n:数组元素的个数(把二维数组看做一维数组,里面的每一个元素是一个一维数组)
    返回值:
        void 不需要返回值
*/
void array_input(int b[][4],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < 4;j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }
    return ;
}

void array_output(int b[][4],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for( j = 0;j < 4;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return ;
}


/*
    is_duichen:判断一个二维数组是否水平对称而且垂直对称
    参数列表:
        m:行\
        n:列
        a[][n]:要输入的数组

    返回值:
        1:对称
        0:不对称
*/
int is_duichen(int m,int n,int a[][n])
{
    //用两个标志位来分别确定他的水平和垂直方向上是否对称
    int flag = 1;//垂直方向
    int sign = 1;//水平对称

    int i,j;//循环变量

    //水平对称
    //因为break只能跳出一层循环,所以外面这个循环,我们加条件限定
    for(i = 0;i < m && sign == 1;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(a[i][j] != a[i][n-1-j])
            {
                sign = 0;
                break;
            }
        }
    }

    //垂直对称
    for(j = 0;j < n && flag == 1;j++)
    {
        for(i = 0;i < m;i++)
        {
            if(a[i][j] != a[m-1-i][j])
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1 && sign == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}