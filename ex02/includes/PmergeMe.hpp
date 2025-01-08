/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <vector>
#include <list>
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>

class PmergeMe
{
	public:
		class 	BadInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class 	OutOfIntLimitsException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		PmergeMe(void);
		PmergeMe(std::string const input);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);

		PmergeMe & operator=(PmergeMe const & src);

		void	sortVector(void);
		void	sortList(void)
;
	private:
	
		std::vector<int>	_dataVector;
		std::list<int>		_dataList;
		std::string const	_input;

};

#endif
