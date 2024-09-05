#include "twolist.h"
struct nodes *creatlist(void);
void printf_list(struct nodes *h);
int list_length(struct nodes *h);

int main()
{
  struct nodes *h = creatlist();
  printf_list(h);
  int count = list_length(h);
  int num = 0;
  if(count%2==0)
  {
    while (h)
    {
      if (h == NULL)
      {
        return 0;
      }
      if (num == (count/2-1))
      {
        printf("%d %d", h->data, h->next->data);
        break;
      }
      h = h->next;
      num++;
    }
  }
  else{
    while (h)
    {
      if (h == NULL)
      {
        return 0;
      }
       if (num == (count/2))
      {
        printf("%d", h->data);
        break;
      }
      h = h->next;
      num++;
    }
  }
  
  return 0;
}


/*
    creatlist:创建无头单链表
*/
struct nodes *creatlist(void)
{
  Datatype d;                // 保存用户数据
  struct nodes *pnew = NULL; // 指向新创建的节点
  struct nodes *head = NULL; // 指向首节点
  struct nodes *tail = NULL; // 指向尾节点
  // head->num = 0;
  // tail->num = 0;
  while (1)
  {
    // 1.每个数据分配一个节点
    scanf("%d", &d);
    if (d == 0) //
    {
      break;
    }
    pnew = malloc(sizeof(*pnew));
    int temp = 0;
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
  // printf("%d", pnew->num);
  return head;
};

// 求链表的长度
int list_length(struct nodes *h)
{
  struct nodes *p = h;
  int num = 0;
  while (p)
  {
    num++;
    p = p->next;
  }
  return num;
}
/*
    printflist:打印链表的值
*/
void printf_list(struct nodes *h)
{
  while (h)
  {
    printf("%d ", h->data);
    h = h->next; 
  }
  printf("\n");
}