#pragma once

#include "RBTree.hpp"
#include "algorithm.hpp"
#include "reverse_iterator.hpp"
#include "set_const_iterator.hpp"
#include "set_iterator.hpp"
#include "utility.hpp"
#include <functional>
#include <memory>
#include <stdexcept>

namespace ft {

template< class Key,
		  class Compare	  = std::less< Key >,
		  class Allocator = std::allocator< Key > >
class set {
	public:
		/* Member types */
		typedef Key									   key_type;
		typedef Key									   value_type;
		typedef std::size_t							   size_type;
		typedef std::ptrdiff_t						   difference_type;
		typedef Compare								   key_compare;
		typedef Compare								   value_compare;
		typedef Allocator							   allocator_type;
		typedef value_type&							   reference;
		typedef value_type const&					   const_reference;
		typedef typename allocator_type::pointer	   pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef set_const_iterator< value_type >			   iterator;
		typedef set_const_iterator< value_type >	   const_iterator;
		typedef ft::reverse_iterator< iterator >	   reverse_iterator;
		typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;

	private:
		typedef typename allocator_type::template rebind< value_type >::other
			key_allocator_type;
		typedef RBTree< value_type, value_compare, key_allocator_type > rbtree;
		typedef RBNode< value_type >									node;
		typedef RBNode< value_type> * node_pointer;

	public:
		/* Member functions */
		set(void) :
			kcomp(key_compare()),
			allocator(allocator_type()),
			tree(rbtree()) {}
		explicit set(Compare const&	  comp,
					 Allocator const& alloc = Allocator()) :
			kcomp(comp),
			allocator(alloc),
			tree(rbtree()) {}
		template< class InputIt >
		set(InputIt			 first,
			InputIt			 last,
			Compare const&	 comp  = Compare(),
			Allocator const& alloc = Allocator()) :
			kcomp(comp),
			allocator(alloc),
			tree(rbtree()) {
			this->insert(first, last);
		}
		set(set const& other) { *this = other; }
		~set(void) {}
		set& operator=(set const& other) {
			if (this == &other)
				return (*this);
			this->allocator = other.allocator;
			this->kcomp		= other.kcomp;
			if (this->tree.get_size())
				this->clear();
			this->tree.insert(other.begin(), other.end());
			return (*this);
		}
		allocator_type get_allocator(void) const { return (this->allocator); }

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
				this->insert(iterator(this->tree.search(value)), value),
				tmp != this->tree.get_size()));
		}
		iterator insert(iterator hint, const_reference value) {
			(void)hint;
			this->tree.insert(value);
			return (iterator(this->tree.search(value)));
		}
		template< class InputIt >
		void insert(InputIt first, InputIt last) {
			for (; first != last; ++first)
				this->tree.insert(*first);
		}
		void erase(iterator pos) { this->tree.erase(pos.get_ptr()->key); }
		void erase(iterator first, iterator last) {
			iterator tmp;
			while (first != last) {
				tmp = first;
				++first;
				this->tree.erase(tmp.get_ptr()->key);
			}
		}
		size_type erase(key_type const& key) {
			size_type ret = this->tree.get_size();
			this->tree.erase(key);
			return (ret - this->tree.get_size());
		}
		void swap(set& other) { this->tree.swap(other.tree); }

		/* Lookup */
		size_type count(Key const& key) const {
			return (this->find(key) != this->end());
		}
		iterator find(Key const& key) {
			iterator it = this->lower_bound(key);
			if (it == this->end() || this->kcomp(key, it.get_ptr()->key))
				return (this->end());
			return (it);
		}
		const_iterator find(Key const& key) const {
			const_iterator it = this->lower_bound(key);
			if (it == this->end() || this->kcomp(key, it.get_ptr()->key))
				return (this->end());
			return (it);
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
				if (!this->kcomp(it.get_ptr()->key, key))
					return (it);
			return (this->end());
		}
		const_iterator lower_bound(Key const& key) const {
			for (const_iterator it = this->begin(); it != this->end(); ++it)
				if (!this->kcomp(it.get_ptr()->key, key))
					return (it);
			return (this->end());
		}
		iterator upper_bound(Key const& key) {
			for (iterator it = this->begin(); it != this->end(); ++it)
				if (this->kcomp(key, it.get_ptr()->key))
					return (it);
			return (this->end());
		}
		const_iterator upper_bound(Key const& key) const {
			for (const_iterator it = this->begin(); it != this->end(); ++it)
				if (this->kcomp(key, it.get_ptr()->key))
					return (it);
			return (this->end());
		}

		/* Observers */
		key_compare	  key_comp(void) const { return (this->kcomp); }
		value_compare value_comp(void) const {
			return (value_compare(this->kcomp));
		}

	private:
		key_compare	   kcomp;
		allocator_type allocator;
		rbtree tree;
};

/* Non-member functions */
template< class Key, class Compare, class Alloc >
bool operator==(ft::set< Key, Compare, Alloc > const& lhs,
				ft::set< Key, Compare, Alloc > const& rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template< class Key, class Compare, class Alloc >
bool operator!=(ft::set< Key, Compare, Alloc > const& lhs,
				ft::set< Key, Compare, Alloc > const& rhs) {
	return (!(lhs == rhs));
}
template< class Key, class Compare, class Alloc >
bool operator<(ft::set< Key, Compare, Alloc > const& lhs,
			   ft::set< Key, Compare, Alloc > const& rhs) {
	return (ft::lexicographical_compare(lhs.begin(),
										lhs.end(),
										rhs.begin(),
										rhs.end()));
}
template< class Key, class Compare, class Alloc >
bool operator<=(ft::set< Key, Compare, Alloc > const& lhs,
				ft::set< Key, Compare, Alloc > const& rhs) {
	return (!(rhs < lhs));
}
template< class Key, class Compare, class Alloc >
bool operator>(ft::set< Key, Compare, Alloc > const& lhs,
			   ft::set< Key, Compare, Alloc > const& rhs) {
	return (rhs < lhs);
}
template< class Key, class Compare, class Alloc >
bool operator>=(ft::set< Key, Compare, Alloc > const& lhs,
				ft::set< Key, Compare, Alloc > const& rhs) {
	return (!(lhs < rhs));
}
template< class Key, class Compare, class Alloc >
void swap(ft::set< Key, Compare, Alloc >& lhs,
		  ft::set< Key, Compare, Alloc >& rhs) {
	lhs.swap(rhs);
}

} // namespace ft
