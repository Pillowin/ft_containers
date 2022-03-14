#include "vector.hpp"
#include "Test.hpp"
#include <iostream>
#include <stdint.h>
#include <vector>

/* Member types */

/* Member functions */
bool test_default_constructor(void) {
	ft::vector< int > vec;
	if (vec.size() || vec.capacity())
		return (false);
	return (true);
}
bool test_fill_constructor(void) {
	ft::vector< char > vec(10, 'a');
	if (vec.size() != 10 || vec.capacity() != 10 || vec.at(0) != 'a'
		|| vec.at(9) != 'a')
		return (false);
	return (true);
}
bool test_range_constructor(void) {
	std::vector< int > stdvec(1, 42);
	stdvec.push_back(43);
	ft::vector< int > vec(stdvec.begin(), stdvec.end());
	if (vec.empty() || vec.capacity() != 2 || vec.at(0) != *(stdvec.begin())
		|| vec.at(1) != *(stdvec.end() - 1))
		return (false);
	return (true);
}
bool test_copy_constructor(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(vec);
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assignment_operator(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2 = vec;
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assignment_operator_reused(void) {
	ft::vector< char > vec(10, 'a');
	ft::vector< char > vec2(1, 'b');
	vec2 = vec;
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assignment_operator_real(void) {
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
bool test_assign_fill(void) {
	ft::vector< char > vec;
	vec.assign(10, 'a');
	if (vec.size() != 10 || vec.capacity() != 10 || vec.at(0) != 'a'
		|| vec.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assign_range(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2;
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assign_range_reused_bigger(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2(100, 'b');
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 100 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_assign_range_reused_smaller(void) {
	std::vector< char > vec(10, 'a');
	ft::vector< char >	vec2(1, 'b');
	vec2.assign(vec.begin(), vec.end());
	if (vec2.size() != 10 || vec2.capacity() != 10 || vec2.at(0) != 'a'
		|| vec2.at(9) != 'a')
		return (false);
	return (true);
}
bool test_get_allocator(void) {
	assert_eq(std::allocator< char >(), std::vector< char >().get_allocator());
}

/* Access */
bool test_at_single(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.at(0);
	assert_eq(c, 'a');
}
/*
bool test_at_push_back(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char&			   c = vec.at(1);
	assert_eq(c, 'b');
}
*/
bool test_const_at_single(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.at(0);
	assert_eq(c, 'a');
}
/*
bool test_const_at_push_back(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char const&			   c = vec.at(1);
	assert_eq(c, 'b');
}
*/
bool test_access_operator_zero(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec[0];
	assert_eq(c, 'a');
}
/*
bool test_access_operator_one(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char& c = vec[1];
	assert_eq(c, 'b');
}
*/
bool test_const_access_operator_zero(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec[0];
	assert_eq(c, 'a');
}
/*
bool test_const_access_operator_one(void) {
	ft::vector< char > vec(1, 'a');
	vec.push_back('b');
	char const& c = vec[1];
	assert_eq(c, 'b');
}
*/
bool test_front(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.front();
	assert_eq(c, 'a');
}
bool test_const_front(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.front();
	assert_eq(c, 'a');
}
bool test_back(void) {
	ft::vector< char > vec(1, 'a');
	char&			   c = vec.back();
	assert_eq(c, 'a');
}
bool test_const_back(void) {
	ft::vector< char > vec(1, 'a');
	char const&		   c = vec.back();
	assert_eq(c, 'a');
}
bool test_data(void) {
	ft::vector< char > vec(1, 'a');
	char*			   c = vec.data();
	assert_eq(*c, 'a');
}
bool test_const_data(void) {
	ft::vector< char > vec(1, 'a');
	char const*		   c = vec.data();
	assert_eq(*c, 'a');
}

/* Capacity */
bool test_empty_true(void) { assert_eq(ft::vector< int >().empty(), true); }
bool test_empty_false(void) {
	assert_eq(ft::vector< char >(10, 'a').empty(), false);
}
bool test_size_null(void) { assert_eq(ft::vector< int >().size(), 0); }
bool test_size_positive(void) {
	assert_eq(ft::vector< char >(10, 'a').size(), 10);
}
bool test_size_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	assert_eq(vec.size(), 9);
}
bool test_max_size(void) {
	assert_eq(ft::vector< int >().max_size(), std::vector< int >().max_size());
}
bool test_capacity_null(void) { assert_eq(ft::vector< char >().capacity(), 0); }
bool test_capacity_positive(void) {
	assert_eq(ft::vector< char >(10, 'a').capacity(), 10);
}
bool test_capacity_pop_back(void) {
	ft::vector< char > vec(10, 'a');
	vec.pop_back();
	assert_eq(vec.capacity(), 10);
}

bool test_vector(void) {
	Test vector_test("Vector");

	/* Member types */

	// vector_test.registerTest("Member types", &test_member_types);

	/* Member functions */
	vector_test.registerTest("Default constructor", &test_default_constructor);
	vector_test.registerTest("Fill constructor", &test_fill_constructor);
	vector_test.registerTest("Range constructor", &test_range_constructor);
	vector_test.registerTest("Copy constructor", &test_copy_constructor);
	vector_test.registerTest("Assignment operator", &test_assignment_operator);
	vector_test.registerTest("Assignment operator reused",
							 &test_assignment_operator_reused);
	vector_test.registerTest("Assignment operator real",
							 &test_assignment_operator_real);
	vector_test.registerTest("Assign fill", &test_assign_fill);
	vector_test.registerTest("Assign range", &test_assign_range);
	vector_test.registerTest("Assign range reuse bigger",
							 &test_assign_range_reused_bigger);
	vector_test.registerTest("Assign range reuse smaller",
							 &test_assign_range_reused_smaller);
	vector_test.registerTest("Get allocator", &test_get_allocator);

	/* Access */
	vector_test.registerTest("At 0", &test_at_single);
	// vector_test.registerTest("At 1", &test_at_push_back);
	vector_test.registerTest("Const at 0", &test_const_at_single);
	// vector_test.registerTest("Const at 1", &test_at_push_back);
	vector_test.registerTest("Access operator at 0",
							 &test_access_operator_zero);
	// vector_test.registerTest("Access operator at 1",
	// &test_access_operator_one);
	vector_test.registerTest("Const access operator at 0",
							 &test_const_access_operator_zero);
	// vector_test.registerTest("Const access operator at 1",
	// &test_const_access_operator_one);
	vector_test.registerTest("Front", &test_front);
	vector_test.registerTest("Const front", &test_const_front);
	vector_test.registerTest("Back", &test_back);
	vector_test.registerTest("Const back", &test_const_back);
	vector_test.registerTest("Data", &test_data);
	vector_test.registerTest("Const data", &test_const_data);

	/* Capacity */
	vector_test.registerTest("Empty true", &test_empty_true);
	vector_test.registerTest("Empty false", &test_empty_false);
	vector_test.registerTest("Size null", &test_size_null);
	vector_test.registerTest("Size positive", &test_size_positive);
	vector_test.registerTest("Size pop back", &test_size_pop_back);
	vector_test.registerTest("Max size", &test_max_size);
	vector_test.registerTest("Capacity null", &test_capacity_null);
	vector_test.registerTest("Capacity positive", &test_capacity_positive);
	vector_test.registerTest("Capacity pop back", &test_capacity_pop_back);

	return (vector_test.run());
}
