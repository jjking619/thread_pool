#ifndef __LINK_H__
#define __LINK_H__
#include <stdio.h>
#include <stdlib.h>
typedef int Datatype; // 队列元素的类型

// 数据结点
struct node
{
  Datatype data; //
  struct node *next;
};
// 队列结点
typedef struct LinkedQueue
{
  struct node *rear;  // 指向队尾元素结点
  struct node *front; // 指向队头元素结点

  int nodenum;
} LinkedQueue;

LinkedQueue *InitQueue();
void EnQueue(LinkedQueue *q, Datatype d);
Datatype DeQueue(LinkedQueue *q);
LinkedQueue *DestroyQueue(LinkedQueue *q);
void ClearQueue(LinkedQueue *q);
int QueueIsEmpty(LinkedQueue *q);
int QueueLength(LinkedQueue *q);
Datatype GetHead(LinkedQueue *q);

#endif