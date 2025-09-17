#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main( void )
{
  try
  {
    std::vector<int> vector;
    for (int i = 1; i <= 5; ++i)
      vector.push_back(i);
    std::cout << "vector " << easyfind(vector, 3) << " has been found\n";
    std::list<int> list;
    list.push_back(8);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(1);
    std::cout << "list "<< easyfind(list, 32) << " has been found\n";
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }
  return 0;
}
