/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:44 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 13:05:20 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ){

	this->_name = name;
	std::cout << "	Constructor: " << "Bob" << std::endl;
}

HumanB::~HumanB( void ){

	std::cout << "	Destructor: " << "Jim" << std::endl;
}

void	HumanB::attack( void ){

	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	std::cout << "	Jim' weapon address: " << &this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &weapon ){

	this->_weapon = &weapon;
}
