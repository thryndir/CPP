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
  this->std::stack<T, Container>::operator=(mutantStack);
  return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
  std::cout << "MutantStack destructor called\n";
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
  return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
  return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
  return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
  return (this->c.end());
}
