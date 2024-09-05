#include "LinkedStack.h"

// 初始化一个栈
struct LinkedStack *InitStack()
{
  Datatype d;
  struct LinkedStack *s = malloc(sizeof(*s));
  s->bottom = NULL;
  s->top = NULL;
  s->num = 0;
  struct node *pnew = NULL; // 指向新创建的结点

  while (1)
  {
    /*step1:每获得一个数据就要申请一个新的结点*/
    scanf("%d", &d);
    if (d == 0) // 我们规定输入的数据为0表示结束
    {
      break;
    }
    pnew = malloc(sizeof(*pnew));
    /*step2:把数据写入到新的结点中*/
    pnew->data = d;
    pnew->next = NULL;
    pnew->prev = NULL;
    /*step3:把结点加入到链表中*/
    if (s->top == NULL) // 从无到有
    {
      s->top = pnew;
      s->bottom= pnew;
    }
    else
    {
      /*尾插法*/
      // s->bottom->next = pnew;
      // s->bottom = pnew;
      /*头插法*/
      pnew->next = s->top;
      s->top = pnew;
    }
    s->num++;
  }

  return s;
}

//销毁一个栈
struct LinkedStack *DestroyStack(struct LinkedStack *s)
{
  if (s)
  {
    s->top = NULL;
    free(s);
  }

  return NULL;
}

// 清空一个栈
void ClearStack(struct LinkedStack *s)
{
  if (s)
  {
    s->top= NULL;
  }
}
/*
//     判断一个栈是否为空
//     如果为空返回1   不为空返回0
 */
int StackIsEmpty(struct LinkedStack *s)
{
  if (s)
  {
    return s->top == NULL ;
  }
}
// 返回栈的长度
int StackLength(struct LinkedStack *s)
{
  if (s)
  {
    return s->num;
  }
}
// 获取栈顶元素的值 但是不出栈
Datatype GetTop(struct LinkedStack *s)
{
  if (s)
  {
    return s->top->data;
  }
}
// 出栈
Datatype Pop(struct LinkedStack *s)
{   
    struct node *p = s->top;
    // struct node *pre = NULL;
    // while (p)
      if (s)
      {
        // s->num--;
        s->top = s->top->next;
        // if (s->num != 0)
        // {
        //   p->next->prev = s->top;
        //   s->top = p->next;
        // }
        // p->next = NULL;
        // free(p);
        // p =s->top;
        // if (s->num == 0)
        // {
        //   s->bottom = NULL;
        // }
        return p->data;
      }
}
// 入栈
void Push(struct LinkedStack *s, Datatype d)
{
  struct node *p = s->top;
  // struct node *pnew = malloc(sizeof(*pnew));
  // Datatype d;
  if (s)
  {
    struct node *pnew = malloc(sizeof(*pnew));
    pnew->data = d;
    pnew->next = NULL;
    pnew->prev = NULL;
    // scanf("%d", &d);
    pnew->next = s->top;
    s->top->prev = pnew;
    s->top = pnew;
  }
}
void printlist(struct LinkedStack *h)
{
  if (h != NULL)
  {
    // 需要一个遍历指针
    struct node *p = h->top;
    // int num = h->nodenum;
    while (p)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
  printf("\n");
}