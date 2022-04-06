#include "Test.hpp"
#include "map.hpp"
#include "RBTree.hpp"
#include <map>
#include <string>
#include <iostream>
#include <functional>

/* Member functions */
static bool test_default_constructor(void) {
	ft::map<std::string, int> m;
	(void)m;
	return (true);
}
static bool test_explicit_constructor(void) {
	ft::map<std::string, int> m(std::less<std::string>);
	(void)m;
	return (true);
}
static bool test_range_constructor(void) {
	ft::map<std::string, int> m1;
	m1.insert(ft::make_pair<std::string, int>("a", 1));
	m1.insert(ft::make_pair<std::string, int>("b", 2));
	m1.insert(ft::make_pair<std::string, int>("c", 3));
	ft::map<std::string, int> m2(m1.begin(), m1.end());
	if (m2["a"] != 1 || m2["b"] != 2 || m2["c"] != 3)
		return (false);
	return (true);
}
static bool test_copy_constructor(void) {
	ft::map<std::string, int> m2;
	m2.insert(ft::make_pair<std::string, int>("a", 1));
	m2.insert(ft::make_pair<std::string, int>("b", 2));
	m2.insert(ft::make_pair<std::string, int>("c", 3));
	ft::map<std::string, int> m(m2);
	if (m["a"] != 1 || m["b"] != 2 || m["c"] != 3)
		return (false);
	return (true);
}
static bool test_assignment_operator(void) {
	ft::map<std::string, int> m2;
	m2.insert(ft::make_pair<std::string, int>("a", 1));
	m2.insert(ft::make_pair<std::string, int>("b", 2));
	m2.insert(ft::make_pair<std::string, int>("c", 3));
	ft::map<std::string, int> m = m2;
	if (m["a"] != 1 || m["b"] != 2 || m["c"] != 3)
		return (false);
	return (true);
}
static bool test_get_allocator(void) {
	ft::map<std::string, int> const m;
	ft::map<std::string, int>::allocator_type const toto = m.get_allocator();
	if (toto != std::allocator<ft::pair<std::string, int> >())
		return (false);
	return (true);
}

/* Element access */
static bool test_at(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	int a = m.at("a");
	int b = m.at("b");
	int c = m.at("c");
	if (a != 1 || b != 2 || c != 3)
		return (false);
	return (true);
}
static bool test_const_at(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	const int a = m.at("a");
	const int b = m.at("b");
	const int c = m.at("c");
	if (a != 1 || b != 2 || c != 3)
		return (false);
	return (true);
}
static bool test_access_operator(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	int a = m["a"];
	int b = m["b"];
	int c = m["c"];
	if (a != 1 || b != 2 || c != 3)
		return (false);
	return (true);
}
static bool test_insert_operator(void) {
	ft::map<std::string, int> m;
	m["a"] = 1;
	m["b"] = 2;
	m["c"] = 3;
	if (m["a"] != 1 || m["b"] != 2 || m["c"] != 3)
		return (false);
	return (true);
}

/* Iterators */
static bool test_begin(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	ft::map<std::string, int>::iterator begin = m.begin();
	if (begin->first != "a" || begin->second != 1)
		return (false);
	return (true);
}
static bool test_const_begin(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map< int, int > const		   m_const(m.begin(), m.end());
	ft::map< int, int >::const_iterator it = m_const.begin();
	if (it->first != 1 || it->second != 1)
		return (false);
	return (true);
}
static bool test_rbegin(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	ft::map<std::string, int>::reverse_iterator rbegin = m.rbegin();
	if (rbegin->first != "c" || rbegin->second != 3)
		return (false);
	return (true);
}
static bool test_const_rbegin(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map< int, int > const		   m_const(m.begin(), m.end());
	ft::map< int, int >::const_reverse_iterator it = m_const.rbegin();
	if (it->first != 3 || it->second != 3)
		return (false);
	return (true);
}
static bool test_end(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	ft::map<std::string, int>::iterator end = m.end();
	--end;
	if (end->first != "c" || end->second != 3)
		return (false);
	return (true);
}
static bool test_const_end(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map< int, int > const		   m_const(m.begin(), m.end());
	ft::map< int, int >::const_iterator itend = m_const.end();
	--itend;
	if (itend->first != 3 || itend->second != 3)
		return (false);
	return (true);
}
static bool test_rend(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	ft::map<std::string, int>::reverse_iterator rend = m.rend();
	--rend;
	if (rend->first != "a" || rend->second != 1)
		return (false);
	return (true);
}
static bool test_const_rend(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map< int, int > const		   m_const(m.begin(), m.end());
	ft::map< int, int >::const_reverse_iterator itrend = m_const.rend();
	--itrend;
	if (itrend->first != 1 || itrend->second != 1)
		return (false);
	return (true);
}

