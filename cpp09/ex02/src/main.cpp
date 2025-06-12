#include <iostream>
#include "PmergeMe.hpp"
#include <vector>

void printVector(std::vector<int>& order)
{
  size_t pos = 0;
  while (pos < order.size())
  {
    std::cout << order[pos] << " ";
    pos++;
  }
  std::cout << std::endl;
}

std::vector<int> generate_jacobsthal_up_to(int n)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    if (n == 0) return jacobsthal;
    jacobsthal.push_back(1);
    while (true)
    {
      int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
      if (next >= n) break;
      jacobsthal.push_back(next);
    }
    return jacobsthal;
}

int jacobsthal_index(int n)
{
    std::vector<int> jacobsthal = generate_jacobsthal_up_to(n);
    std::cout << "with n = " << n << " the jacobsthal suite is equal to: ";
    printVector(jacobsthal);
    if (jacobsthal.size() < 2)
        return 0;
    return jacobsthal[jacobsthal.size() - 2]; // avant-dernier
}

void build_insertion_order(int n, int offset, std::vector<int>& order)
{
    if (n <= 0)
        return;
    if (n == 1)
    {
      std::cout << "offset = " << offset << std::endl;
      order.push_back(offset);
      printVector(order);
      std::cout << std::endl;
      return;
    }

    int m = jacobsthal_index(n);
    order.push_back(offset + m);
    std::cout << "offset = " << offset << std::endl;
    std::cout << "with m = " << m << std::endl;
    printVector(order);
    std::cout << std::endl;
    build_insertion_order(m, offset, order);
    build_insertion_order(n - m - 1, offset + m + 1, order);
}

std::vector<int> optimal_insertion_order(int n)
{
    std::vector<int> order;
    build_insertion_order(n, 0, order);
    return order;
}

int main(int argc, char **argv)
{
  (void)argv;
  (void)argc;
  PmergeMe test("0 1 2 3 4 5 98");
  test.FordJohnson(test.getDeque());
  optimal_insertion_order(8);
  return (1);
}
