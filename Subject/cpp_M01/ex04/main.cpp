/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:21 by akaraca           #+#    #+#             */
/*   Updated: 2023/03/10 12:34:15 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace( std::string buffer, std::string s1, std::string s2 ){

	std::string new_line;
	int i = 0;
	int l_buf = buffer.length(); //The buffer length is taken.
	int l_s1 = s1.length(); // Getting the length of the argument that needs to be changed.
	while (i < l_buf)
	{
		if (!buffer.compare(i, l_s1, s1)) //i represents the starting index, l_s1 is the length, s1 is the compared argument.
		{
			new_line += s2; // The argument to be changed is added.
			i += l_s1; // The index should be skipped by the length of the argument to be changed.
		}
		else
		{
			new_line += buffer[i]; // Unchanged arguments, index index is added.
			i++;
		}
	}
	return (new_line);
}

/**
 * ./Replace test.txt Ali Mert
 **/
int main( int argc, char **argv )
{
	argc--;
	argv++;
	if (argc != 3)
	{
		std::cout << "Error, not enought inputs!" << std::endl;
		return (0);
	}

	std::string buffer;
	std::ifstream read; // input file stream
	std::string	filename = argv[0]; // It is taken as a string in order to use a function on the received argument.

	read.open(argv[0]);
	if (read.is_open())
	{
		std::ofstream write; // output file stream
		filename.append(".replace"); // We add extension to change the name of the file being read.
		write.open(filename.c_str());
		if (write.is_open())
		{
			while (getline(read, buffer)) // It reads line by line.
			{
				buffer = replace(buffer, argv[1], argv[2]);
				write << buffer << std::endl; // We direct the arguments that must be written to the ofstream structure to write to the file we open.
			}
			write.close();
		}
		else
			read.close();
	}
	return (0);
}
