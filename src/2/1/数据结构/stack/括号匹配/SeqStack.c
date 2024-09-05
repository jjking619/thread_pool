#include "SeqStack.h"

//初始化一个栈
Sqstack *InitStack()
{
    Sqstack *s = malloc(sizeof(*s));
    s->top = -1;//-1表示栈是空栈   
    return s;
}

//销毁一个栈
Sqstack *DestroyStack(Sqstack *s)
{
    if(s)
    {
        s->top = -1;
        free(s);
    }
    return NULL;
}

//清空一个栈
void ClearStack(Sqstack *s)
{
    if(s)
    {
        s->top = -1;
    }
}
/*
    判断一个栈是否为空 
    如果为空返回1   不为空返回0
*/
int StackIsEmpty(Sqstack *s)
{
    if(s)
    {
        return s->top == -1;
    }
}
//返回栈的长度
int StackLength(Sqstack *s)
{
    if(s)
    {
        return s->top+1;
    }
}
//获取栈顶元素的值 但是不出栈
Datatype GetTop(Sqstack *s)
{
    if(s)
    {
        return s->S[s->top];
    }
}
//出栈
Datatype Pop(Sqstack *s)
{
    if(s)
    {
        return s->S[(s->top)--];
    }
}
//入栈  
void Push(Sqstack *s,Datatype d)
{
    if(s)
    {
        s->S[++(s->top)]=d;
    }
}