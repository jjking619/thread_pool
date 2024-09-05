#include "AVL.h"
#include <stdio.h>

int main()
{
  AVLnode *at = NULL; // 空树
  Datatype1 d;
  while (1)
  {
    scanf("%d", &d);
    if (d == 0)
    {
      break;
    }
    at = Insert_node(at, d);
  }
  pre_order(at);

  return 0;
}