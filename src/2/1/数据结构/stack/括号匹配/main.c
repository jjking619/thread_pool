#include "SeqStack.h"
#include <stdio.h>
#include <string.h>

int judge_bracket(char *str);

int main()
{
    char str[32] = {0};
    gets(str);
    if (judge_bracket(str))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}

//匹配返回1,不匹配返回0
int judge_bracket(char *str)
{
    Sqstack *s = InitStack();
    int flag = 1;
    int i;
    for (i = 0; i < strlen(str);i++)
    { 
         if
    }
}   