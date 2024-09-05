#include <stdio.h>


int a = 5;
int main()
{
    printf("%d\n",a);
    int a = 6;
    if(1)
    {
        int a = 7;
        printf("%d\n",a);
    }

    printf("%d\n",a);
}
