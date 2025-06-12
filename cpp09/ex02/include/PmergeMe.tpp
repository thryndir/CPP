#define PMERGEME_TPP_INCLUDED
#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::FordJohnson(T& nbrSequence)
{
    T big;
    T small;
    std::vector<std::pair<long, long> > pairs;
    typename T::iterator it = nbrSequence.begin();
    std::pair<long, long> currentPair;
    int i = 0;
    while (it != nbrSequence.end())
    {
        if (i % 2 == 0)
            currentPair.first = *it;
        else
        {
            currentPair.second = *it;
            pairs.push_back(currentPair);
            currentPair.second = -1;
        }
        it++;
        i++;
    }

}
