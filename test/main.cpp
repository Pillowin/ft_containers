#include "Test.hpp"
#include <stdlib.h>

bool test_vector(void);
bool test_vector_iterator(void);
bool test_vector_const_iterator(void);
bool test_reverse_iterator(void);

int main(void) {
	bool passed = true;

	if (!test_vector())
		passed &= false;
	if (!test_vector_iterator())
		passed &= false;
	if (!test_vector_const_iterator())
		passed &= false;
	if (!test_reverse_iterator())
		passed &= false;
	return (passed ? EXIT_SUCCESS : EXIT_FAILURE);
}
