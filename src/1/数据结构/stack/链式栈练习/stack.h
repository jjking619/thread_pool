#ifndef __STACK_H__
#define __STACK_H__
#include <stdlib.h>
#include <stdio.h>
typedef int Datatype; // 栈中元素的类型
#define STACK_MAX_LENGTH 1024

struct node
{
  Datatype data;
  struct node *next;
  struct node *prev;
};

struct LinkedStack
{
  struct node *bottom; // 栈底元素的指针，链表中的第一个结点
  struct node *top;    // 栈顶元素的指针，链表中的最后一个结点
  int num;             // 栈中元素的个数
};

struct LinkedStack *DestroyStack(struct LinkedStack *s);
struct LinkedStack *InitStack();
void printlist(struct LinkedStack *h);
void ClearStack(struct LinkedStack *s);
int StackIsEmpty(struct LinkedStack *s);
int StackLength(struct LinkedStack *s);
Datatype GetTop(struct LinkedStack *s);
Datatype Pop(struct LinkedStack *s);
void Push(struct LinkedStack *s, Datatype d);

#endif