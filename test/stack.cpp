#include "Test.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include <stack>

/* Member functions */
static bool test_default_constructor(void) {
	ft::stack<int> test;
	return (true);
}
static bool test_default_constructor_explicit_container(void) {
	ft::vector<int> vec;
	ft::stack<int> test(vec);
	return (true);
}
static bool test_copy_constructor(void) {
	ft::stack<int> test;
	ft::stack<int> test2(test);
	return (true);
}
static bool test_assignment_operator(void) {
	ft::stack<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	ft::stack<int> test2 = test;
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
	ft::stack<int> test;
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
	ft::stack<int> test;
	test.push(1);
	ft::stack<int>::const_reference nbr = test.top();
	if (nbr != 1)
		return (false);
	return (true);
}

/* Capacity */
static bool test_empty(void) {
	ft::stack<int> test;
	if (!test.empty())
		return (false);
	test.push(1);
	if (test.empty())
		return (false);
	return (true);
}
static bool test_size(void) {
	ft::stack<int> test;
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
	ft::stack<std::string>test;
	test.push("1");
	test.push("2");
	if (test.size() != 2 || test.top() != "2")
		return (false);
	return (true);
}
static bool test_pop(void) {
	ft::stack<std::string>test;
	test.push("1");
	test.push("2");
	test.pop();
	if (test.size() != 1 || test.top() != "1")
		return (false);
	return (true);
}

/* Non-member functions */
static bool test_operator_equal_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::stack< char > s(vec);
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s == s2, true);
}
static bool test_operator_equal_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::stack< char > s(vec);
	ft::vector< char > vec2(9, 'a');
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s == s2, false);
}
static bool test_operator_different_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(9, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	vec2.insert(vec2.begin() + vec2.size() / 2, 'b');
	ltest_assert_eq(s != s2, true);
}
static bool test_operator_different_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s != s2, false);
}
static bool test_operator_less_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(15, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s < s2, true);
}
static bool test_operator_less_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s < s2, false);
}
static bool test_operator_less_equal_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s <= s2, true);
}
static bool test_operator_less_equal_false(void) {
	ft::vector< char > vec(15, 'a');
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s <= s2, false);
}
static bool test_operator_great_true(void) {
	ft::vector< char > vec(15, 'a');
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s > s2, true);
}
static bool test_operator_great_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s > s2, false);
}
static bool test_operator_great_equal_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s >= s2, true);
}
static bool test_operator_great_equal_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(15, 'a');
	ft::stack< char > s(vec);
	ft::stack< char > s2(vec2);
	ltest_assert_eq(s >= s2, false);
}

bool test_stack(void) {
	Test t("Stack");

	/* Member functions */
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Default constructor explicit container", &test_default_constructor_explicit_container);
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
