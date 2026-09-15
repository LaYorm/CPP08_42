/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:32:18 by yorimek           #+#    #+#             */
/*   Updated: 2026/09/15 12:46:11 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Not_Found_Exception : public std::exception
{
	public :
		virtual const char *what() const throw()
		{
			return ("No occurence has been found\n");
		}
};

template <typename T>
void	easyfind(T &container, int b)
{
	typename T::iterator it = std::find(container.begin(), container.end(), b);
	if (it != container.end())
	{
		std::cout << "The first occurence has been found: " << *it << std::endl;
		return ;
	}
	else
	{
		throw Not_Found_Exception();
	}
}

#endif 