#include "CircleQueue.h"

//初始化一个队列
Cqueue *InitQueue()
{
    Cqueue *q = malloc(sizeof(*q));
    q->cur_num = 0;
    q->front = -1;
    q->rear = -1;//两个下标都为-1代表为空队列
    
    return q;
}
//入队
void EnQueue(Cqueue *q,Datatype d)
{
    if(q)
    {
        //需要判断队列是否为满队列  
        if(q->cur_num == MAX_LEN)
        {
            printf("the CircleQueue is Full!!\n");
            return ;
        } 
        if(q->cur_num == 0)//如果队列为空
        {
            
            q->front = (q->front+1)%MAX_LEN;
            q->rear = (q->rear+1)%MAX_LEN;
            q->Cq[q->front] = d;
        } 
        else 
        {
            q->rear = (q->rear+1)%MAX_LEN;
            q->Cq[q->rear] = d;

        }  
        q->cur_num++;   
    }
}
//出队 
Datatype DeQueue(Cqueue *q)
{
    if(q)
    {
        if(q->cur_num == 0)
        {
            printf("the CircleQueue is empty!!!\n");
            return 0;//0代表没有值可以出队
        }
        Datatype d = q->Cq[q->front];
        q->cur_num--;
        if(q->cur_num == 0)//如果出队之后为空队列
        {
            q->front = -1;
            q->rear = -1;
        }
        else 
        {
             q->front = (q->front+1)%MAX_LEN;
        } 
        return  d;    
    }  
    
}

//清空一个队列
void ClearQueue(Cqueue *q)
{
    if(q)
    {
        q->front = -1;
        q->rear = -1;
        q->cur_num = 0;
    }
}
//判断一个队列是否为空  为空返回1  不为空返回0
int QueueIsEmpty(Cqueue *q)
{
    if(q)
    {
        return q->cur_num == 0;
    }
}
//返回队列的长度   
int QueueLength(Cqueue *q)
{
    if(q)
    {
        return q->cur_num;
        
    }
}
//获取队头元素的值但是不出队
Datatype GetHead(Cqueue *q)
{
    if(q)
    {
        return q->Cq[q->front];
    }
}
//摧毁一个队列
Cqueue *DestroyQueue(Cqueue *q)
{
    if(q)
    {
       q->front = -1;
       q->rear = -1;
       q->cur_num = 0;
       free(q);
        return NULL;
    }
}