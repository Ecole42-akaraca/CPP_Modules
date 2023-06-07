/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:29 by akaraca           #+#    #+#             */
/*   Updated: 2023/03/10 14:23:16 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ){

	std::cout << "	Constructor: " << "Harl" << std::endl;
}

Harl::~Harl( void ){

	std::cout << "	Destructor: " << "Harl" << std::endl;
}

void Harl::debug( void ){

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ){

	func_list func_list[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string func_name_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index = 0;
	int lenght = func_name_list->length() - 2; // We subtract -2 because the first argument index of the list is 1 and the last argument is NULL. 
	while (index <= lenght && (func_name_list[index]).compare(level))
		index++;
	if (index <= lenght)
		(this->*func_list[index])();
	else
		std::cout << "Wrong input" << std::endl;
}
