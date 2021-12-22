/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:09:54 by agautier          #+#    #+#             */
/*   Updated: 2021/12/22 17:48:48 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include <cstdlib>
#include <string>

bool test_vector(void);

// bool test_assert(void) { assert(true); }
// bool test_assert_eq(void) {
//	assert_eq(std::string("toto"), std::string("toto"));
// }
// bool test_assert_ne(void) { assert_ne(42, 12); }

int main(void) {
	// test.registerTest(&test_assert);
	// test.registerTest(&test_assert_eq);
	// test.registerTest(&test_assert_ne);
	if (!test_vector())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

