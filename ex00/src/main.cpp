/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:32:14 by yorimek           #+#    #+#             */
/*   Updated: 2026/09/15 12:48:50 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

int	main()
{
	std::vector<int>	container_vec;
	std::list<int>		container_list;

	std::cout << "=== TEST for vector ===\n";
	for (int i = 0; i < 5; i++)
		container_vec.push_back(i * 2);
	try
	{
		easyfind(container_vec, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=== TEST for list ===\n";
	for (int i = 0; i < 5; i++)
		container_list.push_back(i * 2);
	try
	{
		easyfind(container_list, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=== TEST when not found ===\n";
	try
	{
		easyfind(container_list, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}