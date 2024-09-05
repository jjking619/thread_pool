#include "cicle.h"

Cqueue *InitQueue()
{
  Cqueue *r = malloc(sizeof(*r));
  r->front = -1;
  r->rear = -1;
  r->cur_num = 0;
}

void EnQueue(Cqueue *q, Datatype d)
{
  if (q->cur_num == MAX_LEN)
  {
    return;
  }
  if (q->cur_num == 0)
  {
    q->front = (q->front + 1) % MAX_LEN;
    q->rear = (q->rear + 1) % MAX_LEN;
    q->Cq[q->front] = d;
  }
  else{
    q->rear = (q->rear + 1) % MAX_LEN;
    q->Cq[q->rear] = d;
  }
  q->cur_num++;
}

Datatype DeQueue(Cqueue *q)
{
  if(q)
  {
    if (q->cur_num == 0)
    {
      return 0;
    }
    Datatype d = q->Cq[q->front];
    q->cur_num--;
    if (q->cur_num == 0)
    {
      q->front = -1;
      q->rear = -1;
    }
      else
      {
        q->front = (q->front + 1) % MAX_LEN;
      }
      return d;
  }     
}

Cqueue *DestroyQueue(Cqueue *q)
{
   while (--q->cur_num)
   {
     DeQueue(q);
   }
   free(q);
}

int QueueIsEmpty(Cqueue *q)  //1为空,0为不空
{
     if(q)
     {
       return q->cur_num==0;
     }
}

int QueueLength(Cqueue *q)
{ 
  if(q){
    return q->cur_num;
  }
}

Datatype GetHead(Cqueue *q)
{
  if(q)
  {
      return q->Cq[q->front];
  }
}

void ClearQueue(Cqueue *q)
{
  if (q)
  {
    q->front = -1;
    q->rear = -1;
    q->cur_num = 0;
  }
}