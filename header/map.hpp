#pragma once

#include "RBTree.hpp"
#include "algorithm.hpp"
#include "map_const_iterator.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"
#include <functional>
#include <memory>
#include <stdexcept>

namespace ft {

template< class Key,
		  class T,
		  class Compare	  = std::less< Key >,
		  class Allocator = std::allocator< ft::pair< Key, T > > >
class map {
	public:
		/* Member types */
		typedef Key									   key_type;
		typedef T									   mapped_type;
		typedef ft::pair< key_type, mapped_type >	   value_type;
		typedef std::size_t							   size_type;
		typedef std::ptrdiff_t						   difference_type;
		typedef Compare								   key_compare;
		typedef Allocator							   allocator_type;
		typedef value_type&							   reference;
		typedef value_type const&					   const_reference;
		typedef typename allocator_type::pointer	   pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef map_iterator< value_type >			   iterator;
		typedef map_const_iterator< value_type >	   const_iterator;
		typedef ft::reverse_iterator< iterator >	   reverse_iterator;
		typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;

	private:
		typedef typename allocator_type::template rebind< value_type >::other
			pair_allocator_type;
		typedef RBTree< value_type, key_compare, pair_allocator_type > rbtree;
		typedef RBNode< value_type >								   node;
		typedef typename rbtree::node_pointer node_pointer;

	public:
		/* Member classes */
		class value_compare {
			public:
				/* Member types */
				typedef bool	   result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;

				/* Member functions */
				value_compare(void) : comp(Compare()) {}
				value_compare(Compare c) : comp(c) {}
				~value_compare(void) {}
				value_compare& operator=(value_compare const& rhs) {
					if (this == &rhs)
						return (*this);
					this->comp = rhs.comp;
					return (*this);
				}
				result_type operator()(value_type const& lhs,
									   value_type const& rhs) const {
					return (this->comp(lhs.first, rhs.first));
				}

			protected:
				/* Protected member objects */
				Compare comp;
		};

		/* Member functions */
		map(void) :
			comp(key_compare()),
			allocator(allocator_type()),
			tree(rbtree()) {}
		explicit map(Compare const&	  comp,
					 Allocator const& alloc = Allocator()) :
			comp(comp),
			allocator(alloc),
			tree(rbtree()) {}
		template< class InputIt >
		map(InputIt			 first,
			InputIt			 last,
			Compare const&	 comp  = Compare(),
			Allocator const& alloc = Allocator()) :
			comp(comp),
			allocator(alloc),
			tree(rbtree()) {
			this->insert(first, last);
		}
		map(map const& other) { *this = other; }
		~map(void) {}
		map& operator=(map const& other) {
			if (this == &other)
				return (*this);
			this->allocator = other.allocator;
			this->comp		= other.comp;
			if (this->tree.get_size())
				this->clear();
			this->tree.insert(other.begin(), other.end());
			return (*this);
		}
		allocator_type get_allocator(void) const { return (this->allocator); }

		/* Element access */
		mapped_type& at(key_type const& key) {
			node_pointer ptr = this->tree.search(key);
			if (ptr == NULL)
				throw std::out_of_range("map: out of range");
			return (ptr->key.second);
		}
		mapped_type const& at(key_type const& key) const {
			node_pointer ptr = this->tree.search(key);
			if (ptr == NULL)
				throw std::out_of_range("map: out of range");
			return (ptr->key.second);
		}
		mapped_type& operator[](key_type const& key) {
			node_pointer ptr = this->tree.search(key);
			if (ptr == NULL) {
				this->tree.insert(value_type(key, mapped_type()));
				ptr = this->tree.search(key);
			}
			return (ptr->key.second);
		}

