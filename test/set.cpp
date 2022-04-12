#include "set.hpp"
#include "Test.hpp"
#include <functional>
#include <iostream>
#include <set>
#include <string>

#ifndef NS
#define NS ft
#endif

/* Member functions */
static bool test_default_constructor(void) {
	NS::set< NS::pair< std::string, int > > m;
	(void)m;
	return (true);
}
static bool test_explicit_constructor(void) {
	NS::set< NS::pair< std::string, int > > m(std::less< std::string >);
	(void)m;
	return (true);
}
static bool test_range_constructor(void) {
	NS::set< NS::pair< std::string, int > > m1;
	m1.insert(NS::make_pair< std::string, int >("a", 1));
	m1.insert(NS::make_pair< std::string, int >("b", 2));
	m1.insert(NS::make_pair< std::string, int >("c", 3));
	NS::set< NS::pair< std::string, int > > m2(m1.begin(), m1.end());
	if (*m2.begin() != *m1.begin() || *++m2.begin() != *++m1.begin()
		|| *--m2.end() != *--m1.end())
		return (false);
	return (true);
}
static bool test_copy_constructor(void) {
	NS::set< NS::pair< std::string, int > > m1;
	m1.insert(NS::make_pair< std::string, int >("a", 1));
	m1.insert(NS::make_pair< std::string, int >("b", 2));
	m1.insert(NS::make_pair< std::string, int >("c", 3));
	NS::set< NS::pair< std::string, int > > m2(m1);
	if (*m2.begin() != *m1.begin() || *++m2.begin() != *++m1.begin()
		|| *--m2.end() != *--m1.end())
		return (false);
	return (true);
}
static bool test_assignment_operator(void) {
	NS::set< NS::pair< std::string, int > > m1;
	m1.insert(NS::make_pair< std::string, int >("a", 1));
	m1.insert(NS::make_pair< std::string, int >("b", 2));
	m1.insert(NS::make_pair< std::string, int >("c", 3));
	NS::set< NS::pair< std::string, int > > m2 = m1;
	if (*m2.begin() != *m1.begin() || *++m2.begin() != *++m1.begin()
		|| *--m2.end() != *--m1.end())
		return (false);
	return (true);
}
static bool test_get_allocator(void) {
	NS::set< NS::pair< std::string, int > > const				  m;
	NS::set< NS::pair< std::string, int > >::allocator_type const alloc
		= m.get_allocator();
	if (alloc != std::allocator< NS::pair< std::string, int > >())
		return (false);
	return (true);
}

/* Iterators */
static bool test_begin(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	m.insert(NS::make_pair< std::string, int >("b", 2));
	m.insert(NS::make_pair< std::string, int >("c", 3));
	NS::set< NS::pair< std::string, int > >::iterator begin = m.begin();
	if (begin->first != "a" || begin->second != 1)
		return (false);
	return (true);
}
static bool test_const_begin(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > > const			m_const(m.begin(), m.end());
	NS::set< NS::pair< int, int > >::const_iterator it = m_const.begin();
	if (it->first != 1 || it->second != 1)
		return (false);
	return (true);
}
static bool test_rbegin(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	m.insert(NS::make_pair< std::string, int >("b", 2));
	m.insert(NS::make_pair< std::string, int >("c", 3));
	NS::set< NS::pair< std::string, int > >::reverse_iterator rbegin
		= m.rbegin();
	if (rbegin->first != "c" || rbegin->second != 3)
		return (false);
	return (true);
}
static bool test_const_rbegin(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > > const m_const(m.begin(), m.end());
	NS::set< NS::pair< int, int > >::const_reverse_iterator it
		= m_const.rbegin();
	if (it->first != 3 || it->second != 3)
		return (false);
	return (true);
}
static bool test_end(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	m.insert(NS::make_pair< std::string, int >("b", 2));
	m.insert(NS::make_pair< std::string, int >("c", 3));
	NS::set< NS::pair< std::string, int > >::iterator end = m.end();
	--end;
	if (end->first != "c" || end->second != 3)
		return (false);
	return (true);
}
static bool test_const_end(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > > const			m_const(m.begin(), m.end());
	NS::set< NS::pair< int, int > >::const_iterator itend = m_const.end();
	--itend;
	if (itend->first != 3 || itend->second != 3)
		return (false);
	return (true);
}
static bool test_rend(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	m.insert(NS::make_pair< std::string, int >("b", 2));
	m.insert(NS::make_pair< std::string, int >("c", 3));
	NS::set< NS::pair< std::string, int > >::reverse_iterator rend = m.rend();
	--rend;
	if (rend->first != "a" || rend->second != 1)
		return (false);
	return (true);
}
static bool test_const_rend(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > > const m_const(m.begin(), m.end());
	NS::set< NS::pair< int, int > >::const_reverse_iterator itrend
		= m_const.rend();
	--itrend;
	if (itrend->first != 1 || itrend->second != 1)
		return (false);
	return (true);
}

