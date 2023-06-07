/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:46:37 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 12:07:39 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main( void )
{
	std::string buffer;
	int			N;

	std::cout << "Zombie Horde Count: ";
	std::getline(std::cin, buffer);
	N = std::atoi(buffer.c_str());

	Zombie *horde = zombieHorde(N, "Zombie");
	delete [] horde;
	return (0);
}
 