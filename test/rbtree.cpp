#include "RBTree.hpp"
#include "Test.hpp"
#include <iostream>
#include <string>

/*
static bool test_default_constructor(void) {
	NS::RBTree< NS::pair< std::string, int >, std::less< std::string > > t;
	return (true);
}
static bool test_insert(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	return (true);
}
static bool test_insert_multiple_unordered(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("3"), 3));
	t.insert(tree_type(std::string("2"), 2));
	t.insert(tree_type(std::string("4"), 4));
	t.insert(tree_type(std::string("1"), 1));
	t.insert(tree_type(std::string("5"), 5));
	tree::node_pointer n = t.search("1");
	if (n == NULL)
		return (false);
	tree_type p = n->key;
	if (p.first != "1" || p.second != 1)
		return (false);
	n = t.search("2");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "2" || p.second != 2)
		return (false);
	n = t.search("3");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "3" || p.second != 3)
		return (false);
	n = t.search("4");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "4" || p.second != 4)
		return (false);
	n = t.search("5");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "5" || p.second != 5)
		return (false);
	return (true);
}
static bool test_insert_multiple(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	t.insert(tree_type(std::string("2"), 2));
	t.insert(tree_type(std::string("3"), 3));
	t.insert(tree_type(std::string("4"), 4));
	t.insert(tree_type(std::string("5"), 5));
	tree::node_pointer n = t.search("1");
	if (n == NULL)
		return (false);
	tree_type p = n->key;
	if (p.first != "1" || p.second != 1)
		return (false);
	n = t.search("2");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "2" || p.second != 2)
		return (false);
	n = t.search("3");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "3" || p.second != 3)
		return (false);
	n = t.search("4");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "4" || p.second != 4)
		return (false);
	n = t.search("5");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "5" || p.second != 5)
		return (false);
	return (true);
}
static bool test_insert_same(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	t.insert(tree_type(std::string("2"), 3));
	t.insert(tree_type(std::string("2"), 2));
	tree::node_pointer n = t.search("1");
	if (n == NULL)
		return (false);
	tree_type p = n->key;
	if (p.first != "1" || p.second != 1)
		return (false);
	n = t.search("2");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "2" || p.second != 3)
		return (false);
	return (true);
}
static bool test_search(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	tree::node_pointer n = t.search("1");
	if (n == NULL)
		return (false);
	tree_type p = n->key;
	if (p.first != "1" || p.second != 1)
		return (false);
	return (true);
}
static bool test_search_multiple(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	t.insert(tree_type(std::string("2"), 2));
	tree::node_pointer n = t.search("1");
	if (n == NULL)
		return (false);
	tree_type p = n->key;
	if (p.first != "1" || p.second != 1)
		return (false);
	n = t.search("2");
	if (n == NULL)
		return (false);
	p = n->key;
	if (p.first != "2" || p.second != 2)
		return (false);
	return (true);
}
static bool test_search_non_existent(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	t.insert(tree_type(std::string("2"), 2));
	tree::node_pointer n = t.search("3");
	if (n != NULL)
		return (false);
	return (true);
}
static bool test_erase(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	t.erase("1");
	tree::node_pointer n = t.search("1");
	if (n != NULL)
		return (false);
	return (true);
}
static bool test_erase_multiple(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	t.insert(tree_type(std::string("2"), 2));
	t.insert(tree_type(std::string("3"), 3));
	t.erase("3");
	t.erase("1");
	t.erase("2");
	tree::node_pointer n = t.search("1");
	if (n != NULL)
		return (false);
	n = t.search("2");
	if (n != NULL)
		return (false);
	n = t.search("3");
	if (n != NULL)
		return (false);
	return (true);
}
static bool test_erase_non_existent(void) {
	typedef NS::pair< std::string, int >					  tree_type;
	typedef NS::RBTree< tree_type, std::less< std::string > > tree;
	tree													  t;
	t.insert(tree_type(std::string("1"), 1));
	t.erase("1");
	t.erase("2");
	tree::node_pointer n = t.search("1");
	if (n != NULL)
		return (false);
	return (true);
}
static bool test_balanced_simple(void) {
	typedef NS::pair<int , int > tree_type;
	typedef NS::RBTree< tree_type >		 tree;
	tree t;
	t.insert(tree_type(3, 3));
	t.insert(tree_type(4, 4));
	t.insert(tree_type(10, 10));
	t.insert(tree_type(11, 11));
	t.insert(tree_type(33, 33));
	t.insert(tree_type(24, 24));
	t.insert(tree_type(57, 57));
	t.insert(tree_type(12, 12));
	t.insert(tree_type(12, 12));
	t.insert(tree_type(55, 55));
	t.insert(tree_type(21, 21));
	t.insert(tree_type(17, 17));
	t.insert(tree_type(36, 36));
	t.insert(tree_type(52, 52));
	t.insert(tree_type(42, 42));
	t.insert(tree_type(22, 22));
	t.insert(tree_type(92, 92));
	t.insert(tree_type(2, 2));
	t.insert(tree_type(9, 9));

	NS::node<tree_type>::DG_tree(t.root);

	t.erase(33);

	NS::node<tree_type>::DG_tree(t.root);
	return (false);
}

bool test_rbtree(void) {
	Test t("Red Black Tree");
	t.registerTest("Default constructor", &test_default_constructor);
	t.registerTest("Insert", &test_insert);
	t.registerTest("Insert multiple unordered",
				   &test_insert_multiple_unordered);
	t.registerTest("Insert multiple", &test_insert_multiple);
	t.registerTest("Insert same", &test_insert_same);
	t.registerTest("Search", &test_search);
	t.registerTest("Search multiple", &test_search_multiple);
	t.registerTest("Search non-existent", &test_search_non_existent);
	t.registerTest("Erase", &test_erase);
	t.registerTest("Erase multiple", &test_erase_multiple);
	t.registerTest("Erase non-existent", &test_erase_non_existent);
	// t.registerTest("Balanced", &test_balanced_simple);
	return (t.run());
}

*/
