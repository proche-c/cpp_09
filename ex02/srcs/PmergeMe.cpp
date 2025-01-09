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

const char *PmergeMe::DuplicateElementException::what() const throw()
{
    return "Error: element duplicated";
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
	// int	k;
	// std::vector<int>	baseVector;
	size_t toCut;

	this->getInitVector();
	if (_initVector.size() <= 20)
	{
		toCut = _initVector.size() / 2;
	}
	else if (_initVector.size() <= 100)
	{
		toCut = static_cast<size_t>(log(static_cast<float>(_initVector.size())) / log(2));
	}
	else
	{
		toCut = static_cast<size_t>(sqrt(static_cast<float>(_initVector.size())));
	}
	std::vector<int>	baseVector(_initVector.begin(), _initVector.begin() + toCut);
	std::vector<int>	insertVector(_initVector.begin() + toCut, _initVector.end());

	std::cout << "toCut = " << toCut << std::endl;
	_baseVector = baseVector;
	sort(_baseVector.begin(), _baseVector.end());
	for (std::vector<int>::iterator it = insertVector.begin();it != insertVector.end(); it++)
	{
		std::vector<int>::iterator pos = lower_bound(_baseVector.begin(), _baseVector.end(), *it);
		_baseVector.insert(pos, 1, *it);
	}

	// this->mergeSort(0, _baseVector.size() - 1);
	for (std::vector<int>::iterator it = _baseVector.begin(); it != _baseVector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return ;
}

void	PmergeMe::getInitVector(void)
{
	std::istringstream	stream(_input);
	std::string			element;
	int					number;
	char				*endptr;
	std::vector<int>::iterator	it;

	while(stream >> element)
	{
		number = strtol(element.c_str(), &endptr, 10);
		if (endptr == element.c_str() || number < 1)
			throw BadInputException();
		if (number > INT_MAX)
			throw OutOfIntLimitsException();
		it = find(_initVector.begin(), _initVector.end(), number);
		if (it != _initVector.end())
			throw DuplicateElementException();
		_initVector.push_back(number);		
	}	
}

void	PmergeMe::mergeSort(size_t left, size_t right)
{
	if (left < right)
	{
		size_t	mid = left + (right - left) / 2;
		this->mergeSort(left, mid);
		this->mergeSort(mid + 1, right);
		this->merge(left, mid, right);
	}
}

void PmergeMe::merge(size_t left, size_t mid, size_t right)
{
	size_t	n1 = mid - left + 1;
	size_t	n2 = right - mid;

	std::vector<int>	L(n1), R(n2);

	for (size_t i = 0; i < n1; i++)
		L[i] = _baseVector[left + i];
	for (size_t j = 0; j < n2; j++)
		R[j] = _baseVector[mid + 1 + j];
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			_baseVector[k++] = L[i++];
		else
			_baseVector[k++] = R[j++];
	}
	while (i < n1)
		_baseVector[k++] = L[i++];
	while (j < n2)
		_baseVector[k++] = R[j++];
}