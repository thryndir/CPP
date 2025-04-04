/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thryndir <thryndir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:41:21 by thryndir          #+#    #+#             */
/*   Updated: 2025/03/08 12:43:00 by thryndir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

enum ColOrRows
{
	COLS,
	ROWS
};

class PhoneBook
{
	Contact 	mContact[8];
	int			mContactNbr;
public:
	PhoneBook();
	int		Add(void);
	int		Search(void);
	void	SetContactNbr(const int Nbr);
	void	GetContactNbr(void) const;
};

void	FormatString(const std::string& Src);
int		VerifEmpty(std::string& OutToVerif);
int		VerifNumber(bool CheckRange, int ContactNbr);
int		StrToInt(const std::string& Str);
void 	CheckRange(int CheckIndex);

#endif
