#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
    char s[8];
    char *str="123456789";
    int r = snprintf(s,8,"%s",str);
    printf("s:%s\n",s);
    printf("r=%d\n",r);
    
}