/* Capacity */
static bool test_empty_true(void) {
	ft::map<std::string, int> const m;
	ltest_assert(m.empty());
}
static bool test_empty_false(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	ltest_assert_n(m.empty());
}
static bool test_size_null(void) {
	ft::map<std::string, int> const m;
	ltest_assert_eq(m.size(), 0);
}
static bool test_size_not_null(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	ltest_assert_eq(m.size(), 1);
}
static bool test_max_size(void) {
	ft::map<std::string, int> const m;
	std::map<std::string, int> const stdm;
	//std::cerr << "std max size:\t" << stdm.max_size() << std::endl;
	//std::cerr << "ft max size:\t" << m.max_size() << std::endl;
	ltest_assert_eq(m.max_size(), stdm.max_size());
}
static bool test_clear(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	m.clear();
	ft::map<std::string, int>::iterator it = m.begin();
	if (!m.empty() || m.size() ||it != m.end())
		return (false);
	return (true);
}
static bool test_insert_simple(void) {
	ft::map<std::string, int> m;
	m.insert(ft::make_pair<std::string, int>("a", 1));
	m.insert(ft::make_pair<std::string, int>("b", 2));
	m.insert(ft::make_pair<std::string, int>("c", 3));
	if (m["a"] != 1 || m["b"] != 2 || m["c"] != 3)
		return (false);
	return (true);
}
static bool test_insert_hint(void) {
	ft::map<std::string, int> m;
	m.insert(m.begin(), ft::make_pair<std::string, int>("a", 1));
	m.insert(m.begin(), ft::make_pair<std::string, int>("b", 2));
	m.insert(m.begin(), ft::make_pair<std::string, int>("c", 3));
	if (m["a"] != 1 || m["b"] != 2 || m["c"] != 3)
		return (false);
	return (true);
}
static bool test_insert_range(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map< int, int > m2(m.begin(), m.end());
	if (m2[1] != 1 || m2[2] != 2 || m2[3] != 3)
		return (false);
	return (true);
}
static bool test_erase_simple(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.erase(m.begin());
	if (m[2] != 2 || m[3] != 3 || m.size() != 2)
		return (false);
	return (true);
}
static bool test_erase_range(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.erase(m.begin(), m.end());
	if (!m.empty() || m.size())
		return (false);
	return (true);
}
static bool test_erase_key(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.erase(2);
	if (m[1] != 1 || m[3] != 3 || m.size() != 2)
		return (false);
	return (true);
}
static bool test_swap(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map< int, int > m2;
	m2.insert(ft::make_pair< int, int>(1, 10));
	m2.insert(ft::make_pair< int, int>(2, 20));
	m2.insert(ft::make_pair< int, int>(3, 30));
	m.swap(m2);
	if (m[1] != 10 || m[2] != 20 || m[3] != 30)
		return (false);
	if (m2[1] != 1 || m2[2] != 2 || m2[3] != 3)
		return (false);
	return (true);
}
static bool test_count(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	if (m.count(2) != 1 || m.count(12) != 0)
		return (false);
	return (true);
}
static bool test_find(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::iterator it = m.find(1);
	if (it->second != 1)
		return (false);
	it = m.find(2);
	if (it->second != 2)
		return (false);
	it = m.find(3);
	if (it->second != 3)
		return (false);
	return (true);
}
static bool test_const_find(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::iterator const it = m.find(1);
	if (it->second != 1)
		return (false);
	ft::map<int, int>::iterator const it2 = m.find(2);
	if (it2->second != 2)
		return (false);
	ft::map<int, int>::iterator const it3 = m.find(3);
	if (it3->second != 3)
		return (false);
	return (true);
}
static bool test_equal_range(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> p;
	p = m.equal_range(2);
	ft::map<int, int>::iterator it = p.first;
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_const_equal_range(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> p;
	p = m.equal_range(2);
	ft::map<int, int>::const_iterator it = p.first;
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_lower_bound(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::iterator it = m.lower_bound(2);
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_const_lower_bound(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::const_iterator it = m.lower_bound(2);
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_upper_bound(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::iterator it = m.upper_bound(2);
	if (it->first != 3 || it->second != 3)
		return (false);
	return (true);
}
static bool test_const_upper_bound(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::const_iterator it = m.upper_bound(2);
	if (it->first != 3 || it->second != 3)
		return (false);
	return (true);
}
static bool test_key_comp(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::key_compare k = m.key_comp();
	if (k(1, 1) != false || k(0, 1) != true || k(1, 0) != false)
		return (false);
	return (true);
}
static bool test_value_comp(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map<int, int>::value_compare v = m.value_comp();
	if (v(*m.begin(), *m.begin()) != false || v(*m.begin(), *++m.begin()) != true || v(*++m.begin(), *m.begin()) != false)
		return (false);
	return (true);
}
static bool test_operator_equal(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	ft::map< int, int > m2;
	m2.insert(ft::make_pair< int, int>(1, 1));
	m2.insert(ft::make_pair< int, int>(2, 2));
	m2.insert(ft::make_pair< int, int>(3, 3));
	ltest_assert(m == m2);
}
static bool test_operator_different(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.insert(ft::make_pair< int, int>(4, 4));
	ft::map< int, int > m2;
	m2.insert(ft::make_pair< int, int>(1, 1));
	m2.insert(ft::make_pair< int, int>(2, 2));
	m2.insert(ft::make_pair< int, int>(3, 3));
	ltest_assert(m != m2);
}
static bool test_operator_less(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.insert(ft::make_pair< int, int>(4, 4));
	ft::map< int, int > m2;
	m2.insert(ft::make_pair< int, int>(1, 1));
	m2.insert(ft::make_pair< int, int>(2, 2));
	m2.insert(ft::make_pair< int, int>(3, 3));
	ltest_assert(m2 < m);
}
static bool test_operator_less_equal(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.insert(ft::make_pair< int, int>(4, 4));
	ft::map< int, int > m2;
	m2.insert(ft::make_pair< int, int>(1, 1));
	m2.insert(ft::make_pair< int, int>(2, 2));
	m2.insert(ft::make_pair< int, int>(3, 3));
	m2.insert(ft::make_pair< int, int>(4, 4));
	ltest_assert(m2 <= m);
}
static bool test_operator_more(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.insert(ft::make_pair< int, int>(4, 4));
	ft::map< int, int > m2;
	m2.insert(ft::make_pair< int, int>(1, 1));
	m2.insert(ft::make_pair< int, int>(2, 2));
	m2.insert(ft::make_pair< int, int>(3, 3));
	ltest_assert(m > m2);
}
static bool test_operator_more_equal(void) {
	ft::map< int, int > m;
	m.insert(ft::make_pair< int, int>(1, 1));
	m.insert(ft::make_pair< int, int>(2, 2));
	m.insert(ft::make_pair< int, int>(3, 3));
	m.insert(ft::make_pair< int, int>(4, 4));
	ft::map< int, int > m2;
	m2.insert(ft::make_pair< int, int>(1, 1));
	m2.insert(ft::make_pair< int, int>(2, 2));
	m2.insert(ft::make_pair< int, int>(3, 3));
	m2.insert(ft::make_pair< int, int>(4, 4));
	ltest_assert(m >= m2);
}

//ft::RBNode<ft::pair<std::string, int> >::DG_tree(m.tree.get_root());
bool test_map(void) {
	Test t("Map");

	/* Member functions */
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Explicit constructor", &test_explicit_constructor);
	t.registerTest("Range constructor", &test_range_constructor);
	t.registerTest("Copy constructor", &test_copy_constructor);
	t.registerTest("Assignment operator", &test_assignment_operator);
	t.registerTest("Get allocator", &test_get_allocator);

	/* Element access */
	t.registerTest("At", &test_at);
	t.registerTest("Const at", &test_const_at);
	t.registerTest("Access operator", &test_access_operator);
	t.registerTest("Insert operator", &test_insert_operator);

	/* Iterators */
	t.registerTest("Begin", &test_begin);
	t.registerTest("Const begin", &test_const_begin);
	t.registerTest("End", &test_end);
	t.registerTest("Const end", &test_const_end);
	t.registerTest("Rbegin", &test_rbegin);
	t.registerTest("Const rbegin", &test_const_rbegin);
	t.registerTest("Rend", &test_rend);
	t.registerTest("Const rend", &test_const_rend);

	/* Capacity */
	t.registerTest("Empty true", &test_empty_true);
	t.registerTest("Empty false", &test_empty_false);
	t.registerTest("Size 0", &test_size_null);
	t.registerTest("Size not 0", &test_size_not_null);
	t.registerTest("Max size", &test_max_size);

	/* Modifiers */
	t.registerTest("Clear", &test_clear);
	t.registerTest("Insert simple", &test_insert_simple);
	t.registerTest("Insert hint", &test_insert_hint);
	t.registerTest("Insert range", &test_insert_range);
	t.registerTest("Erase simple", &test_erase_simple);
	t.registerTest("Erase range", &test_erase_range);
	t.registerTest("Erase key", &test_erase_key);
	t.registerTest("Swap", &test_swap);

	/* Lookup */
	t.registerTest("Count", &test_count);
	t.registerTest("Find", &test_find);
	t.registerTest("Const find", &test_const_find);
	t.registerTest("Equal range", &test_equal_range);
	t.registerTest("Const equal range", &test_const_equal_range);
	t.registerTest("Lower bound", &test_lower_bound);
	t.registerTest("Const lower bound", &test_const_lower_bound);
	t.registerTest("Upper bound", &test_upper_bound);
	t.registerTest("Const upper bound", &test_const_upper_bound);

	/* Observers */
	t.registerTest("Key comp", &test_key_comp);
	t.registerTest("Value comp", &test_value_comp);

	/* Non-member functions */
	t.registerTest("Operator equal", &test_operator_equal);
	t.registerTest("Operator different", &test_operator_different);
	t.registerTest("Operator less", &test_operator_less);
	t.registerTest("Operator less equal", &test_operator_less_equal);
	t.registerTest("Operator more", &test_operator_more);
	t.registerTest("Operator more equal", &test_operator_more_equal);

	return (t.run());
}
