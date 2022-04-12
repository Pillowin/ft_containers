#pragma once

#include "utility.hpp"
#include <cstdlib>
#include <memory>
#include <utility>

namespace ft {

#define LEAF NULL

typedef enum {
	RED = 0,
	BLACK
} RBColor;

template< class T >
class RBNode {
	public:
		typedef T					  value_type;
		typedef value_type&			  reference;
		typedef value_type const&	  const_reference;
		typedef value_type*			  pointer;
		typedef value_type const*	  const_pointer;
		typedef RBNode< value_type >* node_pointer;

		RBNode(void) :
			left(NULL),
			right(NULL),
			parent(NULL),
			color(BLACK),
			key() {}
		RBNode(T const& key) :
			left(NULL),
			right(NULL),
			parent(NULL),
			color(BLACK),
			key(key) {}
		RBNode(RBNode const& rhs) { *this = rhs; }
		~RBNode(void) {}
		RBNode& operator=(RBNode const& rhs) {
			if (this == &rhs)
				return (*this);
			this->left	 = rhs.left;
			this->right	 = rhs.right;
			this->parent = rhs.parent;
			this->color	 = rhs.color;
			this->key	 = rhs.key;
			return (*this);
		}

		node_pointer left;
		node_pointer right;
		node_pointer parent;
		RBColor		 color;
		value_type	 key;
};

template< class T,
		  class Compare,
		  class Allocator = std::allocator< RBNode< T > > >
class RBTree {
	public:
		typedef T				  value_type;
		typedef value_type&		  reference;
		typedef value_type const& const_reference;
		typedef Compare			  key_compare;
		typedef
			typename Allocator::template rebind< RBNode< value_type > >::other
													   allocator_type;
		typedef std::size_t							   size_type;
		typedef typename allocator_type::pointer	   pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef RBNode< value_type >				   node;
		typedef node*								   node_pointer;

	private:
		allocator_type allocator;
		size_type	   size;
		key_compare	   comp;
		node_pointer   root;
		node_pointer   end;

	public:
		RBTree(void) :
			allocator(Allocator()),
			size(0),
			comp(Compare()),
			root(LEAF),
			end(this->create_node()) {}
		RBTree(RBTree const& rhs) { *this = rhs; }
		~RBTree(void) {
			this->clear(this->root);
			this->delete_node(this->end);
		}

	private:
		RBTree& operator=(RBTree const& rhs) {
			(void)rhs;
			return (*this);
		}

	public:
		void insert(const_reference key) {
			node_pointer n = search(key);
			if (n != NULL)
				return;
			if (this->size)
				this->end->parent->right = LEAF;
			else
				this->root = LEAF;
			++this->size;
			node_pointer inserted_node = create_node(node(key));
			inserted_node->color	   = RED;
			if (this->root == NULL) {
				this->root = inserted_node;
			} else {
				node_pointer n = this->root;
				while (true) {
					if (this->comp(key, n->key) == true) {
						if (n->left == NULL && n->left != this->end) {
							n->left = inserted_node;
							break;
						} else {
							n = n->left;
						}
					} else {
						if (n->right == NULL && n->right != this->end) {
							n->right = inserted_node;
							break;
						} else {
							n = n->right;
						}
					}
				}
				inserted_node->parent = n;
			}
			insert_case1(inserted_node);
			update_end();
		}

		template< class InputIt >
		void insert(InputIt first, InputIt last) {
			for (; first != last; ++first)
				insert(*first);
		}

