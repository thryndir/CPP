/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thryndir <thryndir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:41:18 by thryndir          #+#    #+#             */
/*   Updated: 2025/03/07 19:55:15 by thryndir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>

PhoneBook::PhoneBook() : mContactNbr(0)
{
	for (int i (0); i <= 7; i++)
		mContact[i] = Contact(i);
}

void	PhoneBook::SetContactNbr(const int Nbr)
{
	mContactNbr = Nbr;
}

int	PhoneBook::Search(void)
{
	int	Index (0);
	
	while (Index <= 7)
	{
		mContact[Index].PrintData(COLS);
		std::cout << '\n';
		Index++;
	}
	std::cout << '\n';
	int	Result (0);
	if (mContactNbr == 0)
		return (EXIT_SUCCESS);
	std::cout << "Please enter the index of the contact you want to display\n";
	Result = VerifNumber(true, mContactNbr);
	if (Result == EOF)
		return (EOF);
	mContact[Result].PrintData(ROWS);
	std::cout << '\n';
	return (EXIT_SUCCESS);
}

int   PhoneBook::Add(void)
{
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	DarkestSecret;
	std::string	PhoneNumber;

	std::cout << "Please type a FirstName\n";
	if (VerifEmpty(FirstName) == EOF)
		return (EOF);
	mContact[mContactNbr % 8].SetFirstName(FirstName);

	std::cout << "Please type a LastName\n";
	if (VerifEmpty(LastName) == EOF)
		return (EOF);
	mContact[mContactNbr % 8].SetLastName(LastName);

	std::cout << "Please type a NickName\n";
	if (VerifEmpty(NickName) == EOF)
		return (EOF);
	mContact[mContactNbr % 8].SetNickName(NickName);

	std::cout << "Please type a DarkestSecret\n";
	if (VerifEmpty(DarkestSecret) == EOF)
		return (EOF);
	mContact[mContactNbr % 8].SetDarkestSecret(DarkestSecret);

	std::cout << "Please type a PhoneNumber\n";
	if (VerifEmpty(PhoneNumber) == EOF)
		return (EOF);
	mContact[mContactNbr % 8].SetPhoneNumber(PhoneNumber);
	
	std::cout << "Contact :" << mContactNbr % 8 << " has been created\n";
	std::cout << '\n';
	mContactNbr++;
	return (EXIT_SUCCESS);
}
