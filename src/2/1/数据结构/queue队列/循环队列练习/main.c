#include "cicle.h"
int main()
{
  Cqueue *q = InitQueue();
  Datatype d;
  while (1)
  {
    scanf("%d", &d);
    if (d == 0)
    {
      break;
    }
    EnQueue(q,d);
  }
  printf("%d", DeQueue(q)); 
  // while (1)
  // {
  //   scanf("%d ", &d);
 
  //   if (d == 0)
  //   {
  //     break;
  //   }  
  //    EnQueue(q, d);
  // }
  
  return 0;
}