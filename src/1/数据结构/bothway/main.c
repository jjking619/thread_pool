#include "bothway.h"

int main()
{
  struct list *h = creat_list();
  Datatype x,a;
  printf("输入删除x的值\n");
  scanf("%d", &x);
  delete_node(h, x);
  printlist(h);
  // destroy_list(h);
  // printf("输入要查找x的值和要添加a的值\n");
  // scanf("%d%d", &x,&a);
  // add_a_node(h,x,a);
  // printlist(h);

  return 0;
}
