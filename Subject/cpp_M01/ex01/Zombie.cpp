/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:46:52 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 12:15:46 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie( void ){

	std::cout << "a nameless zombie is born" << std::endl;
}

Zombie::~Zombie( void ){

	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce( void ){
	std::cout << this->_name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ){

	this->_name = name;
}
