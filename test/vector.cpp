/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:31:25 by agautier          #+#    #+#             */
/*   Updated: 2021/12/19 21:16:09 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <iostream>
#include <stdint.h>

bool test_vector(void) {
	std::cout << "---------------------- Testing Vector ----------------------"
			  << std::endl
			  << std::endl;

	uint8_t failed = 0;
	uint8_t passed = 0;
	(void)failed;
	(void)passed;

	ft::Vector< int > first; // empty vector of ints
	(void)first;
	// ft::Vector< int > second(4, 100); // four ints with value 100
	// ft::Vector< int > third(second.begin(),
	//						second.end()); // iterating throuth second
	// ft::Vector< int > fourth(third); // a copy of third

	return (false);
}
