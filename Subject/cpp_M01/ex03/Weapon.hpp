/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:10 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 13:20:49 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
# define WEAPON_HPP_

#include <iostream>

class Weapon{
private:
	std::string	_type;

public:
	Weapon( std::string type );
	~Weapon();
	const std::string& getType(); // Must return a const reference
	void setType( std::string type );
};

#endif
