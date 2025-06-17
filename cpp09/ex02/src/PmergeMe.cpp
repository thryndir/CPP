#include "PmergeMe.hpp"
#include <cctype>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <set>

std::ostream& operator<<(std::ostream& os, const std::vector<long>& vector)
{
    for (std::vector<long>::const_iterator it = vector.begin(); it != vector.end(); it++)
    {
        if (it + 1 != vector.end())
            os << *it << " ";
        else
            os << *it;
    }
  return (os);
}

template <typename T>
T	strToNbr(const std::string& str)
{
	std::stringstream	Sstream(str);
	T    result;
	char temp;

	if (!(Sstream >> result))
		throw (std::invalid_argument("error: invalid argument"));
	while (Sstream.peek() != EOF && std::isspace(Sstream.peek()))
		Sstream.get(temp);
	if (Sstream.peek() != EOF)
		throw (std::invalid_argument("error: unexpected caracter"));
	return (result);
}

int nbrLen(const std::string& nbr)
{
	size_t result = 0;
	while (result < nbr.size() && std::isdigit(nbr.at(result)))
	{
		result++;
	}
	return (result);
}

void sortPair(std::vector<std::pair<long, long> >& pairs)
{
    std::vector<std::pair<long, long> >::iterator it = pairs.begin();
    while (it != pairs.end())
    {
        if (it->second > it->first)
            std::swap(it->second, it->first);
        it++;
    }
}

std::vector<int> generJacobsthal(int n)
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

int jacobsthalIndex(int n)
{
    std::vector<int> jacobsthal = generJacobsthal(n);
    if (jacobsthal.size() < 2)
        return 0;
    return jacobsthal[jacobsthal.size() - 2];
}

void buildInsertionOrder(int n, int offset, std::vector<int>& order)
{
    if (n <= 0)
        return;
    if (n == 1)
    {
      order.push_back(offset);
      return;
    }
    int m = jacobsthalIndex(n);
    order.push_back(offset + m);
    buildInsertionOrder(m, offset, order);
    buildInsertionOrder(n - m - 1, offset + m + 1, order);
}

PmergeMe::PmergeMe(const std::string& input)
{
	if (input.empty())
		throw (std::invalid_argument("empty input"));
	if (input.find_first_not_of("0123456789 ") != std::string::npos)
		throw (std::invalid_argument("unexpected caracter"));
	if (input.at(0) == ' ' || input.at(input.size() - 1) == ' ')
		throw (std::invalid_argument("space at start or end of the string"));
	if (input.find("  ") != std::string::npos)
		throw (std::invalid_argument("double space detected"));
	size_t pos = 0;
	while (pos < input.size())
	{
		if (input.at(pos) == ' ')
		{
			pos++;
			continue;
		}
		int len = nbrLen(input.substr(pos));
		_vector.push_back(strToNbr<long>(input.substr(pos, len)));
		_deque.push_back(strToNbr<long>(input.substr(pos, len)));
		pos += len;
	}
	std::set<long> seen;
  for (std::vector<long>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
  {
    if (!seen.insert(*it).second)
        throw std::invalid_argument("doubled number detected");
  }
}

PmergeMe::PmergeMe(const PmergeMe& pmergeMe)
	:_deque(pmergeMe._deque)
	,_vector(pmergeMe._vector)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeMe)
{
	if (this == &pmergeMe)
		return (*this);
	_deque = pmergeMe._deque;
	_vector = pmergeMe._vector;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::deque<long>& PmergeMe::getDeque()
{
	return (_deque);
}

std::vector<long>& PmergeMe::getVector()
{
	return (_vector);
}
