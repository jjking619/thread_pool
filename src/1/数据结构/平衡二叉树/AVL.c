#include "AVL.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 返回这个树的高度
int Height(AVLnode *r)
{
  if (r == NULL)
  {
    return 0;
  }

  return r->height;
}
// 对k2进行单向右旋平衡处理  左深左插
AVLnode *SingleRotateWithRight(AVLnode *k2)
{
  AVLnode *k1 = k2->lchild;
  k2->lchild = k1->rchild;
  k1->rchild = k2;
  k2->height = MAX(Height(k2->lchild), Height(k2->rchild)) + 1;
  k1->height = MAX(Height(k1->lchild), Height(k1->rchild)) + 1;

  return k1;
}
// 对k2进行单向左旋平衡处理  右深右插
AVLnode *SingleRotateWithLeft(AVLnode *k2)
{
  AVLnode *k1 = k2->rchild;
  k2->rchild = k1->lchild;
  k1->lchild = k2;
  k2->height = MAX(Height(k2->lchild), Height(k2->rchild)) + 1;
  k1->height = MAX(Height(k1->lchild), Height(k1->rchild)) + 1;

  return k1;
}
// 对k3进行双向旋转(先左后右)   左深右插
AVLnode *DoubleRotateLeftRight(AVLnode *k3)
{
  k3->lchild = SingleRotateWithLeft(k3->lchild);
  return SingleRotateWithRight(k3);
}
// 对k3进行双向旋转(先右后左)   右深左插
AVLnode *DoubleRotateRightLeft(AVLnode *k3)
{
  k3->rchild = SingleRotateWithRight(k3->rchild);
  return SingleRotateWithLeft(k3);
}
// 向一个平衡二叉树中插入一个新的结点
AVLnode *Insert_node(AVLnode *r, Datatype1 d)
{
  if (r == NULL)
  {
    r = malloc(sizeof(*r));
    r->data = d;
    r->lchild = NULL;
    r->rchild = NULL;
    r->height = 1;

    return r;
  }
  if (d > r->data)
  {
    r->rchild = Insert_node(r->rchild, d); // 数值d插在右子树中
    r->height = MAX(Height(r->lchild), Height(r->rchild)) + 1;
    if (Height(r->rchild) - Height(r->lchild) > 1) // 数值d插在右子树中 发现不平衡了 右深
    {
      if (d > r->rchild->data) // 右深右插
      {
        r = SingleRotateWithLeft(r);
      }
      else // 右深左插
      {
        r = DoubleRotateRightLeft(r);
      }
    }
  }
  else if (d < r->data)
  {
    r->lchild = Insert_node(r->lchild, d); // 数值d插在左子树中
    r->height = MAX(Height(r->lchild), Height(r->rchild)) + 1;
    if (Height(r->lchild) - Height(r->rchild) > 1)
    {
      if (d > r->lchild->data) // 左深右插
      {
        r = DoubleRotateLeftRight(r);
      }
      else // 左深左插
      {
        r = SingleRotateWithRight(r);
      }
    }
  }

  return r;
}
// 用递归的方法,实现二叉树的先序 中序 后序
// 先序
void pre_order(AVLnode *r)
{
  if (r == NULL)
  {
    return;
  }
  // 根
  printf("%d ", r->data);
  // 左
  pre_order(r->lchild);
  // 右
  pre_order(r->rchild);
}
// 中序
void mid_order(AVLnode *r)
{
  if (r == NULL)
  {
    return;
  }
  // 左
  mid_order(r->lchild);
  // 根
  printf("%d ", r->data);
  // 右
  mid_order(r->rchild);
}
// 后序
void post_order(AVLnode *r)
{
  if (r == NULL)
  {
    return;
  }
  // 左
  post_order(r->lchild);
  // 右
  post_order(r->rchild);
  // 根
  printf("%d ", r->data);
}
