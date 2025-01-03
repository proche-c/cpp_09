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

#include "RPN.hpp"

int main(int argc, char **args)
{
	if (argc == 2)
	{
		try
		{
			RPN	rpn(args[1]);
			rpn.evaluate();
		}
		catch(const RPN::DivisionByZeroException & e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const RPN::BadInputException & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: argument needed."  << std::endl;

	return (0);
}