/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:06 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 12:30:33 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ){

	this->setType(type);
	std::cout << "	Created weapon address: " << &getType() << std::endl;
}

Weapon::~Weapon( void ){

	std::cout << "	Destructor: " << &getType() << std::endl;
}

const std::string& Weapon::getType( void ){

	return (_type);
}

void	Weapon::setType( std::string type ){

	this->_type = type;
}
