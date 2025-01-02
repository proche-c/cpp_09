/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **args)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange	bce("data.csv");
			bce.evaluate(args[1]);
		}
		catch(const BitcoinExchange::FailToOpenFileException & e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const BitcoinExchange::BadInputException & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: could not open file."  << std::endl;

	return (0);
}