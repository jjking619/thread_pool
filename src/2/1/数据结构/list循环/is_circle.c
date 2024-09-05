#include "twolist.h"
int is_circle(struct nodes *h);
struct nodes *creatlist(void);
void printf_list(struct nodes *h);
void loop(struct nodes *h);

int main()
{
  struct nodes *h = creatlist();
  printf_list(h);
  loop(h);
  if(is_circle(h))
  {
    puts("YES");
  }
  else{
    puts("NO");
  }
  return 0;
}


//判断是否回环
int is_circle(struct nodes *h)
{
  struct nodes *p=NULL;       // 慢指针;
  struct nodes *q=NULL; // 快指针
  p = q = h;
  if (h==NULL)
  {
    printf("空表");
  }
  while(q!=NULL&&p!=NULL&&q->next!=NULL)
  {
    p = p->next;
    q = q->next->next;
    if (q == p)
      return 1;
  }
  return 0;
}

/*
    creatlist:创建无头单链表
*/
struct nodes *creatlist(void)
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
      tail->next = pnew;
      tail = pnew;
      // 头插法
      //  pnew->next = head;
      //  head = pnew;
    }
    else
    { // 从无到有
      head = pnew;
      tail = pnew;
    }
  }
  return head;
};

// 把链表变成一个环
void loop(struct nodes *h) 
{
  struct nodes *p = h;
  struct nodes *t = h;
  while (p->next)
  {
    p = p->next;
  }
  while (t->next)

  {
    if (t->data == -1)
    {
      p->next = t;
      return;
    }
    else
    {
      t = t->next;
    }
  }
}
  /*
      printflist:打印链表的值
  */
  void printf_list(struct nodes * h)
  {
    while (h)
    {
      printf("%d ", h->data);
      h = h->next;
    }
    printf("\n");
  }