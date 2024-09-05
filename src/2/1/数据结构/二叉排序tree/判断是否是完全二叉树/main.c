#include "BinarySortTree.h"

int main()
{
  BiTnode *h = creat_sort_tree();
  // pre_order(h);
  // printf("\n");
  // mid_order(h);
  // printf("\n");
  // post_order(h);
  // printf("\n");
  level_print(h);
  if(is_EntireBinaryTree(h))
  {
    printf("YES");
  }
  else{
    printf("NO");
  }
      // Destory_node(h);
      // Datatype1 d;
      // printf("输入要删除的值\n");
      // scanf("%d", &d);
      // delete_node(h, d);
      // level_print(h);
      return 0;
}