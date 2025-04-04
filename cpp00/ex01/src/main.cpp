/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thryndir <thryndir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:17:26 by lgalloux          #+#    #+#             */
/*   Updated: 2025/03/08 12:55:46 by thryndir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

int	StrToInt(const std::string& Str)
{
	std::stringstream	Sstream(Str);
	int					result;
	char				temp;

	if (!(Sstream >> result))
		throw std::invalid_argument("Please enter a valid int");
	while (Sstream.peek() != EOF && std::isspace(Sstream.peek()))
		Sstream.get(temp);
	if (Sstream.peek() != EOF)
		throw std::invalid_argument("Please enter a valid int");
	return (result);
}

void CheckRange(int Index, int ContactNumber)
{
	if ((Index < 0 || Index > 7))
		throw std::runtime_error("Please enter a value between 0 and 7");
	if (Index >= ContactNumber)
		throw std::runtime_error("Please enter the index of an existing contact");
}

int	VerifNumber(bool	CheckIndex, int ContactNumber)
{
	std::string Input;
	int			Number (0);

	do
	{
		std::getline(std::cin, Input);
		if (std::cin.eof())
			return (EOF);
		try
		{
			Number = StrToInt(Input);
			if (CheckIndex)
				CheckRange(Number, ContactNumber);
			return (Number);
		}
		catch (const std::runtime_error& Error)
		{
			std::cerr << Error.what() << '\n';
		}
		catch (const std::invalid_argument& Arg)
		{
			std::cerr << Arg.what() << '\n';
			std::cin.clear();
			char c;
			while (std::cin.peek() != EOF && std::isspace(std::cin.peek()))
				std::cin.get(c);
		}
	} while (true);
	return (EXIT_FAILURE);
}

void	FormatString(const std::string& Src)
{
	std::string ToPrint;

	if (Src.length() <= 10)
		std::cout << std::setw(10) << std::right << Src << '|';
	else
	{
		ToPrint = Src.substr(0, 9);
		ToPrint.push_back('.');
		std::cout << ToPrint << '|';
	}
}

int	VerifEmpty(std::string& OutToVerif)
{
	do
	{
		std::getline(std::cin, OutToVerif);
		if (std::cin.eof())
			return (EOF);
		std::string::size_type pos = OutToVerif.find_first_not_of(" \n\t\v\r\f");
		if (pos == OutToVerif.npos)
		{	
			std::cerr << "Input cannot be empty. Please enter a valid input: ";
			OutToVerif.clear();
		}
	} while (OutToVerif.empty());
	return (EXIT_SUCCESS);
}

int	main(void)
{
	std::string	Input;
	PhoneBook PhoneBook;
	
	while (Input != "EXIT")
	{
		std::cout << "Please enter your command [ADD, SEARCH, EXIT]\n";
		std::getline(std::cin >> std::ws, Input);
		if (std::cin.eof())
			return (EXIT_SUCCESS);
		if (Input == "ADD")
		{
			if (PhoneBook.Add() == EOF)
				return (EXIT_SUCCESS);
		}
		else if (Input == "SEARCH")
		{
			if (PhoneBook.Search() == EOF)
				return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
