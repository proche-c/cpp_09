/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char *RPN::DivisionByZeroException::what() const throw()
{
    return "Error: division by zero.";
}

const char *RPN::BadInputException::what() const throw()
{
    return "Error: bad input";
}

RPN::RPN(void)
{}

RPN::RPN(std::string const & input):_input(input)
{
	return ;
}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN::~RPN(void)
{}

RPN & RPN::operator=(RPN const & src)
{
	(void)src;
    return (*this);
}

void	RPN::evaluate(void)
{
	std::istringstream stream(_input);
	std::string	element;

	while(stream >> element)
	{
		if (element.size() != 1)
			throw RPN::BadInputException();
		if (element >= "0" && element <= "9")
			this->_data.push(static_cast<int>(element[0] - '0'));
		else if (element == "+" || element == "-" || element == "*"
			|| element == "/")
		{
			if (_data.size() < 2)
				throw RPN::BadInputException();
			this->calculate(element);
		}
		else
			throw RPN::BadInputException();
	}
	if (_data.size() != 1)
		throw RPN::BadInputException();
	while (!_data.empty())
	{
        std::cout << _data.top();
        _data.pop();
    }
	std::cout << std::endl;
}

void	RPN::calculate(std::string &op)
{
	int	n;
	int	result;

	n = _data.top();
	_data.pop();
	if (op == "+")
		result = _data.top() + n;
	else if (op == "-")
		result = _data.top() -n;
	else if (op == "*")
		result = _data.top() * n;
	else if (op == "/")
	{
		if (n == 0)
			throw RPN::DivisionByZeroException();
		result = _data.top() / n;
	}
	_data.pop();
	_data.push(result);
}