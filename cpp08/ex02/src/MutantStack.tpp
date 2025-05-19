#include <stack>
#include <deque>
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
  : std::stack<T, Container>()
{
  std::cout << "MutantStack default constructor called\n";
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const Container& cont)
  : std::stack<T, Container>(cont)
{
  std::cout << "MutantStack constructor called\n";
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& mutantStack)
  : std::stack<T, Container>(mutantStack)
{
  std::cout << "MutantStack copy constructor called\n";
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& mutantStack)
{
  if (this == &mutantStack)
    return (*this);
  std::stack<T, Container> = mutantStack;
  return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
  std::cout << "MutantStack destructor called\n";
}

template <typename T, typename Container>
iterator MutantStack<T, Container>::begin
{
  return (std::stack<T, Container>.begin());
}

template <typename T, typename Container>
iterator MutantStack<T, Container>::end()
{
  return (std::stack<T, Container>.end());
}

template <typename T, typename Container>
const_iterator MutantStack<T, Container>::begin()
{
  return (std::stack<T, Container>.begin())
}

template <typename T, typename Container>
const iterator Mutantstack<T, Container>::end()
{
  return (std::stack<T, Container>.end());
}
