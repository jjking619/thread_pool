#ifndef __CICLE_H__
#define __CICLE_H__

#include <stdlib.h>
#include <stdio.h>

typedef int Datatype; // 队列元素的类型
#define MAX_LEN 10
typedef struct Cqueue
{
  Datatype Cq[MAX_LEN];
  int front;   // 队头元素下标
  int rear;    // 队尾元素下标
  int cur_num; // 当前队列中元素的个数
} Cqueue;

Cqueue *InitQueue();
void EnQueue(Cqueue *q, Datatype d);
Datatype DeQueue(Cqueue *q);
Cqueue *DestroyQueue(Cqueue *q);
void ClearQueue(Cqueue *q);
int QueueIsEmpty(Cqueue *q);
int QueueLength(Cqueue *q);
Datatype GetHead(Cqueue *q);

#endif 