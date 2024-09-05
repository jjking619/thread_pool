#include <stdio.h>
#include "LinkedList.h"
int main()
{
  struct nodes *H = creat_list();
  Datatype x,a;
  printf("请输入x和a的值:\n");
  scanf("%d%d", &x, &a);
  H =modify_node(H, x, a);
  // printf("输入要删除的值:\n");
  // scanf("%d", &x);
  // H =delete_node(H,x);
  printflist(H);
  return 0;
  }