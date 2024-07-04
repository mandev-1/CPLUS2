/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:40:04 by mman              #+#    #+#             */
/*   Updated: 2024/07/04 22:00:12 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void print_uppercase(const std::string& str)
{
	for (char c : str)
		std::cout << static_cast<char>(std::toupper(c));
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			print_uppercase(argv[i]);
			if (i < argc - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (0);
}




/*

Breakdown of Standard Library Components:

    <iostream>:
        std::cout: Standard output stream used to print to the console.
        std::endl: Stream manipulator used to insert a newline character and flush the stream.

    <cctype>:
        std::toupper: Function used to convert a character to its uppercase equivalent.

    <string>:
        std::string: Standard C++ string class used to manage sequences of characters.

By using only these components, the program adheres to the requirements of using only the standard library.

*/