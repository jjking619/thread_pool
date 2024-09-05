#include <iostream>
using namespace std;
template <typename T>
T sum(T  a,T b){
  return a + b;
}
int main()
{
  cout << sum(3, 4) << endl;
  cout << sum(3.5, 5.5);
  return 0;
}
