/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:46:21 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 12:09:02 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie( std::string name ){

	this->_name = name;
	std::cout << _name << " is born" << std::endl;
} // This func when creating a new structure. Should be called. (Constructor)

Zombie::~Zombie( void ){

	std::cout << _name << " is dead" << std::endl;
} // Used to remove an existing build. (Destructor)

void Zombie::announce( void ){

	std::cout << this->_name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
