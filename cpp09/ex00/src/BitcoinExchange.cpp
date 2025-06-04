#include "BitcoinExchange.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& data)
{
  std::cout << "constructor called\n";
  std::ifstream dataBase(data.c_str());
  if (dataBase.is_open() && dataBase.peek() != EOF) 
  {
    std::string line;
    while (std::getline(dataBase, line))
    {
      try
      {
        parseDataBase(line);
      }
      catch (const std::exception& e)
      {
        throw ;
      }
    }
  }
  else
  {
    throw (std::runtime_error("Error when opening the file"));
    dataBase.close();
  }
}

const char* BitcoinExchange::FirstLine::what() const throw()
{
  return ("First line");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitExc)
  :_dataBase(bitExc._dataBase)
  ,_input(bitExc._input)
{
  std::cout << "copy constructor called\n";
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bitExc)
{
  std::cout << "assignation operator called\n";
  if (this == &bitExc)
    return (*this);
  _dataBase.operator=(bitExc._dataBase);
  _input.operator=(bitExc._input);
  return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
  std::cout << "destructor called\n";
}

void BitcoinExchange::search(const std::string& file)
{
  std::ifstream infile(file.c_str());
  std::map<int, float>::iterator it;
  if (infile.is_open() && infile.peek() != EOF)
  {
    std::string line;
    while (std::getline(infile, line))
    {
      try
      {
        parseFile(line);
      }
      catch (const std::exception& e)
      {
        continue;
      }
      it = _dataBase.lower_bound(_input.first);
      if ((it == _dataBase.begin() && it->first != _input.first) || it == _dataBase.end())
        std::cout << "error: the date is not within the range of the dataBase: " << line << std::endl;
      else if (it->first == _input.first)
      {
        printDate(it->first);
        std::cout << " => " << _input.second << " = " << it->second * _input.second << std::endl;
      }
      else if ((--it)->first <= _input.first)
      {
        printDate(it->first);
        std::cout << " => " << _input.second << " = " << it->second * _input.second << std::endl;
      }
      else
        std::cout << "error: date not found: " << line << std::endl;
    }
  }
}

void BitcoinExchange::parseFile(const std::string& line)
{
  if (line == "date | value")
    throw (FirstLine());
  size_t pos;
  int result;
  try
  {
    int year = strToNbr<int>(line.substr(0, 4));
    pos = line.find_first_not_of("0123456789");
    result = year * 10000;
    if (pos != 4 || line.at(pos) != '-')
      throw (std::runtime_error("error: year format incorrect"));

    pos++;
    int month = strToNbr<int>(line.substr(pos, 2));
    pos = line.find_first_not_of("0123456789", pos);
    result += month * 100;
    if (pos != 7 || line.at(pos) != '-' || month < 1 || month > 12)
      throw (std::runtime_error("error: month format incorrect"));

    pos++;
    int day = strToNbr<int>(line.substr(pos, 2));
    pos = line.find_first_not_of("0123456789", pos);
    result += day;
    if (pos != 10 || line.at(pos) != ' ' || day < 1 || month > 12)
      throw (std::runtime_error("error: day format incorrect"));

    pos++;
    pos = line.find_first_not_of("0123456789", pos);
    if (pos != 11 || line.at(pos) != '|')
      throw (std::runtime_error("error: missing |"));

    pos++;
    pos = line.find_first_not_of("0123456789", pos);
    if (pos != 12 || line.at(pos) != ' ')
      throw (std::runtime_error("error: missing space after |"));
    
    pos = line.find_first_of("0123456789", pos);
    float value = strToNbr<float>(line.substr(pos, line.size() - pos));
    if (value < 0 || pos != 13)
      throw (std::runtime_error("error: value format inferior to 0"));
    _input.first = result;
    _input.second = value;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << ": " << line << std::endl;
    throw;
  }
}

void BitcoinExchange::parseDataBase(const std::string& line)
{
  if (line == "date,exchange_rate")
    return ;
  int result;
  size_t pos;
  try
  {
    pos = line.find_first_not_of("0123456789");
    int year = strToNbr<int>(line.substr(0, 4));
    result = year * 10000;
    if (pos != 4 || line.at(pos) != '-' || year < 2009 || year > 2025)
      throw (std::runtime_error("error: year format incorrect"));

    pos++;
    int month = strToNbr<int>(line.substr(pos, 2));
    pos = line.find_first_not_of("0123456789", pos);
    result += month * 100;
    if (pos != 7 || line.at(pos) != '-' || month < 1 || month > 12)
      throw (std::runtime_error("error: month format incorrect"));

    pos++;
    int day = strToNbr<int>(line.substr(pos, 2));
    pos = line.find_first_not_of("0123456789", pos);
    result += day;
    if (pos != 10 || line.at(pos) != ',' || !IsExistingDay(month, year, day))
      throw (std::runtime_error("error: day format incorrect"));

    pos++;
    float value = strToNbr<float>(line.substr(pos, line.size() - pos));
    if (value < 0)
      throw (std::runtime_error("error: value format inferior to 0"));
    _dataBase[result] = value;
  }
  catch (const std::exception& e)
  {
    throw (makeException<std::runtime_error>(e.what(), line));
  }
}
