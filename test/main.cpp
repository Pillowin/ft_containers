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

