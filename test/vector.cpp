/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:31:25 by agautier          #+#    #+#             */
/*   Updated: 2022/01/04 12:40:34 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "Test.hpp"
#include <iostream>
#include <stdint.h>
#include <vector>

// Member functions

bool test_default_constructor(void) {
	ft::vector< int > ftvec;
	(void)ftvec;
	return (true);
}

bool test_fill_constructor(void) {
	std::size_t		  n	  = 10;
	int				  val = 42;
	ft::vector< int > ftvec(n, val);
	(void)ftvec;
	return (true);
}

// bool test_range_constructor(void) {
//	std::vector< int > stdvec(10, 42);
//	ft::vector< int > ftvec(stdvec.begin(), stdvec.end());
//	(void)ftvec;
//	return (true);
// }

bool test_copy_constructor(void) {
	ft::vector< int > ftvec;
	ft::vector< int > ftvec2(ftvec);
	(void)ftvec2;
	return (true);
}

// Capacity

// bool test_default_constructor_empty(void) {
//	ft::vector< int > ftvec;
//	std::vector< int > stdvec;
//
//	assert_eq(ftvec.empty(), stdvec.empty());
// }
//
// bool test_default_constructor_size(void) {
//	ft::vector< int > ftvec;
//	std::vector< int > stdvec;
//
//	assert_eq(ftvec.size(), stdvec.size());
// }

bool test_vector(void) {
	Test test("vector");

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

	// ft::vector< int > second(4, 100); // four ints with value 100
	// ft::vector< int > third(second.begin(),
	//						second.end()); // iterating throuth second
	// ft::vector< int > fourth(third); // a copy of third

	return (test.run());
}
