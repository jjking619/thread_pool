#include "twolist.h"
/*
creat_list : 根据用户的输入创建一个带头结点的单链表
*/
struct list *creat_list()
{
  Datatype d; // 用来保存用户的数据
  /*step0:先建立一个头结点*/
  struct list *h = malloc(sizeof(struct list));
  h->first = NULL;
  h->last = NULL;
  h->nodenum = 0;
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
    if (h->first == NULL) // 从无到有
    {
      h->first = pnew;
      h->last = pnew;
    }
    else
    {
      /*尾插法*/
      h->last->next = pnew;
      pnew->prev = h->last;
      h->last = pnew;
      /*头插法*/
      // pnew->next = h->first;
      // h->first->prev = pnew;
      // h->first = pnew;
    }
    h->nodenum++;
  }
  if(h->nodenum!=0)
  {
    h->first->prev = h->last;
    h->last->next = h->first;
  }
  return h;
}

/*
    creat_sort_list:根据用户的输入创建一个升序带头结点的单链表
*/
struct list *creat_sort_list()
{
  Datatype d; // 用来保存用户的数据
  /*step0:先建立一个头结点*/
  struct list *h = malloc(sizeof(struct list));
  h->first = NULL;
  h->last = NULL;
  h->nodenum = 0;
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
    if (h->first == NULL) // 从无到有
    {
      h->first = pnew;
      h->last = pnew;
    }
    else
    {
      if (pnew->data <= h->first->data)
      {
        pnew->next = h->first;
        h->first->prev = pnew;
        h->first = pnew;
      }
      else if (pnew->data >= h->last->data)
      {
        h->last->next = pnew;
        pnew->prev = h->last;
        h->last = pnew;
      }
      else
      {
        struct node *p = h->first;
        struct node *pre = h->first;
        while (1)
        {
          if (p->data > pnew->data) // 找到
          {
            break;
          }
          // pre = p;
          p = p->next;
        }
        p->prev->next = pnew;
        pnew->next = p;
        pnew->prev = p->prev;
        p->prev = pnew;
        // pre->next = pnew;
        // pnew->next = p;
      }
    }
    h->nodenum++;
  }

  return h;
}

/*
    add_a_node:在链表h中值为x的结点之前插入一个新的结点值为a
        如果没有值为x的结点，则添加在尾部
        如果有很多个值为x的结点，默认添加在第一个值为x结点之前

*/
struct list *add_a_node(struct list *h, Datatype x, Datatype a)
{
  struct node *p = NULL;
  struct node *pnew = NULL;
  /*step1:新建结点*/
  pnew = malloc(sizeof(struct node));
  pnew->data = a;
  pnew->next = NULL;
  pnew->prev = NULL;

  /*step2:找到值为x的结点*/
  p = h->first;
  int num = h->nodenum;
  while (num--)
  {
    if (p->data == x) // 找到了
    {
      break;
    }
    p = p->next;
  }
  /*step3:插入新的结点*/
  if (num != -1) // 找到了
  {
    if (p == h->first) // 头插
    {
      pnew->next = h->first;
      h->first->prev = pnew;
      h->first = pnew;
      h->last->next = h->first;
      h->first->prev = h->last;
    }
    else // 插在中间
    {
      p->prev->next = pnew;
      pnew->next = p;
      pnew->prev = p->prev;
      p->prev = pnew;

    }
  }
  else // 没找到 尾插
  {
    if (h->first == NULL) // 如果h本身就是一个空链表
    {
      h->first = pnew;
      h->last = pnew;
      pnew->next = pnew;
      pnew->prev = pnew;
    }
    else
    {
      h->last->next = pnew;
      pnew->prev = h->last;
      h->last = pnew;
      h->last->next = h->first;
      h->first->prev = h->last;
    }
  }
  h->nodenum++;

  return h;
}

/*
    delete_node:在链表h中删除所有值为x的结点
*/
struct list *delete_node(struct list *h, Datatype x)
{
  struct node *p = NULL;
  struct node *pre = NULL;
  /*step1 : 找到值为x的结点*/
  p = h->first;
  int num = h->nodenum;
  while (num--)
  {
    if (p->data == x) // 找到了
    {
      h->nodenum--;
      /*step2:删除结点*/
      if (p == h->first)
      {
        if(h->nodenum==0)
        {
          h->first = NULL;
          h->last = NULL;
          free(p);
          p = NULL;
          return h;
        }
        h->first = h->first->next;
        // p->next->prev = h->first;
        h->first->prev = h->last;
        p->prev= NULL;
        p->next = NULL;
        h->last->prev = h->first;
        free(p);
        p = h->first;
      }
      else if (p == h->last) // 删最后一个结点
      {
        h->last =h->last->prev;
        h->last->next = h->first;
        p->prev = NULL;
        p->next = NULL;
        h->first->prev = h->last;
        free(p);
        p = NULL;
      }
      else // 删除中间的结点
      {
        pre->next = p->next;
        p->next->prev = pre;
        p->next = NULL;
        p->prev = NULL;
        free(p);
        p = pre->next;
      }
    }
    else // 没找到 接着找
    {
      pre = p;
      p = p->next;
    }
  }

  return h;
}

/*
    updata_node:把h链表中所有值为x结点的值全部改成a
*/
void updata_node(struct list *h, Datatype x, Datatype a)
{
  struct node *p = h->first;
  int num = h->nodenum;
  while (num--)
  {
    if (p->data == x)
    {
      p->data = a;
    }
    p = p->next;
  }
}

/*
    destroy_list:摧毁整个链表，包括头结点
*/
struct list *destroy_list(struct list *h)
{
  struct node *p = h->first;
  int num = h->nodenum;
  while (num--)
  {
    h->first = h->first->next;
    p->next->prev = h->first;
    p->next = NULL;
    free(p);
    p = h->first;
  }
  free(h);
  printf("删除完成");
  return NULL;
}

void printlist(struct list *h)
{
  if (h != NULL)
  {
    // 需要一个遍历指针
    struct node *p = h->first;
    int num = h->nodenum;
    while (num--)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
  printf("\n");
}



//  is_circle.c 的函数
/*
    is_circle:判断无头单链表是不是回环
*/