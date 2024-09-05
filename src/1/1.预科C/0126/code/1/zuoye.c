#include "zuoye.h"
#include <stdio.h>


int bit_count(unsigned int x)
{
    int bits = sizeof(x)*8;
    int i;
    int num = 0;//统计1的个数

    for(i = 0;i < bits;i++)
    {
        if(x & (1<<i))
        {
            num++;
        }
    }

    return num;
}

int bit_count_v2(unsigned int x)
{
    int num = 0;
    while(x)
    {
        //每次移动x的位到这个1这里来计算
        if(x & 1)
        {
            num++;
        }
        x = x >> 1;
        //x每次往右移动一位,直到x的值为0的时候,跳出循环
    }

    return num;
}