/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:37 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/22 15:37:07 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl talkative;

	talkative.complain("DEBUG");
	talkative.complain("INFO");
	talkative.complain("WARNING");
	talkative.complain("ERROR");
	talkative.complain("NULL");
	talkative.complain("");
	return (0);
}
