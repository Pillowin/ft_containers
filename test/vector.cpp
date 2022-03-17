#include "vector.hpp"
#include "Test.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <stdint.h>
#include <vector>

/* Member functions */
static bool test_default_constructor(void) {
	ft::vector< int > vec;
	if (vec.size() || vec.capacity())
		return (false);
	return (true);
}
static bool test_fill_constructor(void) {
	ft::vector< char > vec(10, 'a');
	if (vec.size() != 10 || vec.capacity() != 10 || vec.at(0) != 'a'
		|| vec.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_range_constructor(void) {
	std::vector< int > stdvec(1, 42);
	stdvec.push_back(43);
	ft::vector< int > vec(stdvec.begin(), stdvec.end());
	if (vec.empty() || vec.capacity() != 2 || vec.at(0) != *(stdvec.begin())
		|| vec.at(1) != *(stdvec.end() - 1))
		return (false);
	return (true);
}
static bool test_copy_constructor(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(vec);
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_assignment_operator(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2 = vec;
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_assignment_operator_reused(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(1, 'b');
	vec2 = vec;
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_assignment_operator_real(void) {
	std::vector< char > vec(10, 'a');
	std::vector< char > vec2(789888, 'b');
	vec2.push_back('c');
	vec = vec2;
	std::vector< char > ftvec(10, 'a');
	std::vector< char > ftvec2(789888, 'b');
	ftvec2.push_back('c');
	ftvec = ftvec2;
	if (ftvec.capacity() != vec.capacity() || ftvec.size() != vec.size()
		|| vec[0] != ftvec[0] || vec[vec.size() - 1] != ftvec[ftvec.size() - 1])
		return (false);
	return (true);
}
static bool test_assign_fill(void) {
	ft::vector< char > vec;
	vec.assign(10, 'a');
	if (vec.size() != 10 || vec.capacity() != 10 || vec.at(0) != 'a'
		|| vec.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_assign_range(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2;
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_assign_range_reused_bigger(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2(100, 'b');
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 100 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_assign_range_reused_smaller(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2(1, 'b');
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
static bool test_get_allocator(void) {
	ltest_assert_eq(std::allocator< char >(), std::vector< char >().get_allocator());
}

/* Access */
static bool test_at_single(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.at(0);
	ltest_assert_eq(c, 'a');
}
static bool test_at_push_back(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char& c = vec.at(1);
	ltest_assert_eq(c, 'b');
}
static bool test_const_at_single(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.at(0);
	ltest_assert_eq(c, 'a');
}
static bool test_const_at_push_back(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char const& c = vec.at(1);
	ltest_assert_eq(c, 'b');
}
static bool test_access_operator_zero(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec[0];
	ltest_assert_eq(c, 'a');
}
static bool test_access_operator_one(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char& c = vec[1];
	ltest_assert_eq(c, 'b');
}
static bool test_const_access_operator_zero(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec[0];
	ltest_assert_eq(c, 'a');
}
static bool test_const_access_operator_one(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char const& c = vec[1];
	ltest_assert_eq(c, 'b');
}
static bool test_front(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.front();
	ltest_assert_eq(c, 'a');
}
static bool test_const_front(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.front();
	ltest_assert_eq(c, 'a');
}
static bool test_back(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.back();
	ltest_assert_eq(c, 'a');
}
static bool test_const_back(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.back();
	ltest_assert_eq(c, 'a');
}
static bool test_data(void) {
	ft::vector< char > vec(1, 'a');
	char*			   c = vec.data();
	ltest_assert_eq(*c, 'a');
}
static bool test_const_data(void) {
	ft::vector< char > vec(1, 'a');
	char const*		   c = vec.data();
	ltest_assert_eq(*c, 'a');
}

/* Iterators */
static bool test_begin(void) {
	ltest_assert_eq(*(ft::vector< char >(10, 'a').begin()), 'a');
}
static bool test_begin_incremented(void) {
	ltest_assert_eq(*(ft::vector< char >(10, 'a').begin() + 1), 'a');
}
static bool test_const_begin(void) {
	ft::vector< char> const vec (10, 'a');
	ft::vector < char >::const_iterator it = vec.begin();
	ltest_assert_eq(*it, 'a');
}
static bool test_rbegin(void) {
	std::vector<char> stdvec(1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	std::vector <char>::reverse_iterator stdit = stdvec.rbegin();
	ft::vector< char> vec (1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	ft::vector < char>::reverse_iterator it = vec.rbegin();
	ltest_assert_eq(*it, *stdit);
}
static bool test_rbegin_const(void) {
	std::vector<char> const stdvec(3, 'a');
	std::vector <char>::const_reverse_iterator stdit = stdvec.rbegin();
	ft::vector< char> const vec (3, 'a');
	ft::vector < char>::const_reverse_iterator it = vec.rbegin();
	ltest_assert_eq(*it, *stdit);
}
static bool test_end_decremented(void) {
	ltest_assert_eq(*(ft::vector< char >(10, 'a').end() - 1), 'a');
}
static bool test_const_end(void) {
	ft::vector< char> const vec (10, 'a');
	ft::vector < char>::const_iterator it = vec.end() - 1;
	ltest_assert_eq(*it, 'a');
}
static bool test_rend(void) {
	ft::vector< char> vec (1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	ft::vector < char>::reverse_iterator it = vec.rend() - 1;
	std::vector< char> stdvec (1, 'a');
	stdvec.push_back('b');
	stdvec.push_back('c');
	std::vector < char>::reverse_iterator stdit = stdvec.rend() - 1;
	ltest_assert_eq(*it, *stdit);
}
static bool test_rend_const(void) {
	ft::vector< char> const vec (3, 'a');
	ft::vector < char>::const_reverse_iterator it = vec.rend() - 1;
	std::vector< char> const stdvec (3, 'a');
	std::vector < char>::const_reverse_iterator stdit = stdvec.rend() - 1;
	ltest_assert_eq(*it, *stdit);
}

/* Capacity */
static bool test_empty_true(void) { ltest_assert_eq(ft::vector< int >().empty(), true); }
static bool test_empty_false(void) {
	ltest_assert_eq(ft::vector< char >(10, 'a').empty(), false);
}
static bool test_size_null(void) { ltest_assert_eq(ft::vector< int >().size(), 0); }
static bool test_size_positive(void) {
	ltest_assert_eq(ft::vector< char >(10, 'a').size(), 10);
}
static bool test_size_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	ltest_assert_eq(vec.size(), 9);
}
static bool test_max_size(void) {
	ltest_assert_eq(ft::vector< int >().max_size(), std::vector< int >().max_size());
}
static bool test_reserve(void) {
	ft::vector< char > vec(10, 'a');
	vec.reserve(100);
	if (vec.capacity() != 100 || vec.size() != 10 || vec[0] != 'a'
		|| vec[9] != 'a')
		return (false);
	return (true);
}
static bool test_capacity_null(void) { ltest_assert_eq(ft::vector< char >().capacity(), 0); }
static bool test_capacity_positive(void) {
	ltest_assert_eq(ft::vector< char >(10, 'a').capacity(), 10);
}
static bool test_capacity_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	ltest_assert_eq(vec.capacity(), 10);
}

/* Modifiers */
static bool test_clear(void) {
	ft::vector< char > vec(10, 'a');
	vec.clear();
	ltest_assert_eq(vec.size(), 0);
}
static bool test_insert_simple(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('d');
	vec.push_back('e');
	ft::vector< char >::iterator it = vec.insert(vec.begin() + 2, 'c');
	if (vec.size() != 5 || vec[0] != 'a' || vec[1] != 'b' || vec[2] != 'c' || vec[3] != 'd' || vec[4] != 'e'
		|| *it != 'c')
		return (false);
	return (true);
}
static bool test_insert_fill(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('d');
	vec.push_back('e');
	vec.insert(vec.begin() + 2, 3, 'c');
	if (vec.size() != 7 || vec[0] != 'a' || vec[1] != 'b' || vec[2] != 'c' || vec[3] != 'c' || vec[4] != 'c' || vec[5] != 'd' || vec[6] != 'e')
		return (false);
	return (true);
}
static bool test_insert_range(void) {
	std::vector< char > stdvec(1, 'b');
	stdvec.push_back('c');
	stdvec.push_back('d');
	ft::vector< char > vec(1, 'a');
	vec.push_back('e');
	vec.insert(vec.begin() + 1, stdvec.begin(), stdvec.end());
	if (vec.size() != 5 || vec[0] != 'a' || vec[1] != 'b' || vec[2] != 'c' || vec[3] != 'd' || vec[4] != 'e')
		return (false);
	return (true);
}
static bool test_insert_range_size_one(void) {
	std::vector<char> stdvec(5, 'a');
	ft::vector<char> ftvec(1, 'b');
	ftvec.insert(ftvec.begin(), stdvec.begin(), stdvec.end());
	if (ftvec.size() != 6 || ftvec[0] != 'a' || ftvec[4] != 'a' || ftvec[5] != 'b')
		return (false);
	return (true);
}
static bool test_erase_simple(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.erase(vec.begin() + 1);
	if (vec.size() != 2 || vec[0] != 'a' || vec[1] != 'c')
		return (false);
	return (true);
}
static bool test_erase_range(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	vec.push_back('c');
	vec.push_back('d');
	vec.push_back('e');
	vec.erase(vec.begin() + 1, vec.end() - 1);
	std::vector< char > vec2(1, 'a');
	vec2.push_back('b');
	vec2.push_back('c');
	vec2.push_back('d');
	vec2.push_back('e');
	vec2.erase(vec2.begin() + 1, vec2.end() - 1);
	if (vec.size() != vec2.size() || vec[0] != vec2[0] || vec[1] != vec2[1])
		return (false);
	return (true);
}
static bool test_push_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.push_back('b');
	if (vec.size() != 11 || vec[0] != 'a' || vec[10] != 'b')
		return (false);
	return (true);
}
static bool test_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	if (vec.size() != 9 || vec[0] != 'a' || vec[8] != 'a')
		return (false);
	return (true);
}
static bool test_resize_reduce(void) {
	ft::vector< char > vec(10, 'a');
	vec.resize(1, 'b');
	std::vector< char > stdvec(10, 'a');
	stdvec.resize(1, 'b');
	if (vec.size() != stdvec.size() || vec[0] != stdvec[0])
		return (false);
	return (true);
}
static bool test_resize_increase(void) {
	ft::vector< char > vec(10, 'a');
	vec.resize(100, 'b');
	std::vector< char > stdvec(10, 'a');
	stdvec.resize(100, 'b');
	if (vec.size() != stdvec.size() || vec[0] != stdvec[0]
		|| vec[9] != stdvec[0] || vec[10] != stdvec[10]
		|| vec[99] != stdvec[99])
		return (false);
	return (true);
}
static bool test_member_swap(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(15, 'b');
	vec.swap(vec2);
	if (vec.size() != 15 || vec[0] != 'b' || vec[14] != 'b' || vec2.size() != 10
		|| vec2[0] != 'a' || vec2[9] != 'a')
		return (false);
	return (true);
}

/* Non member */
static bool test_std_swap_overload(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(15, 'b');
	swap(vec, vec2);
	if (vec.size() != 15 || vec[0] != 'b' || vec[14] != 'b' || vec2.size() != 10
		|| vec2[0] != 'a' || vec2[9] != 'a')
		return (false);
	return (true);
}
static bool test_operator_equal_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec == vec2, true);
}
static bool test_operator_equal_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(9, 'a');
	vec2.insert(vec2.begin() + vec2.size()/2, 'b');
	ltest_assert_eq(vec == vec2, false);
}
static bool test_operator_different_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(9, 'a');
	vec2.insert(vec2.begin() + vec2.size()/2, 'b');
	ltest_assert_eq(vec != vec2, true);
}
static bool test_operator_different_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec != vec2, false);
}
static bool test_operator_less_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(15, 'a');
	ltest_assert_eq(vec < vec2, true);
}
static bool test_operator_less_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec < vec2, false);
}
static bool test_operator_less_equal_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec <= vec2, true);
}
static bool test_operator_less_equal_false(void) {
	ft::vector< char > vec(15, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec <= vec2, false);
}
static bool test_operator_great_true(void) {
	ft::vector< char > vec(15, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec > vec2, true);
}
static bool test_operator_great_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec > vec2, false);
}
static bool test_operator_great_equal_true(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(10, 'a');
	ltest_assert_eq(vec >= vec2, true);
}
static bool test_operator_great_equal_false(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(15, 'a');
	ltest_assert_eq(vec >= vec2, false);
}

