#pragma once

#include "iterator.hpp"
#include "set_iterator.hpp"

namespace ft {

/* Basic iterator */
template< class T >
class set_const_iterator {
	public:
		/* Member types */
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef T							   value_type;
		typedef std::ptrdiff_t				   difference_type;
		typedef value_type const*			   pointer;
		typedef value_type const&			   reference;

	private:
		typedef typename RBNode< T >::node_pointer node_pointer;

	public:
		/* Constructors/Destructor */
		set_const_iterator(void) : ptr(0) {}
		set_const_iterator(node_pointer ptr) : ptr(ptr) {}
		set_const_iterator(set_iterator< T > const& rhs) : ptr(rhs.get_ptr()) {}
		set_const_iterator(set_const_iterator const& rhs) { *this = rhs; }
		~set_const_iterator(void) {}

		/* Assignment operator */
		set_const_iterator& operator=(set_const_iterator const& rhs) {
			if (this == &rhs)
				return (*this);
			this->ptr = rhs.ptr;
			return (*this);
		}

		/* Access operators */
		reference	 operator*(void) const { return (this->ptr->key); }
		pointer		 operator->(void) const { return (&this->ptr->key); }
		node_pointer get_ptr(void) const { return (this->ptr); }

		/* Increment/Decrement operators */
		set_const_iterator& operator++(void) {
			if (!this->ptr)
				return (*this);
			if (this->ptr->right) {
				this->ptr = this->ptr->right;
				while (this->ptr->left)
					this->ptr = this->ptr->left;
			} else if (this->ptr->parent) {
				while (this->ptr->parent
					   && this->ptr->parent->right == this->ptr)
					this->ptr = this->ptr->parent;
				if (this->ptr->parent && this->ptr->parent->left == this->ptr)
					this->ptr = this->ptr->parent;
				else
					this->ptr = NULL;
			} else
				this->ptr = NULL;
			return (*this);
		}
		set_const_iterator& operator--(void) {
			if (!this->ptr)
				return (*this);
			if (this->ptr->left) {
				this->ptr = this->ptr->left;
				while (this->ptr && this->ptr->right)
					this->ptr = this->ptr->right;
			} else {
				node_pointer tmp = this->ptr;
				this->ptr		 = this->ptr->parent;
				while (this->ptr && this->ptr->right != tmp) {
					tmp		  = this->ptr;
					this->ptr = this->ptr->parent;
				}
			}
			return (*this);
		}
		set_const_iterator operator++(int) {
			set_const_iterator tmp = *this;
			++(*this);
			return (tmp);
		}
		set_const_iterator operator--(int) {
			set_const_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		/* Comparaison operators */
		bool operator==(ft::set_const_iterator< T > const& rhs) const {
			return (this->ptr == rhs.ptr);
		}
		bool operator!=(ft::set_const_iterator< T > const& rhs) const {
			return (this->ptr != rhs.ptr);
		}

	private:
		node_pointer ptr;
};

} // namespace ft
