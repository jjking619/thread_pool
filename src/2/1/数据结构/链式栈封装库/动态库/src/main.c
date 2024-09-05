#include "LinkedStack.h"
int main(){
  struct LinkedStack *h=InitStack();
  printlist(h);
  // DestroyStack(h);
  // printlist(h);
  // ClearStack(h);
  // if (StackIsEmpty(h))
  // {
  //   printf("栈为空");
  // }
  // else{
  //   printf("栈为不空");
  // }
  // printf("%d",StackLength(h));
  // printf("%d",GetTop(h));
  // while (!StackIsEmpty(h))
  // {
  //   printf("%d ", Pop(h));
  // }
  // printlist(h);
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
}