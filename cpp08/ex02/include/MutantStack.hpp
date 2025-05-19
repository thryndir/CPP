#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
  public:
    MutantStack();
    MutantStack(const Container& cont);
    MutantStack(const MutantStack& mutantStack);
    MutantStack<T, Container>& operator=(const MutantStack& mutantStack);
    ~MutantStack();
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#include "MutantStack.tpp"
#endif
