#include <algorithm>
#define PMERGEME_TPP_INCLUDED
#include "PmergeMe.hpp"

template <typename T>
void createWinners(std::vector<std::pair<long, long> >& pairs, T& winners, bool first)
{
    std::vector<std::pair<long, long> >::iterator it = pairs.begin();
    if (first)
        winners.push_back(it->second);
    while (it != pairs.end())
    {
        winners.push_back(it->first);
        it++;
    }
}

template <typename T>
void createLosers(std::vector<std::pair<long, long> >& pairs, T& losers, bool first)
{
    std::vector<std::pair<long, long> >::iterator it = pairs.begin();
    if (first)
        it++;
    while (it != pairs.end())
    {
        if (it->second != -1)
            losers.push_back(it->second);
        it++;
    }
}

template <typename T>
void binaryInsert(T& winners, long loser)
{
    int left = 0;
    int right = winners.size();

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (winners[mid] < loser)
            left = mid + 1;
        else
            right = mid;
    }
    winners.insert(winners.begin() + left, loser);
}

template <typename T>
void PmergeMe::FordJohnson(T& nbrSequence, bool first)
{
    T losers;
    std::vector<std::pair<long, long> > pairs;
    typename T::iterator it = nbrSequence.begin();
    std::pair<long, long> tempPair;
    int i = 0;
    while (it != nbrSequence.end())
    {
        if (i % 2 == 0)
            tempPair.first = *it;
        else
        {
            tempPair.second = *it;
            pairs.push_back(tempPair);
            tempPair.second = -1;
        }
        it++;
        i++;
    }
    if (nbrSequence.size() % 2 != 0)
        pairs.push_back(tempPair);
    sortPair(pairs);
    nbrSequence.clear();
    createWinners(pairs, nbrSequence, first);
    createLosers(pairs, losers, first);
    if (nbrSequence.size() >= 2)
        FordJohnson(nbrSequence, false);
    if (!losers.empty())
    {
        std::vector<int> order;
        buildInsertionOrder(losers.size(), 0, order);
        std::vector<int>::iterator oit = order.begin();
        typename T::iterator wit;
        while (oit != order.end())
        {
            wit = std::lower_bound(nbrSequence.begin(), nbrSequence.end(), losers.at(*oit));
            nbrSequence.insert(wit, losers.at(*oit));
            oit++;
        }
    }
}