/* Capacity */
static bool test_empty_true(void) {
	NS::set< NS::pair< std::string, int > > const m;
	ltest_assert(m.empty());
}
static bool test_empty_false(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	ltest_assert_n(m.empty());
}
static bool test_size_null(void) {
	NS::set< NS::pair< std::string, int > > const m;
	ltest_assert_eq(m.size(), 0);
}
static bool test_size_not_null(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	ltest_assert_eq(m.size(), 1);
}
static bool test_max_size(void) {
	NS::set< NS::pair< std::string, int > > const  m;
	std::set< NS::pair< std::string, int > > const stdm;
	ltest_assert_eq(m.max_size(), stdm.max_size());
}

/* Modifier */
static bool test_clear(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	m.insert(NS::make_pair< std::string, int >("b", 2));
	m.insert(NS::make_pair< std::string, int >("c", 3));
	m.clear();
	NS::set< NS::pair< std::string, int > >::iterator it = m.begin();
	if (!m.empty() || m.size() || it != m.end())
		return (false);
	return (true);
}
static bool test_insert_simple(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(NS::make_pair< std::string, int >("a", 1));
	m.insert(NS::make_pair< std::string, int >("b", 2));
	m.insert(NS::make_pair< std::string, int >("c", 3));
	if (*m.begin() != NS::make_pair< std::string, int >("a", 1)
		|| *++m.begin() != NS::make_pair< std::string, int >("b", 2)
		|| *--m.end() != NS::make_pair< std::string, int >("c", 3))
		return (false);
	return (true);
}
static bool test_insert_hint(void) {
	NS::set< NS::pair< std::string, int > > m;
	m.insert(m.begin(), NS::make_pair< std::string, int >("a", 1));
	m.insert(m.begin(), NS::make_pair< std::string, int >("b", 2));
	m.insert(m.begin(), NS::make_pair< std::string, int >("c", 3));
	if (*m.begin() != NS::make_pair< std::string, int >("a", 1)
		|| *++m.begin() != NS::make_pair< std::string, int >("b", 2)
		|| *--m.end() != NS::make_pair< std::string, int >("c", 3))
		return (false);
	return (true);
}
static bool test_insert_range(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > > m2(m.begin(), m.end());
	NS::pair< int, int > const		tmp1 = NS::make_pair< int, int >(1, 1);
	NS::pair< int, int > const		tmp2 = NS::make_pair< int, int >(2, 2);
	NS::pair< int, int > const		tmp3 = NS::make_pair< int, int >(3, 3);
	if (*m.begin() != tmp1 || *++m.begin() != tmp2 || *--m.end() != tmp3)
		return (false);
	return (true);
}
static bool test_erase_simple(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.erase(m.begin());
	if (*m.begin() != NS::make_pair< int, int >(2, 2)
		|| *++m.begin() != NS::make_pair< int, int >(3, 3) || m.size() != 2)
		return (false);
	return (true);
}
static bool test_erase_range(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.erase(m.begin(), m.end());
	if (!m.empty() || m.size())
		return (false);
	return (true);
}
static bool test_erase_key(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.erase(NS::make_pair< int, int >(2, 2));
	if (*m.begin() != NS::make_pair< int, int >(1, 1)
		|| *++m.begin() != NS::make_pair< int, int >(3, 3) || m.size() != 2)
		return (false);
	return (true);
}
static bool test_swap(void) {
	NS::set< NS::pair< int, int > > m1;
	m1.insert(NS::make_pair< int, int >(1, 1));
	m1.insert(NS::make_pair< int, int >(2, 2));
	m1.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > > oldm1(m1);
	NS::set< NS::pair< int, int > > m2;
	m2.insert(NS::make_pair< int, int >(1, 10));
	m2.insert(NS::make_pair< int, int >(2, 20));
	m2.insert(NS::make_pair< int, int >(3, 30));
	NS::set< NS::pair< int, int > > oldm2(m2);
	m1.swap(m2);
	if (*m1.begin() != *oldm2.begin() || *++m1.begin() != *++oldm2.begin()
		|| *--m1.end() != *--oldm2.end())
		return (false);
	if (*m2.begin() != *oldm1.begin() || *++m2.begin() != *++oldm1.begin()
		|| *--m2.end() != *--oldm1.end())
		return (false);
	return (true);
}

