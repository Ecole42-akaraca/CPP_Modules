/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:40 by akaraca           #+#    #+#             */
/*   Updated: 2023/03/07 14:30:37 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP_
# define HUMANA_HPP_

#include "Weapon.hpp"

class HumanA{
private:
	std::string	_name;
	Weapon 		&_weapon;

public:
	HumanA( std::string name, Weapon &weapon );
	~HumanA();
	void attack();
};

#endif
