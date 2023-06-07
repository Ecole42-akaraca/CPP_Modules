/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:31 by akaraca           #+#    #+#             */
/*   Updated: 2023/03/07 14:30:59 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Colon structure should be used for reference assignment.
// only constructors take base initializers
HumanA::HumanA( std::string name, Weapon &weapon ):_name(name), _weapon(weapon){

	std::cout << "	Constructor: " << "Bob" << std::endl;
}

HumanA::~HumanA( void ){

	std::cout << "colon - weapon address: " << &this->_weapon << std::endl;
	std::cout << "	Destructor: " << "Bob" << std::endl;
}

void	HumanA::attack( void ){

	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	std::cout << "	Bob' weapon address: " << &this->_weapon.getType() << std::endl;
}
