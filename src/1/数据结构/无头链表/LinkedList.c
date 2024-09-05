#include "LinkedList.h"
/*
  creat_list:根据用户输入创建一条无头单链表,并返回首节点的地址
*/
struct nodes *creat_list(void)
{
  Datatype d;  //保存用户数据
  struct nodes *pnew=NULL; //指向新创建的节点
  struct nodes *head = NULL; // 指向首节点
  struct nodes *tail = NULL; // 指向尾节点
  while (1)
  {
    //1.每个数据分配一个节点
    scanf("%d", &d);
    if(d==0) //
    {
      break;
    }
    pnew = malloc(sizeof(*pnew));
    //2.把数据写入新节点
    pnew->data = d;
    pnew->next = NULL;
    //3.加入到链表中
    if(head != NULL)  
    {
      //尾插法
      tail->next = pnew;
      tail = pnew;
      //头插法
      // pnew->next = head;
      // head = pnew;
    }
    else{ //从无到有
      head = pnew;
      tail = pnew;
    }
  }
  return head;
};

/*
  creat_sort_list:根据用户输入创建一条升序无头单链表,并返回首节点的地址
*/

struct nodes *creat_sort_list(void)
{
  
    Datatype d;               // 保存用户数据
    struct nodes *pnew = NULL; // 指向新创建的节点
    struct nodes *head = NULL; // 指向首节点
    struct nodes *tail = NULL; // 指向尾节点
    while (1)
    {
      // 1.每个数据分配一个节点
      scanf("%d", &d);
      if (d == 0) //
      {
        break;
      }
      pnew = malloc(sizeof(*pnew));
      // 2.把数据写入新节点
      pnew->data = d;
      pnew->next = NULL;
      // 3.加入到链表中
      if (head != NULL)
      {
        // 尾插法
        // tail->next = pnew;
        // tail = pnew;
        // 头插法
        //  pnew->next = head;
        //  head = pnew;
        // 从少到多
        if (pnew->data < head->data)
        {
          pnew->next = head;
          head = pnew;
        }
        else if (pnew->data >= tail->data)
        {
          tail->next = pnew;
          tail = pnew;
        }
        else
        {
          struct nodes *p = head;
          struct nodes *pre = head;
          while (1)
          {
             if(p->data >pnew->data)
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
      else
      { // 从无到有
        head = pnew;
        tail = pnew;
      }
    }
    return head;
  };

  /*
   add_node:在链表h的值为x的节点之前插入一个新的结点值为a,并返回首节点的地址
      如果没有值为x的结点,则添加在尾部
      如果有多个值为x的结点,默认添加在第一个值为x的结点
  */



struct nodes *add_node(struct nodes *h,Datatype x,Datatype a)
  {

    struct nodes *p = NULL;
    struct nodes *pre = NULL;
    struct nodes *pnew = NULL;
    //1.新建结点
    pnew = malloc(sizeof(*pnew));
    pnew->data = a;
    pnew->next=NULL;
    //2.找到值为x的结点
    p = h;
    while(p){
      if(p->data==x) //找到了
      {
        break;
      }
      pre = p;
      p = p->next;
    }
    //3.插入新结点
    if(p !=NULL)
    {
      if(p==h)
      { pnew->next = h;
        h = pnew;
      }
      else{
        pre->next = pnew;
        pnew->next= p;
      }
    }
    else{ //没找到,尾插
          if(h==NULL)
          {
            h = pnew;
          }
          else{
            pre->next = pnew;
          }
    }
    return h;
  };

  /*
     delete_node:删除链表h中所有值为x的节点,并返回首节点的地址
  
  */
struct nodes *delete_node(struct nodes *h, Datatype x)
  {
    struct nodes *p = NULL;
    struct nodes *pre = NULL;
   
    if (h==NULL)
    {
      printf("空表");
    }
  
    p = h;
    // 1.找到值为x的结点
    while (p)
    {
      if (p->data == x) // 找到了
      {
        //2.删除结点
        if (p == h)
        {
          h = h->next;
          p->next = NULL;
          free(p);
          p = h;

        }
        else{  //删中间结点
          pre->next = p->next;
          p->next = NULL;
          free(p);
          p = pre->next;
        }
      }
      else{
        pre = p;
        p = p->next;
      }
    }
    return h;
  };

  /*
      modify_node:把链表h的值为x的节点全部该成a,并返回首节点的地址

  */
struct nodes *modify_node(struct nodes *h, Datatype x, Datatype a)
  {
    struct nodes *p = h;
    p = h;
    while (p)
    {
      if (p->data == x) // 找到了
      {
        p->data = a;
      }
      p = p->next;
    }
      return h;
  };

void printflist(struct nodes *h)
{
  while(h)
  {
    printf("%d ", h->data);
    h = h->next;
  }

}