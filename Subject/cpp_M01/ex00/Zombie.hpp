/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:46:31 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 12:01:34 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie{
private:
	std::string	_name;

public:
	Zombie( std::string name );
	~Zombie( );

	void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
