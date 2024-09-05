#include <stdio.h>


int main()
{
    int sum = 0;
    for(int i = 1;i <1000;i++)
    {
        sum = 0;
        for(int j = 1;j <= i-1;j++)
        {
            if(i%j == 0)
            {
                sum += j; 
            }
        }
        if(sum == i)
        {
            printf("%d\n",i);
        }
    }
}