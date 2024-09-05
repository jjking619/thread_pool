#include "linkedlist.h"

//创建一个链表
struct nodes *Creat_List()
{
    struct nodes *head = NULL;
    struct nodes *tail = NULL;
    struct nodes *pnew = NULL;
    Datatype d;
    
    while(1)
    {
      pnew = malloc(sizeof(*pnew));
      scanf("%d",&d);
      if(d == 0)
      {
        break;
      }
      pnew->data = d;
      pnew->next=NULL;
      if(head==NULL){
        head = pnew;
        tail = pnew;
      }
      else{
        //头插法
        pnew->next=head;
        head=pnew;
      }
    }
    return head;
};

void Printf_List(struct nodes *h)
{
  while (h)
  {
    printf("%d ", h->data); 
    h = h->next;
  }
}