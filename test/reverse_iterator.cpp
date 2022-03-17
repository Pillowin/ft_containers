#include "reverse_iterator.hpp"
#include "Test.hpp"
#include "vector.hpp"
#include "vector_const_iterator.hpp"
#include "vector_iterator.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

static bool test_constructor_default(void) {
	ft::vector< char >::reverse_iterator it;
	return (true);
}
static bool test_constructor_value(void) {
	ft::vector< char >					 vec(1, 'a');
	ft::vector< char >::reverse_iterator itr(&vec[0]);
	return (true);
}
static bool test_constructor_copy(void) {
	ft::vector< char >::reverse_iterator it;
	ft::vector< char >::reverse_iterator itr(it);
	return (true);
}
static bool test_assignment_operator(void) {
	ft::vector< char >::reverse_iterator it;
	ft::vector< char >::reverse_iterator itr = it;
	return (true);
}
static bool test_operator_star(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	std::vector< char >					 stdvec(1, 'a');
	stdvec.push_back('b');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	ltest_assert_eq(*itr, *stditr);
}
static bool test_operator_access(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	std::vector< char >					 stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	ltest_assert_eq(itr[1], stditr[1]);
}
static bool test_operator_pre_increment(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	++itr;
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	++stditr;
	ltest_assert_eq(*itr, *stditr);
}
static bool test_operator_pre_decrement(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	++itr;
	--itr;
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	++stditr;
	--stditr;
	ltest_assert_eq(*itr, *stditr);
}
static bool test_operator_post_increment(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	itr++;
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	stditr++;
	ltest_assert_eq(*itr, *stditr);
}
static bool test_operator_post_decrement(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	++itr;
	itr--;
	std::vector< char > stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	++stditr;
	stditr--;
	ltest_assert_eq(*itr, *stditr);
}
static bool test_operator_addition(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	std::vector< char >					 stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	ltest_assert_eq(*(itr + 2), *(stditr + 2));
}
static bool test_operator_substraction(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin() + 3;
	std::vector< char >					 stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin() + 3;
	ltest_assert_eq(*(itr - 2), *(stditr - 2));
}
static bool test_operator_addition_equal(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin();
	std::vector< char >					 stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin();
	itr += 2;
	stditr += 2;
	ltest_assert_eq(*(itr), *(stditr));
}
static bool test_operator_substraction_equal(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	ft::vector< char >::reverse_iterator itr = vec.rbegin() + 3;
	std::vector< char >					 stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	std::vector< char >::reverse_iterator stditr = stdvec.rbegin() + 3;
	itr -= 2;
	stditr -= 2;
	ltest_assert_eq(*itr, *stditr);
}

/* Non member functions */
static bool test_nm_operator_equal_true(void) {
	ft::vector< char >					 vec(2, 'a');
	ft::vector< char >::reverse_iterator itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator itr2 = vec.rend() - 2;
	ltest_assert(itr == itr2);
}

static bool test_nm_operator_equal_false(void) {
	ft::vector< char >					 vec(2, 'a');
	ft::vector< char >::reverse_iterator itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator itr2 = vec.rend() - 1;
	ltest_assert_n(itr == itr2);
}
static bool test_nm_operator_different_true(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 1;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 1;
	ltest_assert_eq(itr != itr2, stditr != stditr2);
}
static bool test_nm_operator_different_false(void) {
	ft::vector< char >					 vec(2, 'a');
	ft::vector< char >::reverse_iterator itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator itr2 = vec.rend() - 2;
	ltest_assert_n(itr != itr2);
}
static bool test_nm_operator_less_true(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 1;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 1;
	ltest_assert_eq(itr < itr2, stditr < stditr2);
}
static bool test_nm_operator_less_false(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 2;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 2;
	ltest_assert_eq(itr < itr2, stditr < stditr2);
}
static bool test_nm_operator_less_equal_true(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 2;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 2;
	ltest_assert_eq(itr <= itr2, stditr <= stditr2);
}
static bool test_nm_operator_less_equal_false(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 1;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 1;
	ltest_assert_eq(itr <= itr2, stditr <= stditr2);
}
static bool test_nm_operator_great_true(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 1;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 1;
	ltest_assert_eq(itr > itr2, stditr > stditr2);
}
static bool test_nm_operator_great_false(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 1;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 1;
	ltest_assert_eq(itr2 < itr, stditr2 < stditr);
}
static bool test_nm_operator_great_equal_true(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 2;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 2;
	ltest_assert_eq(itr > itr2, stditr > stditr2);
}
static bool test_nm_operator_great_equal_false(void) {
	ft::vector< char >					  vec(2, 'a');
	ft::vector< char >::reverse_iterator  itr  = vec.rbegin();
	ft::vector< char >::reverse_iterator  itr2 = vec.rend() - 1;
	std::vector< char >					  stdvec(2, 'a');
	std::vector< char >::reverse_iterator stditr  = stdvec.rbegin();
	std::vector< char >::reverse_iterator stditr2 = stdvec.rend() - 1;
	ltest_assert_eq(itr2 >= itr, stditr2 >= stditr);
}

bool test_reverse_iterator(void) {
	Test t("Reverse iterator");

	/* Member functions */
	t.registerTest("Default constructor", &test_constructor_default);
	t.registerTest("Value constructor", &test_constructor_value);
	t.registerTest("Copy constructor", &test_constructor_copy);
	t.registerTest("Assignment operator", &test_assignment_operator);
	t.registerTest("Operator *", &test_operator_star);
	t.registerTest("Operator []", &test_operator_access);
	t.registerTest("Operator ++", &test_operator_pre_increment);
	t.registerTest("Operator --", &test_operator_pre_decrement);
	t.registerTest("Operator post ++", &test_operator_post_increment);
	t.registerTest("Operator post --", &test_operator_post_decrement);
	t.registerTest("Operator +", &test_operator_addition);
	t.registerTest("Operator -", &test_operator_substraction);
	t.registerTest("Operator +=", &test_operator_addition_equal);
	t.registerTest("Operator -=", &test_operator_substraction_equal);

	/* Non member functions */
	t.registerTest("Non member operator == true", &test_nm_operator_equal_true);
	t.registerTest("Non member operator == false",
				   &test_nm_operator_equal_false);
	t.registerTest("Non member operator != true",
				   &test_nm_operator_different_true);
	t.registerTest("Non member operator != false",
				   &test_nm_operator_different_false);
	t.registerTest("Non member operator < true", &test_nm_operator_less_true);
	t.registerTest("Non member operator < false", &test_nm_operator_less_false);
	t.registerTest("Non member operator <= true",
				   &test_nm_operator_less_equal_true);
	t.registerTest("Non member operator <= false",
				   &test_nm_operator_less_equal_false);
	t.registerTest("Non member operator > true", &test_nm_operator_great_true);
	t.registerTest("Non member operator > false",
				   &test_nm_operator_great_false);
	t.registerTest("Non member operator >= true",
				   &test_nm_operator_great_equal_true);
	t.registerTest("Non member operator >= false",
				   &test_nm_operator_great_equal_false);
	return (t.run());
}