bool test_vector(void) {
	Test t("Vector");

	/* Member functions */
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Fill constructor", &test_fill_constructor);
	t.registerTest("Range constructor", &test_range_constructor);
	t.registerTest("Copy constructor", &test_copy_constructor);
	t.registerTest("Assignment operator", &test_assignment_operator);
	t.registerTest("Assignment operator reused", &test_assignment_operator_reused);
	t.registerTest("Assignment operator real", &test_assignment_operator_real);
	t.registerTest("Assign fill", &test_assign_fill);
	t.registerTest("Assign range", &test_assign_range);
	t.registerTest("Assign range reuse bigger", &test_assign_range_reused_bigger);
	t.registerTest("Assign range reuse smaller", &test_assign_range_reused_smaller);
	t.registerTest("Get allocator", &test_get_allocator);

	/* Access */
	t.registerTest("At 0", &test_at_single);
	t.registerTest("At 1", &test_at_push_back);
	t.registerTest("Const at 0", &test_const_at_single);
	t.registerTest("Const at 1", &test_const_at_push_back);
	t.registerTest("Access operator at 0", &test_access_operator_zero);
	t.registerTest("Access operator at 1", &test_access_operator_one);
	t.registerTest("Const access operator at 0", &test_const_access_operator_zero);
	t.registerTest("Const access operator at 1", &test_const_access_operator_one);
	t.registerTest("Front", &test_front);
	t.registerTest("Const front", &test_const_front);
	t.registerTest("Back", &test_back);
	t.registerTest("Const back", &test_const_back);
	t.registerTest("Data", &test_data);
	t.registerTest("Const data", &test_const_data);

	/* Iterators */
	t.registerTest("Begin", &test_begin);
	t.registerTest("Begin incremented", &test_begin_incremented);
	t.registerTest("Begin const", &test_const_begin);
	t.registerTest("Rbegin", &test_rbegin);
	t.registerTest("Rbegin const", &test_rbegin_const);
	t.registerTest("End decremented", &test_end_decremented);
	t.registerTest("End const", &test_const_end);
	t.registerTest("Rend", &test_rend);
	t.registerTest("Rend const", &test_rend_const);

	/* Capacity */
	t.registerTest("Empty true", &test_empty_true);
	t.registerTest("Empty false", &test_empty_false);
	t.registerTest("Size null", &test_size_null);
	t.registerTest("Size positive", &test_size_positive);
	t.registerTest("Size pop back", &test_size_pop_back);
	t.registerTest("Max size", &test_max_size);
	t.registerTest("Reserve", &test_reserve);
	t.registerTest("Capacity null", &test_capacity_null);
	t.registerTest("Capacity positive", &test_capacity_positive);
	t.registerTest("Capacity pop back", &test_capacity_pop_back);

	/* Modifiers */
	t.registerTest("Clear", &test_clear);
	t.registerTest("Insert simple", &test_insert_simple);
	t.registerTest("Insert fill", &test_insert_fill);
	t.registerTest("Insert range ", &test_insert_range);
	t.registerTest("Insert range size 1", &test_insert_range_size_one);
	t.registerTest("Erase simple", &test_erase_simple);
	t.registerTest("Erase range", &test_erase_range);
	t.registerTest("Push back", &test_push_back);
	t.registerTest("Pop back", &test_pop_back);
	t.registerTest("Resize reduce", &test_resize_reduce);
	t.registerTest("Resize increase", &test_resize_increase);
	t.registerTest("Member swap", &test_member_swap);

	/* Modifiers */
	t.registerTest("Std swap overload", &test_std_swap_overload);
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