		/* Iterators */
		iterator begin(void) {
			return (iterator(this->tree.minimum(this->tree.get_root())));
		}
		const_iterator begin(void) const {
			return (const_iterator(this->tree.minimum(this->tree.get_root())));
		}
		iterator	   end(void) { return (iterator(this->tree.get_end())); }
		const_iterator end(void) const {
			return (const_iterator(this->tree.get_end()));
		}
		reverse_iterator rbegin(void) {
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin(void) const {
			return (const_reverse_iterator(this->end()));
		}
		reverse_iterator rend(void) {
			return (reverse_iterator(this->begin()));
		}
		const_reverse_iterator rend(void) const {
			return (const_reverse_iterator(this->begin()));
		}

		/* Capacity */
		bool	  empty(void) const { return (this->tree.get_size() == 0); }
		size_type size(void) const { return (this->tree.get_size()); }
		size_type max_size(void) const {
			return (this->tree.get_allocator().max_size());
		}

		/* Modifiers */
		void clear(void) { this->tree.clear(this->tree.get_root()); }
		ft::pair< iterator, bool > insert(const_reference value) {
			size_type tmp = this->tree.get_size();
			return (ft::make_pair< iterator, bool >(
				this->insert(iterator(this->tree.search(value.first)), value),
				tmp != this->tree.get_size()));
		}
		iterator insert(iterator hint, const_reference value) {
			(void)hint;
			this->tree.insert(value);
			return (iterator(this->tree.search(value.first)));
		}
		template< class InputIt >
		void insert(InputIt first, InputIt last) {
			for (; first != last; ++first)
				this->tree.insert(*first);
		}
		void erase(iterator pos) { this->tree.erase(pos->first); }
		void erase(iterator first, iterator last) {
			iterator tmp;
			while (first != last) {
				tmp = first;
				++first;
				this->tree.erase(tmp->first);
			}
		}
		size_type erase(key_type const& key) {
			size_type ret = this->tree.get_size();
			this->tree.erase(key);
			return (ret - this->tree.get_size());
		}
		void swap(map& other) { this->tree.swap(other.tree); }

		/* Lookup */
		size_type count(Key const& key) const {
			return (this->tree.search(key) != NULL);
		}
		iterator find(Key const& key) {
			node_pointer ptr = this->tree.search(key);
			if (ptr == NULL)
				return (this->end());
			return (iterator(ptr));
		}
		const_iterator find(Key const& key) const {
			node_pointer ptr = this->tree.search(key);
			if (ptr == NULL)
				return (this->end());
			return (const_iterator(ptr));
		}
		ft::pair< iterator, iterator > equal_range(Key const& key) {
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}
		ft::pair< const_iterator, const_iterator >
			equal_range(Key const& key) const {
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}
		iterator lower_bound(Key const& key) {
			for (iterator it = this->begin(); it != this->end(); ++it)
				if (it->first == key || !this->comp(it->first, key))
					return (it);
			return (this->end());
		}
		const_iterator lower_bound(Key const& key) const {
			for (const_iterator it = this->begin(); it != this->end(); ++it)
				if (it->first == key || !this->comp(it->first, key))
					return (it);
			return (this->end());
		}
		iterator upper_bound(Key const& key) {
			for (iterator it = this->begin(); it != this->end(); ++it)
				if (it->first != key && !this->comp(it->first, key))
					return (it);
			return (this->end());
		}
		const_iterator upper_bound(Key const& key) const {
			for (const_iterator it = this->begin(); it != this->end(); ++it)
				if (it->first != key && !this->comp(it->first, key))
					return (it);
			return (this->end());
		}

		/* Observers */
		key_compare	  key_comp(void) const { return (this->comp); }
		value_compare value_comp(void) const {
			return (value_compare(this->comp));
		}

	private:
		key_compare	   comp;
		allocator_type allocator;
		rbtree tree;
};

/* Non-member functions */
template< class Key, class T, class Compare, class Alloc >
bool operator==(ft::map< Key, T, Compare, Alloc > const& lhs,
				ft::map< Key, T, Compare, Alloc > const& rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template< class Key, class T, class Compare, class Alloc >
bool operator!=(ft::map< Key, T, Compare, Alloc > const& lhs,
				ft::map< Key, T, Compare, Alloc > const& rhs) {
	return (!(lhs == rhs));
}
template< class Key, class T, class Compare, class Alloc >
bool operator<(ft::map< Key, T, Compare, Alloc > const& lhs,
			   ft::map< Key, T, Compare, Alloc > const& rhs) {
	return (ft::lexicographical_compare(lhs.begin(),
										lhs.end(),
										rhs.begin(),
										rhs.end()));
}
template< class Key, class T, class Compare, class Alloc >
bool operator<=(ft::map< Key, T, Compare, Alloc > const& lhs,
				ft::map< Key, T, Compare, Alloc > const& rhs) {
	return (!(rhs < lhs));
}
template< class Key, class T, class Compare, class Alloc >
bool operator>(ft::map< Key, T, Compare, Alloc > const& lhs,
			   ft::map< Key, T, Compare, Alloc > const& rhs) {
	return (rhs < lhs);
}
template< class Key, class T, class Compare, class Alloc >
bool operator>=(ft::map< Key, T, Compare, Alloc > const& lhs,
				ft::map< Key, T, Compare, Alloc > const& rhs) {
	return (!(lhs < rhs));
}
template< class Key, class T, class Compare, class Alloc >
void swap(ft::map< Key, T, Compare, Alloc >& lhs,
		  ft::map< Key, T, Compare, Alloc >& rhs) {
	lhs.swap(rhs);
}

} // namespace ft
