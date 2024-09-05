#include "LinkedQueue.h"
#include <stdio.h>


int main()
{
    LinkedQueue *q = InitQueue();
    Datatype d;
    while(1)
    {
        scanf("%d",&d);
        if(d == 0)
        {
            break;
        }
        EnQueue(q,d);
    }
    while(!QueueIsEmpty(q))
    {
        printf("%d ",DeQueue(q));
    }
    printf("\n");

    return 0;
}
