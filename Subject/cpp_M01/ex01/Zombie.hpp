/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:46:58 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/22 14:47:12 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

#include <iostream>
#include <cstdlib>

class Zombie{
private:
	std::string _name;

public:
	Zombie();
	~Zombie();

	void announce( void );
	void setName( std::string name );
};

Zombie *zombieHorde( int N, std::string name );

#endif