/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *BitcoinExchange::FailToOpenFileException::what() const throw()
{
    return "Error: could not open file.";
}

const char *BitcoinExchange::BadInputException::what() const throw()
{
    return "Error: bad input";
}

const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
    return "Error: not a positive number.";
}

const char *BitcoinExchange::LargeNumberException::what() const throw()
{
    return "Error: too large a number.";
}

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(std::string const & filename)
{
    std::ifstream file(filename.c_str());
	std::string line;
	std::string date;
	float value;
	
	if (!file.is_open())
		throw BitcoinExchange::FailToOpenFileException();
	while (std::getline(file, line))
	{
		date = line.substr(0, line.find(','));
		std::cout << date << std::endl;
		value = atof(line.substr(line.find(',') + 1));
		this->_data.insert(std::pair<std::string, float>(data, value));
	}
	// std::cout << date << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	(void)src;
    return (*this);
}
