/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:54 by akaraca           #+#    #+#             */
/*   Updated: 2023/02/22 14:48:55 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
# define HARL_HPP_

#include <iostream>

class Harl{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	void	defaultMessage( void );

public:
	Harl();
	~Harl();
	void	complain( std::string level );
};

typedef void (Harl::*func_list)();

#endif
