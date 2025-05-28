#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>

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
	return (result);
}

void parseDataBase(const std::string& line)
{
  if (line == "date,exchange_rate")
    return ;
  size_t pos;
  try
  {
    pos = line.find_first_not_of("0123456789");
    int year = strToNbr<int>(line.substr(0, 4));
    if (pos != 4 || line.at(pos) != '-' || year <= 2009 || year > 2025)
      throw (std::runtime_error("error: year format incorrect"));
  }
  catch (const std::exception& e)
  {
    throw (makeException<std::runtime_error>(e.what(), line));
  }

  try
  {
    pos++;
    int month = strToNbr<int>(line.substr(pos, 2));
    pos = line.find_first_not_of("0123456789", pos);
    if (pos != 7 || line.at(pos) != '-' || month < 1 || month > 12)
      throw (std::runtime_error("error: month format incorrect"));
  }
  catch (const std::exception& e)
  {
    throw (makeException<std::runtime_error>(e.what(), line));
  }

  try
  {
    pos++;
    int day = strToNbr<int>(line.substr(pos, 2));
    pos = line.find_first_not_of("0123456789", pos);
    if (pos != 10 || line.at(pos) != ',' || day < 1 || day > 31)
      throw (std::runtime_error("error: day format incorrect"));
  }
  catch (const std::exception& e)
  {
    throw (makeException<std::runtime_error>(e.what(), line));
  }

  try
  {
    pos++;
    float value = strToNbr<float>(line.substr(pos, line.size() - pos));
    if (value < 0)
      throw (makeException<std::runtime_error>("error: value format inferior to 0", line));
  }
  catch (const std::exception& e)
  {
    throw (makeException<std::runtime_error>(e.what(), line));
  }
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "error: usage: btc infile.csv\n";
    return (1);
  }
  std::map<int, float> map;
  std::string temp(argv[1]);
  std::ifstream dataBase(temp.c_str());
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
        std::cerr << e.what();
        return (1);
      }
    }
  }
  else
  {
    std::cerr << "Error when opening the file" << std::endl;
    dataBase.close();
    return (1);
  }
}
