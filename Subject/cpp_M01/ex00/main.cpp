/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:45:55 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 13:25:18 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int	main( void )
{
	//stack : stores local variables. heap : dynamic memory for programmer to allocate.
	//While value types, pointers and addresses are stored in Stack, reference values are stored in Heap.
	//Access to Stack is faster than Heap.
	Zombie stackZombie("stack");
	stackZombie.announce();

	Zombie *heapZombie = newZombie("heap");
	heapZombie->announce();

	delete heapZombie;

	randomChump("random");
	return (0);
}
