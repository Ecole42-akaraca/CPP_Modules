/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:25 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 12:21:57 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "---SUBJECT OUTPUTS---" << std::endl;
	std::cout << "The memory address of the string variable:	&str		: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR:		stringPTR	: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:		&stringREF	: " << &stringREF << std::endl;

	// stringREF = "ahmet";
	std::cout << "\nThe value of the string variable:		str		: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR:		*stringPTR	: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:		stringREF	: " << stringREF << std::endl;
}
