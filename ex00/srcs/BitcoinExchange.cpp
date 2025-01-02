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
    return "Error: could not open file to generate map.";
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

BitcoinExchange::BitcoinExchange(std::string const & fileName)
{
    std::ifstream file(fileName.c_str());
	std::string line;
	std::string date;
	float value;
	
	if (!file.is_open())
		throw BitcoinExchange::FailToOpenFileException();
	while (std::getline(file, line))
	{
		date = line.substr(0, line.find(','));
		if (date == "date")
			continue;
		value = atof((line.substr(line.find(',') + 1)).c_str());
		this->_data.insert(std::pair<std::string, float>(date, value));
	}
	std::map<std::string, float>::iterator	it = this->_data.begin();
	this->_firstData = it->first;
	// std::map<std::string, float>::iterator	ite = this->_data.end();
	// for (it = this->_data.begin(); it!= ite; ++it)
	// {
	// 	std::cout << it->first << "-" << it->second << std::endl;
	// }
	// std::string  line2 = "   date  		| value";
	// std::string  lineCleaned = cleanLine(line2);
	// // lineCleaned = cleanLine(line2);
	// std::cout << lineCleaned << std::endl;
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

void	BitcoinExchange::evaluate(char *inputFileName)
{
	std::ifstream inputFile(inputFileName);
	std::string	line;
	std::string	rawLine;
	std::string date;
	float	value;

	if (!inputFile.is_open())
		throw BitcoinExchange::FailToOpenFileException();
	std::getline(inputFile, line);
	rawLine = cleanLine(line);
	if (rawLine != "date|value")
		throw BitcoinExchange::BadInputException();
	while (std::getline(inputFile, line))
	{
		rawLine = cleanLine(line);
		date = rawLine.substr(0, rawLine.find('|'));
		if (isValidDate(date))
		{
			if (isValidValue(rawLine.substr(rawLine.find('|') + 1)))
			{
				value = atof((rawLine.substr(rawLine.find('|') + 1)).c_str());
				std::map<std::string, float>::iterator	it = this->_data.lower_bound(date);
				if (it == this->_data.end())
				{
					it--;
					std::cout << "no records of price after " << it->first << std::endl;
				}
				else if (it != this->_data.end() && it->first == date)
				{
					std::cout << date << " => " << value << " = " << value * it->second << std::endl;
				}
				else if (it != this->_data.begin())
				{
					it--;
					std::cout << date << " => " << value << " = " << value * it->second << std::endl;
				}
				else
				{
					std::cout << "no records of price before " << this->_firstData << std::endl;
				}
			}
		}
	}
	
}

std::string	& BitcoinExchange::cleanLine(std::string	& line)
{
	std::size_t	found = line.find("\t");
	while (found != std::string::npos)
	{
		line.erase(found, 1);
		found = line.find("\t");
	}
	std::size_t	found2 = line.find(" ");
	while (found2 != std::string::npos)
	{
		line.erase(found2, 1);
		found2 = line.find(" ");
	}
	std::size_t	found3 = line.find("\n");
	while (found3 != std::string::npos)
	{
		line.erase(found3, 1);
		found3 = line.find(" ");
	}
	return line;
}

bool	BitcoinExchange::isValidDate(std::string &date)
{
	int	year;
	int	month;
	int	day;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	try
	{
		year = atoi(date.substr(0, 4).c_str());
		month = atoi(date.substr(5, 2).c_str());
		day = atoi(date.substr(8, 2).c_str());
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    static const int daysByMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDays = daysByMonth[month - 1];
	if (day > maxDays)
	{
		std::cout << "Error: bad input => " << date << std::endl;
        return false;		
	}
	return true;
}

bool	BitcoinExchange::isValidValue(std::string str)
{
	float value;

	try
	{
		value = atof(str.c_str());
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: bad input => " << str << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}