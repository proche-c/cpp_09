/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **args)
{
	if (argc > 1)
	{
		// char	**input;
		// std::istringstream stream(_input);
		std::string	input = "";
		int	i = 2;

		input = args[1];
		while (args[i])
		{
			input = input + " " + args[i];
			i++;
		}
		// std::cout << "input:" << input << "E" << std::endl;
		try
		{
			PmergeMe	pmergeme(input);
			pmergeme.sortVector();
		}
		catch(const PmergeMe::BadInputException & e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const PmergeMe::OutOfIntLimitsException & e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const PmergeMe::DuplicateElementException & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: argument needed."  << std::endl;

	return (0);
}