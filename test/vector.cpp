/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:31:25 by agautier          #+#    #+#             */
/*   Updated: 2021/12/22 17:47:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Test.hpp"
#include <iostream>
#include <stdint.h>
#include <vector>

// Member functions

bool test_default_constructor(void) {
	ft::Vector< int > ftvec;
	(void)ftvec;
	return (true);
}

bool test_fill_constructor(void) {
	std::size_t		  n	  = 10;
	int				  val = 42;
	ft::Vector< int > ftvec(n, val);
	(void)ftvec;
	return (true);
}

// bool test_range_constructor(void) {
//	std::vector< int > stdvec(10, 42);
//	ft::Vector< int > ftvec(stdvec.begin(), stdvec.end());
//	(void)ftvec;
//	return (true);
// }

bool test_copy_constructor(void) {
	ft::Vector< int > ftvec;
	ft::Vector< int > ftvec2(ftvec);
	(void)ftvec2;
	return (true);
}

// Capacity

// bool test_default_constructor_empty(void) {
//	ft::Vector< int > ftvec;
//	std::vector< int > stdvec;
//
//	assert_eq(ftvec.empty(), stdvec.empty());
// }
//
// bool test_default_constructor_size(void) {
//	ft::Vector< int > ftvec;
//	std::vector< int > stdvec;
//
//	assert_eq(ftvec.size(), stdvec.size());
// }

bool test_vector(void) {
	Test test("Vector");

	// Member functions
	test.registerTest(&test_default_constructor);
	test.registerTest(&test_fill_constructor);
	// test.registerTest(&test_range_constructor);	// TODO:
	test.registerTest(&test_copy_constructor);

	// Iterators
	// Capacity
	// test.registerTest(&test_default_constructor_size);
	// test.registerTest(&test_default_constructor_empty);

	// Element access
	// Modifiers
	// Allocator

	// ft::Vector< int > second(4, 100); // four ints with value 100
	// ft::Vector< int > third(second.begin(),
	//						second.end()); // iterating throuth second
	// ft::Vector< int > fourth(third); // a copy of third

	return (test.run());
}
