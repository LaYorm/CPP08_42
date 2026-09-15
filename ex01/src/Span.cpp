/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:44:36 by yorimek           #+#    #+#             */
/*   Updated: 2026/09/15 17:22:05 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(): _max_size(0)
{
}

Span::Span(unsigned int n): _max_size(n)
{
}

Span::~Span()
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span	&Span::operator=(const Span &other)
{
	this->_max_size = other._max_size;
	this->_number = other._number;
	return (*this);
}

void	Span::addNumber(int	nb)
{
	if (this->_number.size() < this->_max_size)
		this->_number.push_back(nb);
	else
		throw OverMaxSize();
}

int	Span::shortestSpan()
{
	size_t	size_n = this->_number.size();
	int		shortest = 2147483647;

	if (size_n > 1)
	{
		std::sort(this->_number.begin(), this->_number.end());
		for (size_t i = 1; i < size_n; i++)
		{
			if (this->_number[i] - this->_number[i - 1] < shortest)
				shortest = this->_number[i] - this->_number[i - 1];
		}
	}
	else
		throw SpanTooSmall();
	return (shortest);
}

int	Span::longestSpan()
{
	size_t	size_n = this->_number.size();
	std::vector<int>::iterator min = std::min_element(this->_number.begin(), this->_number.end());
	std::vector<int>::iterator max = std::max_element(this->_number.begin(), this->_number.end());

	if (size_n <= 1)
		throw SpanTooSmall();
	return (*max - *min);
}
