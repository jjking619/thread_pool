#include "BinarySortTree.h"
#include "CircleQueue.h"

/*
    往二叉排序树中插入一个结点
*/
BiTnode *Insert_node(BiTnode *r,Datatype1 d)
{
    BiTnode *p = r;//遍历指针
    /*step1:创建一个新结点*/
    BiTnode *pnew = malloc(sizeof(*pnew));
    pnew->data = d;
    pnew->lchild = NULL;
    pnew->rchild = NULL;
    if(r == NULL)
    {
        return pnew;
    }
    while(1)
    {
        if(pnew->data < p->data)
        {
            if(p->lchild == NULL)
            {
                p->lchild = pnew;
                break;
            }
            p = p->lchild;
        }
        else if(pnew->data > p->data)
        {
            if(p->rchild == NULL)
            {
                p->rchild = pnew;
                break;
            }
            p = p->rchild;
        }
        else 
        {
            printf("数据重复!!!\n");
            break;
        }
    }

    return r;
}
/*
    创建一颗二叉排序树
*/
BiTnode *creat_sort_tree()
{
    BiTnode *r = NULL;//空树 
    Datatype1 d;
    while(1)
    {
        scanf("%d",&d);
        if(d == 0)
        {
            break;
        }
        r = Insert_node(r,d);
    }

    return r;
}
//用递归的方法,实现二叉树的先序 中序 后序 
//先序 
void pre_order(BiTnode *r)
{
    if(r == NULL)
    {
        return ;
    }
    //根 
    printf("%d ",r->data);
    //左
    pre_order(r->lchild);
    //右
    pre_order(r->rchild);
}
//中序 
void mid_order(BiTnode *r)
{
     if(r == NULL)
    {
        return ;
    }
    //左
    mid_order(r->lchild);
     //根 
    printf("%d ",r->data);
    //右
    mid_order(r->rchild);
}
//后序
void post_order(BiTnode *r)
{
    if(r == NULL)
    {
        return ;
    }  
    //左
    post_order(r->lchild);
    //右
    post_order(r->rchild);
    //根 
    printf("%d ",r->data);
}
//按层次遍历二叉树  -->队列  
void level_print(BiTnode *r)
{
    if(r == NULL)
    {
        return ;
    }
    Cqueue *cq = InitQueue();//初始化一个队列
    EnQueue(cq,r);//先把根结点入队
    while(!QueueIsEmpty(cq))
    {
        //1.出队并打印数据 
        BiTnode *p =DeQueue(cq);
        printf("%d ",p->data);
        //2.把这个结点的子树入队
        if(p->lchild)
        {
            EnQueue(cq,p->lchild);
        }
        if(p->rchild)
        {
            EnQueue(cq,p->rchild);
        }
    }
    printf("\n");
    DestroyQueue(cq);
}
/*
    delete_node:在r这颗二叉排序树中删除数据为d的这个结点 
*/
BiTnode *delete_node(BiTnode *r,Datatype1 d)
{
    /*step1:找到值为x的结点*/
    BiTnode *p = r;//p就是指向要删除的那个结点  
    BiTnode *pre =  NULL;//pre指向p的父节点  
    while(p)
    {
        if(d == p->data)
        {
            break;
        }
        else if(d > p->data)
        {
            pre = p;
            p = p->rchild;
        }
        else 
        {
            pre = p;
            p = p->lchild;
        }
    }
    //没找到
    if(p == NULL)
    {
        return r;
    }
    //找到了
    /*step2:删除p指向的结点*/
    if(p->lchild == NULL && p->rchild == NULL)//没有孩子
    {
        if(p == r)//p为根
        {
            free(p);
            return NULL;
        }
        if(p == pre->lchild)
        {
            pre->lchild = NULL;//断链子
            free(p);
            p = NULL;
        }
        else if(p == pre->rchild)
        {
            pre->rchild = NULL;
            free(p);
            p = NULL;
        }

    }
    else if(p->lchild != NULL && p->rchild != NULL)//p有两个孩子
    {
        BiTnode *p2 = p->lchild;//p2指向p的左子树当中的最大结点
        BiTnode *pre2 = NULL;
        if(p2->rchild == NULL)//p2现在就是最大结点
        {
            p->data = p2->data;
            p->lchild = p2->lchild;
            free(p2);
            p2 = NULL;
        }
        else 
        {
            while(p2->rchild)
            {
                pre2 = p2;
                p2 = p2->rchild;
            }
            p->data = p2->data;
            pre2->rchild = p2->lchild;
            free(p2);
            p2 = NULL;
        }
    }
    else//p只有一个孩子  
    {
        if(p == r)
        {
            if(p->lchild)
            {
                BiTnode *ret = p->lchild;
                p->lchild = NULL;
                free(p);
                p = NULL;
                return ret;
            }
            else 
            {
                BiTnode *ret = p->rchild;
                p->rchild = NULL;
                free(p);
                p = NULL;
                return ret;
            }
        }
        if(p == pre->lchild)
        {
            if(p->lchild)
            {
                pre->lchild = p->lchild;
                p->lchild = NULL;
                free(p);
                p=NULL;
            }
            else 
            {
                pre->lchild = p->rchild;
                p->rchild = NULL;
                free(p);
                p=NULL;
            }
        }
        else
        {
            if(p->lchild)
            {
                pre->rchild = p->lchild;
                p->lchild = NULL;
                free(p);
                p=NULL;
            }
            else 
            {
                pre->rchild = p->rchild;
                p->rchild = NULL;
                free(p);
                p=NULL;
            }
        }
    }

    return r;
}

//递归删除二叉树的结点  
BiTnode *delete_node_r(BiTnode *r,Datatype1 d)
{
    if(r == NULL)
    {
        return NULL;
    }
    else if(d < r->data)
    {
        r->lchild = delete_node_r(r->lchild,d);
    }
    else if(d > r->data)
    {
        r->rchild = delete_node_r(r->rchild,d);
    }
    else //找到了 r就是你要删除的结点
    {
        if(r->lchild != NULL)//r有左子树，则找左子树中最大的
        {
            BiTnode *p = r->lchild;
            while(p->rchild != NULL)
            {
                p = p->rchild;
            }
            r->data = p->data;
           r->lchild = delete_node_r(r->lchild,p->data);//在r的左子树中删除p这个结点  
        }
        else if(r->rchild != NULL)//r只有右子树 则找右子树当中最小的结点
        {
            BiTnode *p = r->rchild;
            while(p->lchild != NULL)
            {
                p = p->lchild;
            }
            r->data = p->data;
           r->rchild = delete_node_r(r->rchild,p->data);//在r的左子树中删除p这个结点
        }
        else//r是叶子结点 
        {
            free(r);
            return NULL;
        }
    }

    return r;
}

BiTnode * Destroy_tree(BiTnode *r)
{
    while(r)
    {
        r = delete_node_r(r,r->data);//每次删除根  
    }

    return NULL;
}