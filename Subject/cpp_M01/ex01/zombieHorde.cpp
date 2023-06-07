/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:04 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 12:06:18 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ){

	Zombie *horde = new Zombie[N];
	int		i;

	i = 0;
	while (i < N){
		horde[i].setName(name + " " + std::to_string(i));
		horde[i].announce();
		i++;
	}
	return (horde);
}
