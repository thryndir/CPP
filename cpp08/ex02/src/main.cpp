#include <iostream>
#include <vector>
#include "MutantStack.hpp"

int main()
{
  MutantStack<int> mstack;
  MutantStack<int> stack2;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite)
  {
  std::cout << *it << std::endl;
  ++it;
  }
  std::stack<int> s(mstack);
  std::cout << "stack2 part >>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
  stack2.push(5);
  stack2.push(17);
  std::cout << stack2.top() << std::endl;
  stack2.pop();
  std::cout << stack2.size() << std::endl;
  stack2.push(3);
  stack2.push(5);
  stack2.push(737);
  //[...]
  stack2.push(0);
  MutantStack<int>::iterator it2 = stack2.begin();
  MutantStack<int>::iterator ite2 = stack2.end();
  ++it2;
  --it2;
  while (it2 != ite2)
  {
  std::cout << *it2 << std::endl;
  ++it2;
  }
  std::stack<int> a(stack2);

  return 0;
}
