#include <stdio.h>



int main()
{
    int sum = 0;
    int i = 1;

    loop:   //行标识符 
        sum += i;
        i++;
        //要加一个条件能够跳出循环===>满足一个条件进入循环,不满足了就跳出循环
        if(i <= 100)
        {
            goto loop;
        }
    
    printf("%d\n",sum);

    return 0;
        
}


