/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:31:25 by agautier          #+#    #+#             */
/*   Updated: 2022/01/04 19:55:21 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "Test.hpp"
#include <iostream>
#include <stdint.h>
#include <vector>

/* Member types */

bool test_member_types(void) {
	ft::vector< int >::iterator it;

	(void)it;
	// TODO:
	return (true);
}

/* Member functions */

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

/* Capacity */

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
	Test vector_test("Vector");

	/* Member types */

	vector_test.registerTest("Member types", &test_member_types);

	/* Member functions */

	vector_test.registerTest("Default constructor", &test_default_constructor);
	vector_test.registerTest("Fill constructor", &test_fill_constructor);
	// vector_test.registerTest(&test_range_constructor);	// TODO:
	vector_test.registerTest("Copy constructor", &test_copy_constructor);

	/* Capacity */

	// vector_test.registerTest(&test_default_constructor_size);
	// vector_test.registerTest(&test_default_constructor_empty);

	return (vector_test.run());
}
