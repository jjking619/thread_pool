#include <stdio.h>

int main()
{
    char s1[5];
    char s2[5]="1234";
    printf("s1:%p\n",s1);
    printf("s2:%p\n",s2);
    gets(s1);
    printf("s1:%s\n",s1);
    printf("s2:%s\n",s2);
    printf("%c\n",s2[2]);
}