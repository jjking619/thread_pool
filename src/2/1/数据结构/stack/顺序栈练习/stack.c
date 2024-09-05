#include "stack.h"

Sqstack *DestroyStack(Sqstack *s)
{
  free(s);
}

Sqstack *InitStack()
{
  Sqstack *s = malloc(sizeof(*s));
  s->top = -1;
  while (1)
  {
    Datatype d;
    scanf("%d", &d);
    if (d==0)
    {
      break;
    }
    if (s->top != STACK_MAX_LENGTH)
    {
      s->S[s->top+1] = d;
      s->top++;
    }
  }
  return s;
}
void printlist(Sqstack *h)
{   
    while (h->top!=-1)
    {
        printf("%d ", h->S[h->top+1]);
        h->top++;
    }
}

void ClearStack(Sqstack *s)
{
         if(s)
         {
           s->top = -1;
         }
}

int StackIsEmpty(Sqstack *s)
{ 
     if(s)
     {
       return s->top == -1;
     }     
}

int StackLength(Sqstack *s)
{
      if (s)
      {
        return s->top+1;
      }
}
Datatype GetTop(Sqstack *s)
{
  if (s)
  {
    return s->S[s->top+1];
  }
  
}
Datatype Pop(Sqstack *s)
{
      if(s->top!=-1)
      {
        Datatype d = s->S[s->top];
        s->top--;
        return d;
      }
}
void Push(Sqstack *s, Datatype d)
{
  if (s->top!=STACK_MAX_LENGTH)
  {
    s->S[s->top + 1]=d;
    s->top++;
  }
}