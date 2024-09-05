#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

class list
{
private:
  node *front; // 队头节点地址
  node *real;  // 队尾节点地址
  int num;     // 队列中节点数目

public:
  void enqueue(int data);
  int dequeue();
  void destroy();
  //.....
};

int main()
{
 
  return 0;
}
