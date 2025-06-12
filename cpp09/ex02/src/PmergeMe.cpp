#include "PmergeMe.hpp"
#include <cctype>
#include <string>
#include <sstream>
#include <fstream>

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
	int result = 0;
	while (std::isdigit(nbr.at(result)))
	{
		result++;
	}
	return (result);
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
		_vector.push_back(strToNbr<size_t>(input.substr(pos, len)));
		_deque.push_back(strToNbr<size_t>(input.substr(pos, len)));
		pos += len;
	}
}
