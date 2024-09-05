#include "zuoye.h"
#include <stdio.h>


int main()
{
    int x = bit_count(1234);
    int y = bit_count_v2(1234);
    
    printf("%d %d\n",x,y);
    return 0;
}