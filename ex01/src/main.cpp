/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:45:26 by yorimek           #+#    #+#             */
/*   Updated: 2026/09/16 09:33:01 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <ctime>

int	main()
{
	std::srand(std::time(NULL));
	Span	tab_1(10000);
	std::vector<int> bigStock;

	
	tab_1.addNumber(145);
	tab_1.addNumber(189);
	for (size_t i = 0; i < 10000; i++)
	{
		bigStock.push_back(std::rand());
	}
	try
	{
		tab_1.addRange(bigStock.begin(), bigStock.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception addrange caught: " << e.what() << '\n';
	}
	try
	{
		int x = tab_1.longestSpan();
		std::cout << "Longest span is: " << x << std::endl;
		x = tab_1.shortestSpan();
		std::cout << "Shortest span is: " << x << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
}