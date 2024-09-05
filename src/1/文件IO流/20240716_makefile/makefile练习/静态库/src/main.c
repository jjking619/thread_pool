#include "BinarySortTree.h"

int main()
{
    BiTnode *r = creat_sort_tree();
    level_print(r);//层次遍历
    Datatype1 d;
    scanf("%d",&d);
    r =delete_node(r,d); 
    level_print(r);//层次遍历
   
    return 0;
}