#ifndef __BINARYSORTTREE_H__
#define __BINARYSORTTREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef int Datatype1;
typedef struct BiTnode
{
    Datatype1 data;//数据域 
    struct BiTnode *lchild;
    struct BiTnode *rchild;
}BiTnode;
BiTnode *Insert_node(BiTnode *r,Datatype1 d);
BiTnode *creat_sort_tree();
void pre_order(BiTnode *r);
void mid_order(BiTnode *r);
void post_order(BiTnode *r);
void level_print(BiTnode *r);
int delete_node(BiTnode *r, Datatype1 d);
int  delete(BiTnode *r);
int Destory_node(BiTnode *r);
#endif 
