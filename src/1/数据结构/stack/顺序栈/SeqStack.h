#ifndef  __SEQLINKED_H__
#define  __SEQLINKED_H__

#include <stdlib.h>
typedef int Datatype;//栈中元素的类型 
#define STACK_MAX_LENGTH 1024 

typedef struct SeqStack
{
    Datatype S[STACK_MAX_LENGTH]; 
    int top;//栈顶元素在数组中的下标 
  
}Sqstack;

Sqstack *InitStack();
Sqstack *DestroyStack(Sqstack *s);
void ClearStack(Sqstack *s);
int StackIsEmpty(Sqstack *s);
int StackLength(Sqstack *s);
Datatype GetTop(Sqstack *s);
Datatype Pop(Sqstack *s);
void Push(Sqstack *s,Datatype d);
#endif  
