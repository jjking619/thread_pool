#include <stdio.h>


int main()
{
    int a = 6;
    int b;
    switch(a)
    {
        default:
            b = 0; 
        case 1:
            b = 2;
        case 2:
            b = 3;
        case 3:
            b = 4; 
    }

    printf("%d\n",b);
}