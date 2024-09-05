#include <stdio.h>
void array_input(int b[][4],int n);
void array_output(int b[][4],int n);
void water(int a[][6],int m,int i,int j);
int water_num(int a[][6],int m);

int main()
{
    int a[4][4];
    array_input(a,4);
    array_output(a,4);

    int b[6][6] = {0};
    int i,j;
    for(i = 1;i < 5;i++)
    {
        for(j = 1;j < 5;j++)
        {
            b[i][j] = a[i-1][j-1];
        }
    }
    int sum = water_num(b,6);

    printf("水洼的数量是%d\n",sum);

    return 0;


}




/*
    array_input:输入一个二维数组的元素
    参数列表:
        int b[][4]:数组元素的类型 
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
    函数名:water  负责每次找到水坑之后,把它附近的也全部查找了
    参数列表:
        二维数组,输入每次找到的有水的水坑坐标
    返回值:
        void
*/
void water(int a[][6],int m,int i,int j)
{
    if(a[i][j] == 1)//i,j坐标上的水坑是有水
    {
        a[i][j] = 0;
        water(a,6,i-1,j);
        water(a,6,i+1,j);
        water(a,6,i,j-1);
        water(a,6,i,j+1);
        //把它所有相关的水坑都记作了一个
    }
}


/*
    函数名:water_num 查找水洼的数量
    参数列表:二维数组 
    返回值:水洼的数量

*/
int water_num(int a[][6],int m)
{
    int i,j;
    int sum = 0;
    for(i = 1;i < 5;i++)
    {
        for(j = 1;j<m-1;j++)
        {
            //每次找到一个有水的水坑,就把它相关的全部计算下来
            if(a[i][j] == 1)
            {
                sum++;
                water(a,6,i,j);//把这个水坑相关的全部清0
            }
        }
    }
    return sum;
}