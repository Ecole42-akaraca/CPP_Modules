/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:57 by akaraca           #+#    #+#             */
/*   Updated: 2023/03/07 14:31:12 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main ()
{
	{
		std::cout << "- Bob' mission -" << std::endl;
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		// HumanA	bob = HumanA("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << "\n- Jim' mission -" << std::endl;
		Weapon club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		// HumanB	jim = HumanB("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
