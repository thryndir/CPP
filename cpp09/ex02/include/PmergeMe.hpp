#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>

class PmergeMe
{
  private:
    std::deque<size_t> _deque;
    std::vector<size_t> _vector;
  public:
    PmergeMe(const std::string& input);
    PmergeMe(const PmergeMe& pmergeMe);
    PmergeMe& operator=(const PmergeMe& pmergeMe);
    ~PmergeMe();
    template <typename T>
    void FordJohnson(T& nbrSequence);
    std::deque<size_t>& getDeque(void);
    std::vector<size_t> getVector(void);
};

#ifndef PMERGEME_TPP_INCLUDED
#include "PmergeMe.tpp"
#endif

#endif
