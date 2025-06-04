#include <iostream>
#include "BitcoinExchange.hpp"
#include <iomanip>

void printDate(int date)
{
  int year = date / 10000;
  int month = date % 10000 / 100;
  int day = date % 100;

  std::cout << year << "-" << std::setfill('0') << std::setw(2) << month << "-"
    << std::setfill('0') << std::setw(2) << day;
}

bool isLeapYear(int year)
{
  return ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
}

bool IsExistingDay(int month, int year, int day)
{
  static const int daysInMonth[] =
  {
     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };
  if (day > daysInMonth[month - 1] && !isLeapYear(year))
    return (false);
  else if (month == 2 && isLeapYear(year) && day > 29)
    return (false);
  return (true);
}


int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "error: usage: btc infile.csv\n";
    return (1);
  }
  try
  {
    BitcoinExchange btcEx;
    btcEx.search(argv[1]);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return (1);
  }
}
