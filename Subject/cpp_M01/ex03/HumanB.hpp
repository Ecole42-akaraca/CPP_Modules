/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:48 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/22 14:47:49 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP_
# define HUMANB_HPP_

#include "Weapon.hpp"

class HumanB{
private:
	std::string	_name;
	Weapon		*_weapon;

public:
	HumanB( std::string name );
	~HumanB();
	void attack();
	void setWeapon( Weapon &weapon );
};

#endif
