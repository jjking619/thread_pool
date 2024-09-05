#include "SeqStack.h"
#include <stdio.h>


int main()
{
    Sqstack *s = InitStack();
    Datatype d;
    while(1)
    {
        scanf("%d",&d);
        if(d == 0)
        {
            break;
        }
        Push(s,d);
    }
    while(!StackIsEmpty(s))
    {
        printf("%d ",Pop(s));
    }
    printf("\n");

    return 0;
}
