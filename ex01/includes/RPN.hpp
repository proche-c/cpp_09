/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <stack>
#include <string>
#include <exception>
#include <iostream>
#include <sstream>

class RPN
{
	public:
		class 	DivisionByZeroException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class 	BadInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		RPN(void);
		RPN(std::string const & input);
		RPN(RPN const & src);
		~RPN(void);

		RPN & operator=(RPN const & src);

		void	evaluate(void);

	private:
	
		std::stack<int>	_data;
		std::string		_input;

		void	calculate(std::string &op);
};

#endif
