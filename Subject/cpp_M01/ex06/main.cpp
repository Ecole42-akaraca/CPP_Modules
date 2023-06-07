/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:49:00 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/23 13:14:40 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( int argc, char **argv )
{
	argc--;
	argv++;
	Harl talkative;
	if (argc == 1)
		talkative.complain(argv[0]);
	else
		std::cout << "Wrong Input" << std::endl;
	return (0);
}