		void erase(const_reference k) {
			node_pointer n = search(k);
			if (n == NULL)
				return;
			if (this->size)
				this->end->parent->right = LEAF;
			else
				this->root = LEAF;
			--this->size;
			if (n->left != NULL && n->right != NULL) {
				node_pointer pred = maximum(n->left);
				n->key			  = pred->key;
				n				  = pred;
			}
			node_pointer child = n->right == NULL ? n->left : n->right;
			if (get_color(n) == BLACK) {
				n->color = get_color(child);
				erase_case1(n);
			}
			replace_node(n, child);
			if (n->parent == NULL && child != NULL)
				child->color = BLACK;
			delete_node(n);
			update_end();
		}
		void clear(node_pointer root) {
			if (root == LEAF || root == this->end) {
				this->size = 0;
				this->update_end();
				return;
			}
			clear(root->left);
			clear(root->right);
			delete_node(root);
		}
		node_pointer search(const_reference k) {
			node_pointer n = this->root;
			while (n != NULL) {
				if (this->comp(k, n->key) == false
					&& this->comp(n->key, k) == false && n != this->end)
					return (n);
				else if (this->comp(k, n->key) == true)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}
		node_pointer search(const_reference k) const {
			node_pointer n = this->root;
			while (n != NULL) {
				if (this->comp(k, n->key) == false
					&& this->comp(n->key, k) == false)
					return (n);
				else if (this->comp(k, n->key) == true)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}
		node_pointer maximum(node_pointer n) {
			while (n->right != NULL && n->right != this->end)
				n = n->right;
			return (n);
		}
		node_pointer maximum(node_pointer n) const {
			while (n->right != NULL && n->right != this->end)
				n = n->right;
			return (n);
		}
		node_pointer minimum(node_pointer n) {
			if (this->size == 0)
				return (this->end);
			while (n->left != NULL)
				n = n->left;
			return (n);
		}
		node_pointer minimum(node_pointer n) const {
			if (this->size == 0)
				return (this->end);
			while (n->left != NULL)
				n = n->left;
			return (n);
		}
		void swap(RBTree& tree) {
			allocator_type tmp_allocator = tree.allocator;
			size_type	   tmp_size		 = tree.size;
			key_compare	   tmp_comp		 = tree.comp;
			node_pointer   tmp_root		 = tree.root;
			node_pointer   tmp_end		 = tree.end;

			tree.allocator = this->allocator;
			tree.size	   = this->size;
			tree.comp	   = this->comp;
			tree.root	   = this->root;
			tree.end	   = this->end;

			this->allocator = tmp_allocator;
			this->size		= tmp_size;
			this->comp		= tmp_comp;
			this->root		= tmp_root;
			this->end		= tmp_end;
		}
		allocator_type get_allocator(void) const { return (this->allocator); }
		size_type	   get_size(void) const { return (this->size); }
		node_pointer   get_root(void) const { return (this->root); }
		node_pointer   get_end(void) const { return (this->end); }

	private:
		/* Create/Delete */
		node_pointer create_node(void) {
			node_pointer n = this->allocator.allocate(1);
			this->allocator.construct(n, node());
			return (n);
		}
		node_pointer create_node(node p) {
			node_pointer n = this->allocator.allocate(1);
			this->allocator.construct(n, p);
			return (n);
		}
		void delete_node(node_pointer n) {
			this->allocator.destroy(n);
			this->allocator.deallocate(n, 1);
		}

		/* Genealogy */
		node_pointer parent(node_pointer n) { return (n->parent); }
		node_pointer grandparent(node_pointer n) {
			node_pointer p = parent(n);
			if (p == NULL)
				return (NULL);
			return parent(p);
		}
		node_pointer sibling(node_pointer n) {
			node_pointer p = parent(n);
			if (p == NULL)
				return (NULL);
			if (n == p->left)
				return (p->right);
			else
				return (p->left);
		}
		node_pointer uncle(node_pointer enfant) {
			node_pointer p = parent(enfant);
			node_pointer g = grandparent(enfant);
			if (g == NULL)
				return (NULL);
			return (sibling(p));
		}

		/* Rotations */
		void rotate_left(node_pointer n) {
			node_pointer r = n->right;
			replace_node(n, r);
			n->right = r->left;
			if (r->left != NULL) {
				r->left->parent = n;
			}
			r->left	  = n;
			n->parent = r;
		}
		void rotate_right(node_pointer n) {
			node_pointer l = n->left;
			replace_node(n, l);
			n->left = l->right;
			if (l->right != NULL)
				l->right->parent = n;
			l->right  = n;
			n->parent = l;
		}

		/* Utils */
		RBColor get_color(node_pointer n) {
			return (n == NULL ? BLACK : n->color);
		}
		void replace_node(node_pointer oldn, node_pointer newn) {
			if (oldn->parent == NULL) {
				this->root = newn;
			} else {
				if (oldn == oldn->parent->left)
					oldn->parent->left = newn;
				else
					oldn->parent->right = newn;
			}
			if (newn != NULL) {
				newn->parent = oldn->parent;
			}
		}
		void update_end(void) {
			if (this->size == 0) {
				if (this->end == NULL)
					this->end = this->create_node();
				this->root = this->end;
				return;
			}
			node_pointer max  = this->maximum(this->root);
			max->right		  = this->end;
			this->end->parent = max;
		}

		/* Insert */
		void insert_case1(node_pointer n) {
			if (n->parent == NULL)
				n->color = BLACK;
			else
				insert_case2(n);
		}
		void insert_case2(node_pointer n) {
			if (get_color(n->parent) == BLACK)
				return;
			else
				insert_case3(n);
		}
		void insert_case3(node_pointer n) {
			if (get_color(uncle(n)) == RED) {
				n->parent->color	  = BLACK;
				uncle(n)->color		  = BLACK;
				grandparent(n)->color = RED;
				insert_case1(grandparent(n));
			} else {
				insert_case4(n);
			}
		}
		void insert_case4(node_pointer n) {
			if (n == n->parent->right && n->parent == grandparent(n)->left) {
				rotate_left(n->parent);
				n = n->left;
			} else if (n == n->parent->left
					   && n->parent == grandparent(n)->right) {
				rotate_right(n->parent);
				n = n->right;
			}
			insert_case5(n);
		}
		void insert_case5(node_pointer n) {
			n->parent->color	  = BLACK;
			grandparent(n)->color = RED;
			if (n == n->parent->left && n->parent == grandparent(n)->left) {
				rotate_right(grandparent(n));
			} else {
				rotate_left(grandparent(n));
			}
		}

		/* Erase */
		void erase_case1(node_pointer n) {
			if (n->parent == NULL)
				return;
			else
				erase_case2(n);
		}
		void erase_case2(node_pointer n) {
			if (get_color(sibling(n)) == RED) {
				n->parent->color  = RED;
				sibling(n)->color = BLACK;
				if (n == n->parent->left)
					rotate_left(n->parent);
				else
					rotate_right(n->parent);
			}
			erase_case3(n);
		}
		void erase_case3(node_pointer n) {
			if (get_color(n->parent) == BLACK && get_color(sibling(n)) == BLACK
				&& get_color(sibling(n)->left) == BLACK
				&& get_color(sibling(n)->right) == BLACK) {
				sibling(n)->color = RED;
				erase_case1(n->parent);
			} else
				erase_case4(n);
		}
		void erase_case4(node_pointer n) {
			if (get_color(n->parent) == RED && get_color(sibling(n)) == BLACK
				&& get_color(sibling(n)->left) == BLACK
				&& get_color(sibling(n)->right) == BLACK) {
				sibling(n)->color = RED;
				n->parent->color  = BLACK;
			} else
				erase_case5(n);
		}
		void erase_case5(node_pointer n) {
			if (n == n->parent->left && get_color(sibling(n)) == BLACK
				&& get_color(sibling(n)->left) == RED
				&& get_color(sibling(n)->right) == BLACK) {
				sibling(n)->color		= RED;
				sibling(n)->left->color = BLACK;
				rotate_right(sibling(n));
			} else if (n == n->parent->right && get_color(sibling(n)) == BLACK
					   && get_color(sibling(n)->right) == RED
					   && get_color(sibling(n)->left) == BLACK) {
				sibling(n)->color		 = RED;
				sibling(n)->right->color = BLACK;
				rotate_left(sibling(n));
			}
			erase_case6(n);
		}
		void erase_case6(node_pointer n) {
			sibling(n)->color = get_color(n->parent);
			n->parent->color  = BLACK;
			if (n == n->parent->left) {
				sibling(n)->right->color = BLACK;
				rotate_left(n->parent);
			} else {
				sibling(n)->left->color = BLACK;
				rotate_right(n->parent);
			}
		}
};

} // namespace ft
