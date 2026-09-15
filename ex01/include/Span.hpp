/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:44:19 by yorimek           #+#    #+#             */
/*   Updated: 2026/09/15 17:37:40 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int		_max_size;
		std::vector<int>	_number;

	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span &copy);
		Span	&operator=(const Span &other);
		void	addNumber(int	nb);
		int		shortestSpan();
		int		longestSpan();

	class OverMaxSize : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return("This Span already contain or will contain the maximum amount of number !");
			}
	};

	class SpanTooSmall : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return("This Span is too small, no span can be found !");
			}
	};
	
	template <typename Iterator>
	void	addRange(Iterator begin, Iterator end)
	{
		if (static_cast<size_t>(end - begin) > this->_max_size - this->_number.size())
			throw OverMaxSize();
		else
			this->_number.insert(this->_number.end(), begin, end);
	}
};

#endif