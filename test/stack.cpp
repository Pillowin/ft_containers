#include "stack.hpp"
#include "Test.hpp"
#include "vector.hpp"
#include <stack>

#ifndef NS
#define NS ft
#endif

/* Member functions */
static bool test_default_constructor(void) {
	NS::stack< int > test;
	return (true);
}
static bool test_default_constructor_explicit_container(void) {
	NS::vector< int >					vec;
	NS::stack< int, NS::vector< int > > test(vec);
	return (true);
}
static bool test_copy_constructor(void) {
	NS::stack< int > test;
	NS::stack< int > test2(test);
	return (true);
}
static bool test_assignment_operator(void) {
	NS::stack< int > test;
	test.push(1);
	test.push(2);
	test.push(3);
	NS::stack< int > test2 = test;
	if (test2.top() != 3)
		return (false);
	test2.pop();
	if (test2.top() != 2)
		return (false);
	test2.pop();
	if (test2.top() != 1)
		return (false);
	return (true);
}

/* Element access */
static bool test_top(void) {
	NS::stack< int > test;
	test.push(1);
	test.push(2);
	test.push(3);
	if (test.top() != 3)
		return (false);
	test.pop();
	if (test.top() != 2)
		return (false);
	test.pop();
	if (test.top() != 1)
		return (false);
	return (true);
}
static bool test_const_top(void) {
	NS::stack< int > test;
	test.push(1);
	NS::stack< int >::const_reference nbr = test.top();
	if (nbr != 1)
		return (false);
	return (true);
}

/* Capacity */
static bool test_empty(void) {
	NS::stack< int > test;
	if (!test.empty())
		return (false);
	test.push(1);
	if (test.empty())
		return (false);
	return (true);
}
static bool test_size(void) {
	NS::stack< int > test;
	if (test.size() != 0)
		return (false);
	test.push(1);
	if (test.size() != 1)
		return (false);
	test.pop();
	if (test.size() != 0)
		return (false);
	return (true);
}

/* Modifiers */
static bool test_push(void) {
	NS::stack< std::string > test;
	test.push("1");
	test.push("2");
	if (test.size() != 2 || test.top() != "2")
		return (false);
	return (true);
}
static bool test_pop(void) {
	NS::stack< std::string > test;
	test.push("1");
	test.push("2");
	test.pop();
	if (test.size() != 1 || test.top() != "1")
		return (false);
	return (true);
}

/* Non-member functions */
static bool test_operator_equal_true(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s == s2, true);
}
static bool test_operator_equal_false(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::vector< char >					  vec2(9, 'a');
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s == s2, false);
}
static bool test_operator_different_true(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(9, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	vec2.insert(vec2.begin() + vec2.size() / 2, 'b');
	ltest_assert_eq(s != s2, true);
}
static bool test_operator_different_false(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s != s2, false);
}
static bool test_operator_less_true(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(15, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s < s2, true);
}
static bool test_operator_less_false(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s < s2, false);
}
static bool test_operator_less_equal_true(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s <= s2, true);
}
static bool test_operator_less_equal_false(void) {
	NS::vector< char >					  vec(15, 'a');
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s <= s2, false);
}
static bool test_operator_great_true(void) {
	NS::vector< char >					  vec(15, 'a');
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s > s2, true);
}
static bool test_operator_great_false(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s > s2, false);
}
static bool test_operator_great_equal_true(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(10, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s >= s2, true);
}
static bool test_operator_great_equal_false(void) {
	NS::vector< char >					  vec(10, 'a');
	NS::vector< char >					  vec2(15, 'a');
	NS::stack< char, NS::vector< char > > s(vec);
	NS::stack< char, NS::vector< char > > s2(vec2);
	ltest_assert_eq(s >= s2, false);
}

bool test_stack(void) {
	Test t("Stack");

	/* Member functions */
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Default constructor explicit container",
				   &test_default_constructor_explicit_container);
	t.registerTest("Copy constructor", &test_copy_constructor);
	t.registerTest("Assignment operator", &test_assignment_operator);

	/* Element access */
	t.registerTest("Top", &test_top);
	t.registerTest("Const top", &test_const_top);

	/* Capacity */
	t.registerTest("Empty", &test_empty);
	t.registerTest("Size", &test_size);

	/* Modifiers */
	t.registerTest("Push", &test_push);
	t.registerTest("Pop", &test_pop);

	/* Non-member functions */
	t.registerTest("Operator == true", &test_operator_equal_true);
	t.registerTest("Operator == false", &test_operator_equal_false);
	t.registerTest("Operator != true", &test_operator_different_true);
	t.registerTest("Operator == false", &test_operator_different_false);
	t.registerTest("Operator < true", &test_operator_less_true);
	t.registerTest("Operator < false", &test_operator_less_false);
	t.registerTest("Operator <= true", &test_operator_less_equal_true);
	t.registerTest("Operator <= false", &test_operator_less_equal_false);
	t.registerTest("Operator > true", &test_operator_great_true);
	t.registerTest("Operator > false", &test_operator_great_false);
	t.registerTest("Operator >= true", &test_operator_great_equal_true);
	t.registerTest("Operator >= false", &test_operator_great_equal_false);

	return (t.run());
}
