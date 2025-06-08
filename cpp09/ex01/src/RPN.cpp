#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <climits>

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

RPN::RPN(const std::string& str)
	:_input(str)
{
  if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
    throw (std::invalid_argument("unexpected caracter"));
	int numbers = 0;
	int operators = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
    char c = str.at(i);
    if (std::isdigit(c))
        numbers++;
    else if (c == '+' || c == '-' || c == '*' || c == '/')
        operators++;
	}
	if (operators != numbers - 1)
		throw (std::invalid_argument("invalid expression"));
}

RPN::RPN(const RPN& rpn)
	:_input(rpn._input)
	,_stack(rpn._stack)
{
}

void RPN::debugPrintStack() const
{
  std::stack<double> temp = _stack;
  std::cout << "DEBUG - Stack (size: " << temp.size() << "): ";
  
  if (temp.empty())
  {
    std::cout << "(empty)";
  }
  else
  {
    while (!temp.empty())
    {
      std::cout << temp.top() << " ";
      temp.pop();
    }
  }
  std::cout << std::endl;
}

RPN& RPN::operator=(const RPN& rpn)
{
	if (this == &rpn)
		return (*this);
	_stack = rpn._stack;
	_input = rpn._input;
	return (*this);
}

RPN::~RPN()
{
}

double RPN::compute(void)
{
	int pos = 0;
	int number;
	bool wasSpace = true;
	while (static_cast<size_t>(pos) < _input.size())
	{
		if (_input.at(pos) == ' ' && !wasSpace)
		{
			pos++;
			wasSpace = true;
			continue;
		}
		if (std::isdigit(_input.at(pos)) && wasSpace)
		{
			try
			{
				number = strToNbr<int>(_input.substr(pos, 1));
			}
			catch (const std::exception& e)
			{
				throw ;
			}
			_stack.push(number);
			wasSpace = false;
		}
		else if (std::string("+-*/").find(_input.at(pos)) != std::string::npos
		          && wasSpace && _stack.size() >= 2)
		{
			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();
			wasSpace = false;
			switch (_input.at(pos))
			{
				case '*':
					_stack.push(a * b);
					break;
				case '/':
					_stack.push(a / b);
					break;
				case '+':
					_stack.push(a + b);
					break;
				case '-':
					_stack.push(a - b);
					break;
			}
		}
		else
			throw (std::invalid_argument("invalid expression"));
		pos++;
		// debugPrintStack();
	}
	if (_stack.size() != 1)
		throw (std::runtime_error("unexpected error"));
	return (_stack.top());
}
