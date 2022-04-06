#include "Test.hpp"
#include <stdlib.h>

bool test_vector(void);
bool test_vector_iterator(void);
bool test_vector_const_iterator(void);
bool test_stack(void);
bool test_reverse_iterator(void);
bool test_utility(void);
bool test_rbtree(void);
bool test_map(void);
bool test_map_iterator(void);
bool test_map_const_iterator(void);

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
	if (!test_stack())
		passed &= false;
	if (!test_utility())
		passed &= false;
	if (!test_rbtree())
		passed &= false;
	if (!test_map())
		passed &= false;
	if (!test_map_iterator())
		passed &= false;
	if (!test_map_const_iterator())
		passed &= false;
	return (passed ? EXIT_SUCCESS : EXIT_FAILURE);
}
