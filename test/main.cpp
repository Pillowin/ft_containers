#include "Test.hpp"

bool test_vector(void);
bool test_vector_iterator(void);
bool test_vector_const_iterator(void);

int main(void) {
	if (!test_vector() || !test_vector_iterator() || !test_vector_const_iterator())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
