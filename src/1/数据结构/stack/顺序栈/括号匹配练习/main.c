#include "SeqStack.h"
#include <stdio.h>
#include <string.h>

int judge_bracket(char *str);

int main()
{
    char str[32]={0};
    gets(str);
    if(judge_bracket(str))
    {
        printf("YES\n");
    }
    else 
    {
        printf("NO\n");
    }

    return 0;
}
/*
    括号匹配函数：judge_bracket  
    匹配返回1  不匹配返回0 
*/
int judge_bracket(char *str)
{
    Sqstack *s = InitStack();//申请一个栈 
    int i;
    int flag = 1;//1代表匹配   0代表不匹配
    for(i=0;i<=strlen(str);i++)
    {
        if(str[i] == '{')
        {
            Push(s,'}');
        }
        else if(str[i] == '(')
        {
            Push(s,')');
        }
        else if(str[i] == '[')
        {
            Push(s,']');
        }
        if(str[i] == '}'||str[i] == ']'||str[i] == ')')
        {
            if(!StackIsEmpty(s))//栈不为空
            {
                if(str[i] != Pop(s))//栈不为空，但是栈顶元素与遇到的右括号不相等
                {
                    flag = 0;
                    break;
                }
            }
            else//栈为空   
            {
                flag = 0;
                break;
            }
            
        }      
    }
    if(!StackIsEmpty(s))//栈不为空
    {
            flag = 0;
    }
    //销毁栈
    s=DestroyStack(s);

    return flag;
}