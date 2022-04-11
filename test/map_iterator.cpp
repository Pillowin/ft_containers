#include "Test.hpp"
#include "map.hpp"

/* Constructors/Destructor */
static bool test_default_constructor(void) {
	ft::map< int, int >			  m;
	ft::map< int, int >::iterator it;
	return (true);
}
static bool test_pointer_constructor(void) {
	ft::map< int, int >				   m;
	ft::RBNode< ft::pair< int, int > > node;
	ft::map< int, int >::iterator	   it(&node);
	return (true);
}
static bool test_copy_constructor(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.begin();
	ft::map< int, int >::iterator it2(it);
	if (it2->first != it->first || it2->second != it->second)
		return (false);
	return (true);
}
static bool test_assignment_operator(void) {
	ft::map< int, int > m;
	m[1]							  = 1;
	m[2]							  = 2;
	m[3]							  = 3;
	ft::map< int, int >::iterator it  = m.begin();
	ft::map< int, int >::iterator it2 = it;
	if (it2->first != it->first || it2->second != it->second)
		return (false);
	return (true);
}

/* Access operators */
static bool test_star_operator(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.begin();
	if ((*it).first != 1 || (*it).second != 1)
		return (false);
	return (true);
}
static bool test_arrow_operator(void) {
	ft::map< int, int > m;
	m[1]							  = 1;
	m[2]							  = 2;
	m[3]							  = 3;
	ft::map< int, int >::iterator it  = m.begin();
	ft::map< int, int >::iterator it2 = it;
	if (it2->first != it->first || it2->second != it->second)
		return (false);
	return (true);
}
static bool test_get_ptr(void) {
	ft::map< int, int >				   m;
	ft::RBNode< ft::pair< int, int > > node;
	ft::map< int, int >::iterator	   it(&node);
	if (it.get_ptr() != &node)
		return (false);
	return (true);
}

/* Increment/Decrement operators */
static bool test_pre_increment_operator(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.begin();
	if ((++it)->first != 2 || it->second != 2)
		return (false);
	return (true);
}
static bool test_pre_decrement_operator(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.end();
	if ((--it)->first != 3 || it->second != 3)
		return (false);
	return (true);
}
static bool test_post_increment_operator(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.begin();
	if ((it++)->first != 1 || it->second != 2)
		return (false);
	return (true);
}
static bool test_post_decrement_operator(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.end();
	--it;
	if ((it--)->first != 3 || it->second != 2)
		return (false);
	return (true);
}

/* Comparaison operators */
static bool test_equal_operator(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.begin();
	if (!(it == m.begin()))
		return (false);
	return (true);
}
static bool test_difference_operator(void) {
	ft::map< int, int > m;
	m[1]							 = 1;
	m[2]							 = 2;
	m[3]							 = 3;
	ft::map< int, int >::iterator it = m.begin();
	if (!(it != m.end()))
		return (false);
	return (true);
}

bool test_map_iterator(void) {
	Test t("Map iterator");

	/* Constructors/Destructor */
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Pointer constructor", &test_pointer_constructor);
	t.registerTest("Copy constructor", &test_copy_constructor);
	t.registerTest("Assignment operator", &test_assignment_operator);

	/* Access operators */
	t.registerTest("Star operator", &test_star_operator);
	t.registerTest("Arrow operator", &test_arrow_operator);
	t.registerTest("Get pointer", &test_get_ptr);

	/* Increment/Decrement operators */
	t.registerTest("Pre increment operator", &test_pre_increment_operator);
	t.registerTest("Pre decrement operator", &test_pre_decrement_operator);
	t.registerTest("Post increment operator", &test_post_increment_operator);
	t.registerTest("Post decrement operator", &test_post_decrement_operator);

	/* Comparaison operators */
	t.registerTest("Equal operator", &test_equal_operator);
	t.registerTest("Difference operator", &test_difference_operator);
	return (t.run());
}
