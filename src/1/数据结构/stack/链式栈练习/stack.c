#include "stack.h"

struct LinkedStack *DestroyStack(struct LinkedStack *s)
{
    if (s)
    {
      struct node *p = s->top;
      while (p)
      {
        p->next = s->top;
        s->top = s->top->next;
        p->next = NULL;
        free(p);
        p = s->top;
      }
    }
}
struct LinkedStack *InitStack()
{
  struct LinkedStack *s = malloc(sizeof(s));
  s->bottom = NULL;
  s->num = 0;
  s->top = NULL;
  while (1)
  {
    struct node *p = malloc(sizeof(*p));
    Datatype d;
    p->next = NULL;
    p->prev = NULL;
    scanf("%d", &d);
    p->data = d;
    if (d==0)
    {
      break;
    }
    if (s->top == NULL)
    {
      s->top = p;
      s->bottom = p;
    }
    else
    {
      p->next= s->top;
      s->top= p;
    }
    s->num++;
  }
  return s;
}
void printlist(struct LinkedStack *h)
{   
    if (h)
    {
      struct node *p = h->top;
      while (p)
      {
        printf("%d ", p->data);
        p = p->next;
      }
    }
    
}

void ClearStack(struct LinkedStack *s)
{
         if(s)
         {
           struct node *p = s->top;
           while (p)
           {
             p->next = s->top;
             s->top = s->top->next;
             p = s->top;
           } 
         }
}

int StackIsEmpty(struct LinkedStack *s)
{ 
     if(s)
     {
       return s->num == 0;
     }     
}

int StackLength(struct LinkedStack *s)
{
      if (s)
      {
        return s->top->data;
      }
}
Datatype GetTop(struct LinkedStack *s)
{
  if (s)
  {
    return s->top->data;
  }
  
}
Datatype Pop(struct LinkedStack *s)
{
      if(s)
      {
        struct node *p = malloc(sizeof(*p));
        Datatype d = s->top->data;
        p= s->top;
        p->next = NULL;
        s->top = s->top->next;
        free(p);
        return d;
      }
}
void Push(struct LinkedStack *s, Datatype d)
{
    if(s)
    {
      struct node *p = malloc(sizeof(*p));
      p->next = NULL;
      p->prev = NULL;
      p->data = d;
      if (s->top == NULL)
      {
        s->top = p;
        s->bottom = p;
      }
      else
      {
        p->next = s->top;
        s->top = p;
      }
    }
}