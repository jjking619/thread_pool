#include <stdio.h>


int main()
{
    int sum = 0;
    int i = 0;

    loop:
        if(i%3 == 0)
        {
            sum = sum+i;
        }
        i++;
        if(i <= 100)
        {
            goto loop;
        }  

    printf("%d\n",sum);

    return 0; 
}