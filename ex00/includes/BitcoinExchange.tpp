/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

template < typename T >
const char *BitcoinExchange<T>::FailToOpenFileException::what() const throw()
{
    return "Error: could not open file.";
}

template < typename T >
const char *BitcoinExchange<T>::BadInputException::what() const throw()
{
    return "Error: bad input";
}

template < typename T >
const char *BitcoinExchange<T>::NegativeNumberException::what() const throw()
{
    return "Error: not a positive number.";
}

template < typename T >
const char *BitcoinExchange<T>::LargeNumberException::what() const throw()
{
    return "Error: too large a number.";
}

template < typename T >
BitcoinExchange<T>::BitcoinExchange(void)
{}

template < typename T >
BitcoinExchange<T>::BitcoinExchange(BitcoinExchange const & src)
{}

template < typename T >
BitcoinExchange<T>::~BitcoinExchange(void)
{}

template < typename T >
BitcoinExchange<T> & BitcoinExchange<T>::operator=(BitcoinExchange const & src)
{
    if (this != &src)
    {
        this->c = src.c;
    }
    return (*this);
}

