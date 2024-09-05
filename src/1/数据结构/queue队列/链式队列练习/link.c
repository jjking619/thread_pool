#include "link.h"

LinkedQueue *InitQueue()
{
  LinkedQueue *q = malloc(sizeof(*q));
  q->front = NULL;
  q->rear = NULL;
  q->nodenum = 0;
  return q;
}

void EnQueue(LinkedQueue *q, Datatype d)
{
    struct node *p = malloc(sizeof(*p));
    p->next = NULL;
    p->data = d;
    if (q)
    {
     if (q->front == NULL)
    {
      q->front = p;
      q->rear = p;
    }
    else{
      q->rear->next=p;
      q->rear= p;
    }
    }
    q->nodenum++;
}

Datatype DeQueue(LinkedQueue *q)
{
     if(q)
     {
          struct node *p = malloc(sizeof(*p));
          Datatype d = q->front->data;
          p = q->front;
          q->front = q->front->next;
          p->next = NULL;
          free(p);
          q->nodenum--;
          if (q->nodenum == 0)
          {
            q->rear = NULL;
          }
          return d;
     }
}
LinkedQueue *DestroyQueue(LinkedQueue *q)
{
         if (q)
         {
           struct node *p = q->front;
           while (p)
           {
             q->front = q->front->next;
             p->next = NULL;
             free(p);
             p = q->front;
          }
          free(q);
         }
         return NULL;
}
void ClearQueue(LinkedQueue *q)
{
      if(q)
      {  
        struct node *p = q->front;
        while (p)
        {  
          q->front = q->front->next;
          p->next = NULL;
          free(p);
          p = q->front;
        }
        q->rear = NULL;
        q->nodenum = 0;
      }
}
int QueueIsEmpty(LinkedQueue *q)
{
       if(q)
       {
         return q->nodenum == 0;
       }
}

int QueueLength(LinkedQueue *q)
{
  return q->nodenum;
}
Datatype GetHead(LinkedQueue *q)
{
  return q->front->data;
}