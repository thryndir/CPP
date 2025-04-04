/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:15:13 by lgalloux          #+#    #+#             */
/*   Updated: 2025/02/04 17:45:33 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i(1); argv[i]; i++)
	{
		for (int j(0); argv[i][j]; j++)
		{
		char	toPrint = std::toupper(argv[i][j]);
			std::cout << (char)toPrint;
		}
		if (i + 1 != argc)
			std::cout << ' ';
	}
	return (0);
}