/* Lookup */
static bool test_count(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.insert(NS::make_pair< int, int >(3, 3));
	if (m.count(NS::make_pair< int, int >(2, 2)) != 1
		|| m.count(NS::make_pair< int, int >(12, 12)) != 0
		|| m.count(NS::make_pair< int, int >(3, 3)) != 1)
		return (false);
	return (true);
}
static bool test_find(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > >::iterator it
		= m.find(NS::make_pair< int, int >(1, 1));
	if (it->second != 1)
		return (false);
	it = m.find(NS::make_pair< int, int >(2, 2));
	if (it->second != 2)
		return (false);
	it = m.find(NS::make_pair< int, int >(3, 3));
	if (it->second != 3)
		return (false);
	return (true);
}
static bool test_const_find(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > >::iterator const it
		= m.find(NS::make_pair< int, int >(1, 1));
	if (it->second != 1)
		return (false);
	NS::set< NS::pair< int, int > >::iterator const it2
		= m.find(NS::make_pair< int, int >(2, 2));
	if (it2->second != 2)
		return (false);
	NS::set< NS::pair< int, int > >::iterator const it3
		= m.find(NS::make_pair< int, int >(3, 3));
	if (it3->second != 3)
		return (false);
	return (true);
}
static bool test_equal_range(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::pair< NS::set< NS::pair< int, int > >::iterator,
			  NS::set< NS::pair< int, int > >::iterator >
		p;
	p = m.equal_range(NS::make_pair< int, int >(2, 2));
	NS::set< NS::pair< int, int > >::iterator it = p.first;
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_const_equal_range(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::pair< NS::set< NS::pair< int, int > >::const_iterator,
			  NS::set< NS::pair< int, int > >::const_iterator >
		p;
	p = m.equal_range(NS::make_pair< int, int >(2, 2));
	NS::set< NS::pair< int, int > >::const_iterator it = p.first;
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_lower_bound(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > >::iterator it
		= m.lower_bound(NS::make_pair< int, int >(2, 2));
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_const_lower_bound(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > >::const_iterator it
		= m.lower_bound(NS::make_pair< int, int >(2, 2));
	if (it->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_upper_bound(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > >::iterator it
		= m.upper_bound(NS::make_pair< int, int >(2, 2));
	if (it->first != 3 || it->second != 3)
		return (false);
	return (true);
}
static bool test_const_upper_bound(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > >::const_iterator it
		= m.upper_bound(NS::make_pair< int, int >(2, 2));
	if (it->first != 3 || it->second != 3)
		return (false);
	return (true);
}

/* Observers */
static bool test_key_comp(void) {
	NS::set< int > m;
	m.insert(1);
	m.insert(2);
	m.insert(3);
	NS::set< int >::key_compare k = m.key_comp();
	if (k(1, 1) != false || k(0, 1) != true || k(1, 0) != false)
		return (false);
	return (true);
}
static bool test_value_comp(void) {
	NS::set< int > m;
	m.insert(2);
	m.insert(3);
	NS::set< int >::value_compare v = m.value_comp();
	if (v(*m.begin(), *m.begin()) != false
		|| v(*m.begin(), *++m.begin()) != true
		|| v(*++m.begin(), *m.begin()) != false)
		return (false);
	return (true);
}

/* Non-member functions */
static bool test_operator_equal(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	NS::set< NS::pair< int, int > > m2;
	m2.insert(NS::make_pair< int, int >(1, 1));
	m2.insert(NS::make_pair< int, int >(2, 2));
	m2.insert(NS::make_pair< int, int >(3, 3));
	ltest_assert(m == m2);
}
static bool test_operator_different(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.insert(NS::make_pair< int, int >(4, 4));
	NS::set< NS::pair< int, int > > m2;
	m2.insert(NS::make_pair< int, int >(1, 1));
	m2.insert(NS::make_pair< int, int >(2, 2));
	m2.insert(NS::make_pair< int, int >(3, 3));
	ltest_assert(m != m2);
}
static bool test_operator_less(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.insert(NS::make_pair< int, int >(4, 4));
	NS::set< NS::pair< int, int > > m2;
	m2.insert(NS::make_pair< int, int >(1, 1));
	m2.insert(NS::make_pair< int, int >(2, 2));
	m2.insert(NS::make_pair< int, int >(3, 3));
	ltest_assert(m2 < m);
}
static bool test_operator_less_equal(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.insert(NS::make_pair< int, int >(4, 4));
	NS::set< NS::pair< int, int > > m2;
	m2.insert(NS::make_pair< int, int >(1, 1));
	m2.insert(NS::make_pair< int, int >(2, 2));
	m2.insert(NS::make_pair< int, int >(3, 3));
	m2.insert(NS::make_pair< int, int >(4, 4));
	ltest_assert(m2 <= m);
}
static bool test_operator_more(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.insert(NS::make_pair< int, int >(4, 4));
	NS::set< NS::pair< int, int > > m2;
	m2.insert(NS::make_pair< int, int >(1, 1));
	m2.insert(NS::make_pair< int, int >(2, 2));
	m2.insert(NS::make_pair< int, int >(3, 3));
	ltest_assert(m > m2);
}
static bool test_operator_more_equal(void) {
	NS::set< NS::pair< int, int > > m;
	m.insert(NS::make_pair< int, int >(1, 1));
	m.insert(NS::make_pair< int, int >(2, 2));
	m.insert(NS::make_pair< int, int >(3, 3));
	m.insert(NS::make_pair< int, int >(4, 4));
	NS::set< NS::pair< int, int > > m2;
	m2.insert(NS::make_pair< int, int >(1, 1));
	m2.insert(NS::make_pair< int, int >(2, 2));
	m2.insert(NS::make_pair< int, int >(3, 3));
	m2.insert(NS::make_pair< int, int >(4, 4));
	ltest_assert(m >= m2);
}

bool test_set(void) {
	Test t("set");

	/* Member functions */
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Explicit constructor", &test_explicit_constructor);
	t.registerTest("Range constructor", &test_range_constructor);
	t.registerTest("Copy constructor", &test_copy_constructor);
	t.registerTest("Assignment operator", &test_assignment_operator);
	t.registerTest("Get allocator", &test_get_allocator);

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

	//* Modifiers */
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
