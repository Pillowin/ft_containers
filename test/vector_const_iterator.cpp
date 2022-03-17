#include "Test.hpp"
#include "vector.hpp"
#include <iostream>
#include <string>

/* Access operator */
static bool test_operator_star(void) {
	ft::vector< char > const		   vec(1, 'a');
	ft::vector< char >::const_iterator it = vec.begin();
	ltest_assert_eq(*it, 'a');
}
static bool test_operator_index(void) {
	ft::vector< char > const vec(1, 'a');
	ltest_assert_eq(vec.begin()[0], 'a');
}

/* Increment/Decrement operators */
static bool test_operator_pre_increment(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.begin();
	ltest_assert_eq(*(++it), 'b');
}
static bool test_operator_pre_decrement(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.end();
	ltest_assert_eq(*(--it), 'b');
}
static bool test_operator_post_increment(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.begin();
	it++;
	ltest_assert_eq(*it, 'b');
}
static bool test_operator_post_decrement(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.end();
	it--;
	ltest_assert_eq(*it, 'b');
}

/* Arithmetic operators */
static bool test_operator_addition(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.begin();
	ltest_assert_eq(*(it + 1), 'b');
}
static bool test_operator_substraction(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.end() - 1;
	ltest_assert_eq(*(it - 1), 'a');
}
static bool test_operator_addition_equal(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.begin();
	it += 1;
	ltest_assert_eq(*it, 'b');
}
static bool test_operator_substraction_equal(void) {
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	ft::vector< char > const		   vec(stdvec.begin(), stdvec.end());
	ft::vector< char >::const_iterator it = vec.end() - 1;
	it -= 1;
	ltest_assert_eq(*it, 'a');
}

/* Comparaison operators */
static bool test_operator_equal(void) {
	ft::vector< char > const vec(1, 'a');
	ltest_assert_eq(vec.begin() + 1 == vec.end(), true);
}
static bool test_operator_not_equal(void) {
	ft::vector< char > const vec(1, 'a');
	ltest_assert_eq(vec.begin() != vec.end(), true);
}
static bool test_operator_less(void) {
	ft::vector< char > const vec(1, 'a');
	ltest_assert_eq(vec.begin() < vec.end(), true);
}
static bool test_operator_great(void) {
	ft::vector< char > const vec(1, 'a');
	ltest_assert_eq(vec.begin() > vec.end(), false);
}
static bool test_operator_less_equal(void) {
	ft::vector< char > const vec(1, 'a');
	ltest_assert_eq(vec.begin() <= vec.end(), true);
}
static bool test_operator_great_equal(void) {
	ft::vector< char > const vec(1, 'a');
	ltest_assert_eq(vec.begin() >= vec.end(), false);
}

bool test_vector_const_iterator(void) {
	Test t("Vector const iterator");

	/* Member functions */
	t.registerTest("Operator *", &test_operator_star);
	t.registerTest("Operator []", &test_operator_index);
	t.registerTest("Operator pre ++ ", &test_operator_pre_increment);
	t.registerTest("Operator pre -- ", &test_operator_pre_decrement);
	t.registerTest("Operator post ++ ", &test_operator_post_increment);
	t.registerTest("Operator post -- ", &test_operator_post_decrement);
	t.registerTest("Operator + ", &test_operator_addition);
	t.registerTest("Operator - ", &test_operator_substraction);
	t.registerTest("Operator += ", &test_operator_addition_equal);
	t.registerTest("Operator -= ", &test_operator_substraction_equal);
	t.registerTest("Operator == ", &test_operator_equal);
	t.registerTest("Operator != ", &test_operator_not_equal);
	t.registerTest("Operator < ", &test_operator_less);
	t.registerTest("Operator > ", &test_operator_great);
	t.registerTest("Operator <= ", &test_operator_less_equal);
	t.registerTest("Operator >= ", &test_operator_great_equal);

	return (t.run());
}
