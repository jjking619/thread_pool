#include "stack.h"


int main()
{
    struct LinkedStack *h = InitStack();
    printlist(h);

    Datatype d;
    while (1)
    {
      scanf("%d", &d);
      if (d == 0)
      {
        break;
      }
      Push(h, d);
    }
    printlist(h);

   return 0;
}