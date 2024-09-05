#include "linkedlistwithhead.h"
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
      h->last = pnew;
      /*头插法*/
      // pnew->next = h->first;
      // h->first = pnew;
    }
    h->nodenum++;
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
        h->first = pnew;
      }
      else if (pnew->data >= h->last->data)
      {
        h->last->next = pnew;
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
          pre = p;
          p = p->next;
        }

        pre->next = pnew;
        pnew->next = p;
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
  struct node *pre = NULL;
  struct node *pnew = NULL;
  // 1.新建结点
  pnew = malloc(sizeof(*pnew));
  pnew->data = a;
  pnew->next = NULL;
  // 2.找到值为x的结点
  p = h->first;
  while (p)
  {
    if (p->data == x) // 找到了
    {
      break;
    }
    pre = p;
    p = p->next;
  }
  // 3.插入新结点
  if (p != NULL)
  {
    if (p == h->first)
    {
      pnew->next = h->first;
      h->first = pnew;
    }
    else
    {
      pre->next = pnew;
      pnew->next = p;
    }
  }
  else
  { // 没找到,尾插
    if (h->first == NULL) //如果h本身是一个空链表
    {
      h->first= pnew;
      h->last = pnew;
    }
    else
    {
      pre->next = pnew;
      h->last = pnew;
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

  if (h->first == NULL)
  {
    printf("空表");
  }
  p = h->first;
  // 1.找到值为x的结点
  while (p)
  {
    h->nodenum--;
    if (p->data == x) // 找到了
    {
      // 2.删除结点
      if (p == h->first)
      {
        h->first= h->first->next;
        p->next = NULL; 
        free(p);
        p = h->first;
        if(h->nodenum==0)
        {
          h->last = NULL;
        }
      }
      else if (p==h->last)  //删除最后的一个节点
      {
        h->last = pre;
        pre->next = NULL;
        free(p);
        p = NULL;
      }
      
      else
      { // 删中间结点
        pre->next = p->next;
        p->next = NULL;
        free(p);
        p = pre->next;
      }
      
    }
    else
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

struct list *updata_node(struct list *h, Datatype x, Datatype a)
{
          
    struct node *p = h->first;
    while (p)
    {
      if (p->data == x) // 找到了
      {
        p->data = a;
      }
      p = p->next;
    }
      return h;
}
/*
    destroy_list:摧毁整个链表，包括头结点
*/
 struct list *destroy_list(struct list *h)
{
  struct node *p = h->first;
  while(p)
  {
    h->first = h->first->next;
    p->next=NULL;
    free(p);
    p = h->first;
  }
  free(h);
  printf("删除完成");
  return NULL;
};

/*
   is_childlist:判断子链表
*/
struct list *is_childlist(struct list *a, struct list *b)
{
    struct node *n1=a->first;
    struct node *n2 =b->first;
    struct node *pb = b->first; //记录pb的失败后的起点
    if (a->nodenum > b->nodenum)
    {
      printf("不是");
      return NULL;
    }
    else{
        while (n1 && n2)
      {
       if(n1->data==n2->data)
       {
         n1 = n1->next;
         n2 = n2->next;
       }
       else{
         n1 = a->first;
         pb = pb->next; //b链起点往后
         n2 = pb;  //b链从新起点开始
       }
      }
      if (n1==NULL)    
      {
        printf("是");
      } 
      else{
        printf("不是");
      }
    }
    return a;
}

/*
   list_reverse:逆转链表
*/
struct list *list_reverse(struct list *a)
{

  struct node *p = a->first;
  struct node *q = p->next;
  while (q!=NULL)
  {
    //将q删除
    p->next = q->next;
    //将q移动到表头
    q->next = a->first;
    a->first = q;
  //将q指向p后的结点
    q = p->next;
  } 
  return a;
}
/*
   merge_list:合并a和b两个升序链表为c
*/
struct list *merge_list(struct list *a,struct list *b)
{
     struct list *c = malloc(sizeof(struct list));
     c->first = NULL;
     c->last = NULL;
     c->nodenum = 0;
     if(a->first ==NULL)
      return b;
     if(b->first == NULL)
      return a;
    struct node *p1 = a->first;
    struct node *p2 = b->first;
    while (p1&&p2)
    {

      if (p1->data < p2->data) 
      {
         if(c->first==NULL)
         {
           c->first = p1;
           c->last = p1;
         }
         else{
           c->last->next = p1;
           c->last = c->last->next;
         }
         p1 = p1->next;
      }
      else
      {
        if(c->first==NULL)
         {
           c->first = p2;
           c->last = p2;
         }
         else{
           c->last->next = p2;
           c->last = c->last->next;
         }
         p2 = p2->next;
      }
    }
    if(p1){
      c->last->next = p1;
    }
    if(p2)
    {
      c->last->next = p2;
    }
    return c;
}


struct list *sort_list(struct list *a)  
{
  struct node *p = a->first;
  struct node *q = p->next;
  // struct node *pre = p;
  while (p)
  {
    while (p->next != NULL)
    {
      if(p->data>q->data)
    {
      // 将q删除
      // pre->next = q;
      // 将q移动到p前
      p->next=q->next ;
      // 将q指向p后的结点
      q->next = p;
    }
    else{
      p = p->next;
    }
      q = p->next; // p,q如果交换了结点,p已经在if里后移了
      // pre = pre->next;
    }
    a->last = p;     
  }
  return a;
}

/*
    insert_list:加入节点,把正数节点放在链表末端,把负数节点放在链表前端,试卷编程题
*/
struct list *insert_list(struct list *h)
{
  while (1)
  {
    Datatype d;
    struct node *pnew = malloc(sizeof(*pnew));
    pnew->data = 0;
    pnew->next = NULL;
    printf("请输入要加入的值\n"),
    scanf("%d", &d);
    if (d==0)
    {
       break;
    }
    pnew->data = d;
    if(d<0)
    {
      pnew->next = h->first;
      h->first=pnew;
    }
    else{
      h->last->next=pnew;
      h->last = pnew;
      pnew->next = NULL;
    }
  }
  return h;
}

/*
  request_merge:求两个链表有序带头双向链表的交集c,试卷编程题
*/
struct list *request_merge(struct list *a, struct list *b)
{
  struct list *c = malloc(sizeof(*c));
  c->first = NULL;
  c->last = NULL;
  c->nodenum = 0;
  struct node *pre1 = a->first;
  struct node *pre2;
  while (pre1)
  {
    pre2 = b->first;
    while (pre2)
    {
      if (pre1->data == pre2->data)
      {
        struct node *pnew = malloc(sizeof(*pnew));
        pnew->next = NULL;
        pnew->data = pre1->data;
        if (c->first == NULL)
        {
          c->first = pnew;
          c->last = pnew;
        }
        else
        {
          // pnew->next = c->first;
          // c->first = pnew;
         //尾插法
          c->last->next= pnew ;
          c->last = pnew;
        }
        c->nodenum++;
        printf("%d\n", c->nodenum);
        break;
      }
      else
      {
        pre2 = pre2->next;
      }
    }
    pre1 = pre1->next;
  }
  return c;
}

/*
    print_list:打印链表
*/
void printlist(struct list *h)
{
  if(h!=NULL)
  {
    // 需要一个遍历指针
    struct node *p = h->first;
    // int num = h->nodenum;
    while (p)
    {
      printf("%d ",p->data);
      p = p->next;
    }
  }
  printf("\n");
}