/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char *PmergeMe::BadInputException::what() const throw()
{
    return "Error: bad input";
}

const char *PmergeMe::OutOfIntLimitsException::what() const throw()
{
    return "Error: value out of int limits";
}

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(std::string const input):_input(input)
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void)
{}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
	(void)src;
    return (*this);
}

void	PmergeMe::sortVector(void)
{
	std::vector<int>	initVector;

	
	std::istringstream	stream(_input);
	std::string			element;
	int					number;
	char				*endptr;

	while(stream >> element)
	{
		number = strtol(element.c_str(), &endptr, 10);
		if (endptr == element.c_str() || number < 1)
			throw BadInputException();
		if (number > INT_MAX)
			throw OutOfIntLimitsException();
		initVector.push_back(number);		
	}

	return ;
}