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
int delete(BiTnode *p)
{
    BiTnode *q, *s;
    // 1.p为叶子结点
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        p = NULL;
    }
    // 2.1 p左子树为空, 重接右子树
    else if (p->lchild == NULL)
    {
        q = p;
        p= p->rchild;
        free(q);
    }
    // 2.2 p右子树为空, 重接左子树
    else if (p->rchild == NULL)
    {
        q = p;
        p = p->lchild;
        free(q);
    }
    // 3. p左右子树均不为空
    else{
        q= p;
        s = p->rchild;
        while (s->lchild != NULL) // 找到要删除节点左子树的最右节点，即左子树的最大值或者 右子树的最小值节点
        {
            q = s; ///?????
            // q = s->lchild;
            s = s->lchild;
        }
        p->data=s->data;
        if (q != p)             // 判断是否执行上述while循环
            q->lchild = s->rchild; // 执行上述while循环，重接*q的左子树
        else
            q->rchild = s->rchild; // 未执行上述while循环，重接*q的右子树，对于这个情况，可以参考代码后给出的示例图
        free(s);
    }
    return 1;
} 

int  delete_node(BiTnode *r, Datatype1 d)
{
    //树为空,直接返回
     if(r==NULL)
         {
            return 0;
         }
     else{
          if(r->data==d){
             return delete(r);
          }
          else if(r->data<d)
          {
              return delete_node(r->rchild,d);
          }
          else {
              return delete_node (r->lchild,d);
          }
     }
}


int  Destory_node(BiTnode *r)
{ 
    if (r==NULL)
    {
        return 0;
    }
    
     while (r)
     {
         delete_node(r,r->data);
     }
     return 1;
}


/*
判断是否是完全二叉树
 返回值:
 1 是完全二叉树 
 0 不是完全二叉树
*/
int  is_EntireBinaryTree(BiTnode *r)
{
        Cqueue *cq = InitQueue(); // 初始化一个队列
        EnQueue(cq, r);           // 先把根结点入队
        int flag = 0;//空结点标志位,1表示出现了空结点
        while (!QueueIsEmpty(cq))
        {
            // 1.出队并打印数据
            BiTnode *p = DeQueue(cq);
            // BiTnode *pre = NULL;
            // printf("%d ", p->data);
            // 2.把这个结点的子树入队
            if (p->lchild)
            {
                if(flag==1) //表示在p之前的结点已出现了空结点
                {
                    DestroyQueue(cq);
                    return 0;
                }
                EnQueue(cq, p->lchild);
            }
            else{
                flag = 1;
            }
           
            if (p->rchild)
            {
                if (flag == 1) // 表示在p之前的结点已出现了空结点
                {
                    DestroyQueue(cq);
                    return 0;
                }
               EnQueue(cq, p->rchild);
            }
             else {
                 flag = 1;
            }

        }
        DestroyQueue(cq);
        return 1;
}