#include "utility.hpp"
#include "Test.hpp"

/* Member functions */
static bool test_default_constructor(void) {
	ft::pair< int, int > p;
	return (true);
}
static bool test_value_constructor(void) {
	ft::pair< int, int > p(1, 2);
	if (p.first != 1 || p.second != 2)
		return (false);
	return (true);
}
static bool test_copy_constructor(void) {
	ft::pair< int, int > p(1, 2);
	ft::pair< int, int > p2(p);
	if (p2.first != 1 || p2.second != 2)
		return (false);
	return (true);
}
static bool test_assignment_operator(void) {
	ft::pair< int, int > p(1, 2);
	ft::pair< int, int > p2 = p;
	if (p2.first != 1 || p2.second != 2)
		return (false);
	return (true);
}

/* Non-member functions */
static bool test_make_pair(void) {
	ft::pair< int, int > p = ft::make_pair(1, 2);
	if (p.first != 1 || p.second != 2)
		return (false);
	return (true);
}
static bool test_operator_equal(void) {
	ft::pair< int, int > p(1, 2);
	ft::pair< int, int > p2(1, 2);
	ltest_assert(p == p2);
}
static bool test_operator_different(void) {
	ft::pair< int, int > p(1, 2);
	ft::pair< int, int > p2(1, 2);
	ltest_assert_n(p != p2);
}
static bool test_operator_less(void) {
	ft::pair< int, int > p(1, 2);
	ft::pair< int, int > p2(2, 4);
	ltest_assert(p < p2);
}
static bool test_operator_less_equal(void) {
	ft::pair< int, int > p(1, 2);
	ft::pair< int, int > p2(1, 2);
	ltest_assert(p <= p2);
}
static bool test_operator_more(void) {
	ft::pair< int, int > p(4, 2);
	ft::pair< int, int > p2(1, 2);
	ltest_assert(p > p2);
}
static bool test_operator_more_equal(void) {
	ft::pair< int, int > p(4, 2);
	ft::pair< int, int > p2(4, 2);
	ltest_assert(p >= p2);
}

bool test_utility(void) {
	Test t("Utility");

	/* Member functions */
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Value constructor", &test_value_constructor);
	t.registerTest("Copy constructor", &test_copy_constructor);
	t.registerTest("Assignment operator", &test_assignment_operator);

	/* Non-member functions */
	t.registerTest("Make pair", &test_make_pair);
	t.registerTest("Operator equal", &test_operator_equal);
	t.registerTest("Operator different", &test_operator_different);
	t.registerTest("Operator less", &test_operator_less);
	t.registerTest("Operator less equal", &test_operator_less_equal);
	t.registerTest("Operator more", &test_operator_more);
	t.registerTest("Operator more equal", &test_operator_more_equal);

	return (t.run());
}
