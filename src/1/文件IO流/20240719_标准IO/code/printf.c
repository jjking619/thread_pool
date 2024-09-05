#include <stdio.h>

int main()
{
    printf("123");//123放在缓冲区里
    perror("abc");
    while(1);
}