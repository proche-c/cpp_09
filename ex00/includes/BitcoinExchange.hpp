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

class BitcoinExchange
{
	public:
		class 	FailToOpenFileException: public std::exception
		{
			virtual const char *what() const throw();
		};
		class 	BadInputException: public std::exception
		{
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
		BitcoinExchange(std::string const & filename);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & src);

	private:
		std::map<std::string, float>	_data;	
};

#endif
