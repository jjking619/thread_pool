#ifndef __AVL_H__
#define __AVL_H__

#include <stdio.h>
#include <stdlib.h>

typedef int Datatype1;

typedef struct AVLnode
{
  Datatype1 data;
  struct AVLnode *lchild;
  struct AVLnode *rchild;
  int height; // 保存这颗树的高度
} AVLnode;
int Height(AVLnode *r);
AVLnode *SingleRotateWithRight(AVLnode *k2);
AVLnode *SingleRotateWithLeft(AVLnode *k2);
AVLnode *DoubleRotateLeftRight(AVLnode *k3);
AVLnode *DoubleRotateRightLeft(AVLnode *k3);
AVLnode *Insert_node(AVLnode *r, Datatype1 d);
void pre_order(AVLnode *r);
void mid_order(AVLnode *r);
void post_order(AVLnode *r);

#endif
