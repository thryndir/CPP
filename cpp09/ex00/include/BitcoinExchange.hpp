#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>
#include <stdexcept>
#include <sstream>
#include <climits>
#include <fstream>

template <typename ExceptionType>
ExceptionType makeException(const std::string& message, const std::string& details)
{
  std::string result;
  result = message + ": " + details;
  return (ExceptionType(result));
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
	if (static_cast<double>(result) > static_cast<double>(INT_MAX))
		throw (std::overflow_error("error: value too large"));
	return (result);
}

void printDate(int date);
bool isLeapYear(int year);
bool IsExistingDay(int month, int year, int day);

class BitcoinExchange
{
  private:
    std::map<int, float> _dataBase;
    std::pair<int, float> _input;
  public:
    BitcoinExchange(const std::string& dataBase = "data.csv");
    BitcoinExchange(const BitcoinExchange& bitcoinExchange);
    BitcoinExchange& operator=(const BitcoinExchange& btcExc);
    ~BitcoinExchange();
    void parseDataBase(const std::string& line);
    void parseFile(const std::string& line);
    void search(const std::string& file);
    class FirstLine: public std::exception
    {
      virtual const char* what() const throw();
    };

};

#endif
