/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>


class BitcoinExchange
{
	public:
		class 	FailToOpenFileException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class 	BadInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class 	NegativeNumberException: public std::exception
		{
			virtual const char *what() const throw();
		};
		class 	LargeNumberException: public std::exception
		{
			virtual const char *what() const throw();
		};
		BitcoinExchange(void);
		BitcoinExchange(std::string const & fileName);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & src);

		void	evaluate(char *inputFileName);

		// static	std::string	& cleanLine(std::string	& line);
		// static	bool	isValidDate(std::string &date);

	private:
	
		std::map<std::string, float>	_data;
		std::string						_firstData;
		static	std::string	& cleanLine(std::string	& line);
		static	bool	isValidDate(std::string &date);
		static	bool	isValidValue(std::string str);
};

#endif
