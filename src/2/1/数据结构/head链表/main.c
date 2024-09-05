#include "linkedlistwithhead.h"

int main()
{
  // struct list *h = creat_list();
  // struct list *H = creat_list();
  printf("a:的链表\n");
  struct list *a = creat_list();
  printlist(a);
  printf("b:的链表\n");
  struct list *b = creat_list();
  printlist(b);
  // struct list *H = creat_list();
  // sort_list(h);
  // is_childlist(h, H);
  // list_reverse(h);
  // merge_list(h, H);
  // Datatype x, a;
  // printf("请输入x和a的值:\n");
  // scanf("%d%d", &x, &a);
  // printf("请删除x的值:\n");
  // scanf("%d", &x);

  // printf("请修改要x的值:\n");
  // scanf("%d%d", &x,&a);
  // h = updata_node(h, x,a);
  // h=destroy_list(h);
  printlist(request_merge(a,b));
  // printlist(merge_list(h, H));
  return 0;
}