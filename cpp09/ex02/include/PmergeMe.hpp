#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>

void buildInsertionOrder(int n, int offset, std::vector<int>& order);
void sortPair(std::vector<std::pair<long, long> >& pairs);
template <typename T>
void createWinners(std::vector<std::pair<long, long> >& pairs, T& winners, bool first);
template <typename T>
void createLosers(std::vector<std::pair<long, long> >& pairs, T& losers, bool first);
std::ostream& operator<<(std::ostream& os, const std::vector<long>& vector);

class PmergeMe
{
  private:
    std::deque<long> _deque;
    std::vector<long> _vector;
  public:
    PmergeMe(const std::string& input);
    PmergeMe(const PmergeMe& pmergeMe);
    PmergeMe& operator=(const PmergeMe& pmergeMe);
    ~PmergeMe();
    template <typename T>
    void FordJohnson(T& nbrSequence, bool first);
    std::deque<long>& getDeque(void);
    std::vector<long>& getVector(void);
};

#ifndef PMERGEME_TPP_INCLUDED
#include "PmergeMe.tpp"
#endif

#endif
