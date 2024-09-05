#include <stdio.h>


int main()
{
    int sum = 0;
    int i = 0;

    loop:
        if(i%2 == 1)
        {
            sum = sum+i;
        }
        i++; 
        //满足条件才进入循环
        if(i <= 100)
        {
            goto loop;
        }

    printf("%d\n",sum);

    return 0;
}


