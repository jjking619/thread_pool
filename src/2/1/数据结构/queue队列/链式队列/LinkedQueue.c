#include "LinkedQueue.h"

//初始化一个队列
LinkedQueue *InitQueue()
{
    LinkedQueue *q = malloc(sizeof(*q));
    q->front = NULL;
    q->rear = NULL;
    q->nodenum = 0;
    
    return q;
}
//入队
void EnQueue(LinkedQueue *q,Datatype d)
{
    if(q)
    {
        //把数据d入队 
        //step1：创建数据结点
        struct node *pnew = malloc(sizeof(*(pnew)));
        pnew->data = d;
        pnew->next = NULL;
        if(q->front == NULL)//从无到有
        {
            q->front = pnew;
            q->rear = pnew;
        }
        else 
        {
            q->rear->next = pnew;
            q->rear = pnew;
        }
        q->nodenum++;
        
    }
}
//出队 
Datatype DeQueue(LinkedQueue *q)
{
    if(q)
    {
        Datatype tmp = q->front->data;//保存要出队结点的数值
        struct node *p = q->front;
        q->front = q->front->next;
        p->next = NULL;
        free(p);
        q->nodenum--;
        if(q->nodenum == 0)
        {
            q->rear = NULL;
        }
        return tmp;
        
    }   
}

//清空一个队列
void ClearQueue(LinkedQueue *q)
{
    if(q)
    {
        struct node *p = q->front;
        while(p)
        {
            q->front = q->front->next;
            p->next = NULL;
            free(p);
            p = q->front;
        }
        q->rear = NULL;
        q->nodenum = 0;
    }
}
//判断一个队列是否为空  为空返回1  不为空返回0
int QueueIsEmpty(LinkedQueue *q)
{
    if(q)
    {
        return q->nodenum == 0;
    }
}
//返回队列的长度   
int QueueLength(LinkedQueue *q)
{
    if(q)
    {
        return q->nodenum;
        
    }
}
//获取队头元素的值但是不出队
Datatype GetHead(LinkedQueue *q)
{
    if(q)
    {
        return q->front->data;
    }
}
//摧毁一个队列
LinkedQueue *DestroyQueue(LinkedQueue *q)
{
    if(q)
    {
        struct node *p = q->front;
        while(p)
        {
            q->front = q->front->next;
            p->next = NULL;
            free(p);
            p = q->front;
        }
        free(q);
        
        return NULL;
    }
}