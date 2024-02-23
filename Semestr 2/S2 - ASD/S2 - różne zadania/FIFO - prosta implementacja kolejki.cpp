#include <iostream>
#include <queue>// std::queue
 
int main ()
{
  std::queue<int> myqueue;
  int myint;
 
  std::cout << "Please enter some integers (enter 0 to end): " << std::endl;
 
  do {
    std::cin >> myint;
    myqueue.push (myint);
  } while (myint);
 
  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << std::endl;
 
  return 0;
}