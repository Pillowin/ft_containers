#pragma once

#include "algorithm.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "vector_const_iterator.hpp"
#include "vector_iterator.hpp"
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace ft {

template< class T, class Allocator = std::allocator< T > >
class vector {
	public:
		/* Member types */
		typedef T									   value_type;
		typedef Allocator							   allocator_type;
		typedef std::size_t							   size_type;
		typedef std::ptrdiff_t						   difference_type;
		typedef value_type&							   reference;
		typedef value_type const&					   const_reference;
		typedef typename Allocator::pointer			   pointer;
		typedef typename Allocator::const_pointer	   const_pointer;
		typedef vector_iterator< T >				   iterator;
		typedef vector_const_iterator< T >			   const_iterator;
		typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;
		typedef ft::reverse_iterator< iterator >	   reverse_iterator;

		/* Member functions */
		explicit vector(Allocator const& alloc = allocator_type()) :
			m_allocator(alloc),
			m_capacity(0),
			m_size(0),
			m_start(NULL) {}
		explicit vector(size_type		 count,
						const_reference	 value = value_type(),
						Allocator const& alloc = Allocator()) :
			m_allocator(alloc),
			m_capacity(count),
			m_size(count),
			m_start(this->m_allocator.allocate(count)) {
			for (size_type i = 0; i < count; ++i)
				this->m_allocator.construct(this->m_start + i, value);
		}
		template< class InputIt >
		vector(InputIt								   first,
			   typename ft::enable_if< !ft::is_integral< InputIt >::value,
									   InputIt >::type last,
			   Allocator const&						   alloc = Allocator()) :
			m_allocator(alloc),
			m_capacity(ft::distance(first, last)),
			m_size(this->m_capacity),
			m_start(this->m_allocator.allocate(this->m_capacity)) {
			for (size_type i = 0; i < this->m_size; ++i) {
				this->m_allocator.construct(this->m_start + i, *first);
				++first;
			}
		}
		vector(vector const& rhs) :
			m_allocator(rhs.m_allocator),
			m_capacity(rhs.m_capacity),
			m_size(rhs.m_size),
			m_start(this->m_allocator.allocate(this->m_capacity)) {
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.construct(this->m_start + i, rhs[i]);
		}
		~vector(void) {
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(this->m_start + i);
			this->m_allocator.deallocate(this->m_start, this->m_capacity);
		}
		vector& operator=(vector const& rhs) {
			if (this == &rhs)
				return (*this);
			this->m_allocator = rhs.m_allocator;
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(this->m_start + i);
			if (this->m_capacity < rhs.m_size) {
				this->m_allocator.deallocate(this->m_start, this->m_capacity);
				this->m_capacity = rhs.m_size;
				this->m_start	 = this->m_allocator.allocate(this->m_capacity);
			}
			for (size_type i = 0; i < rhs.m_size; ++i)
				this->m_allocator.construct(this->m_start + i, rhs[i]);
			this->m_size = rhs.m_size;
			return (*this);
		}
		void assign(size_type count, const_reference value) {
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(this->m_start + i);
			if (this->m_capacity < count) {
				this->m_allocator.deallocate(this->m_start, this->m_capacity);
				this->m_capacity = count;
				this->m_start	 = this->m_allocator.allocate(this->m_capacity);
			}
			for (size_type i = 0; i < count; ++i)
				this->m_allocator.construct(this->m_start + i, value);
			this->m_size = count;
		}

		template< class InputIt >
		void assign(InputIt									first,
					typename ft::enable_if< !ft::is_integral< InputIt >::value,
											InputIt >::type last) {
			size_type count = ft::distance(first, last);
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(this->m_start + i);
			if (this->m_capacity < count) {
				this->m_allocator.deallocate(this->m_start, this->m_capacity);
				this->m_capacity = count;
				this->m_start	 = this->m_allocator.allocate(this->m_capacity);
			}
			for (size_type i = 0; i < count; ++i, ++first)
				this->m_allocator.construct(this->m_start + i, *first);
			this->m_size = count;
		}
		allocator_type get_allocator(void) const { return (this->m_allocator); }

		/* Element access */
		reference at(size_type pos) {
			if (pos >= this->m_size)
				throw std::out_of_range("vector: out of range");
			return (this->m_start[pos]);
		}
		const_reference at(size_type pos) const {
			if (pos >= this->m_size)
				throw std::out_of_range("vector: out of range");
			return (this->m_start[pos]);
		}
		reference operator[](size_type pos) { return (this->m_start[pos]); }
		const_reference operator[](size_type pos) const {
			return (this->m_start[pos]);
		}
		reference		front(void) { return (this->m_start[0]); }
		const_reference front(void) const { return (this->m_start[0]); }
		reference		back(void) { return (this->m_start[this->m_size - 1]); }
		const_reference back(void) const {
			return (this->m_start[this->m_size - 1]);
		}
		pointer		  data(void) { return (this->m_start); }
		const_pointer data(void) const { return (this->m_start); }

		/* Iterators */
		iterator	   begin(void) { return (iterator(this->m_start)); }
		const_iterator begin(void) const {
			return (const_iterator(this->m_start));
		}
		iterator end(void) { return (iterator(this->m_start + this->m_size)); }
		const_iterator end(void) const {
			return (const_iterator(this->m_start + this->m_size));
		}
		reverse_iterator rbegin(void) {
			return (reverse_iterator(this->m_start + this->m_size));
		}
		const_reverse_iterator rbegin(void) const {
			return (const_reverse_iterator(this->m_start + this->m_size));
		}
		reverse_iterator rend(void) {
			return (reverse_iterator(this->m_start));
		}
		const_reverse_iterator rend(void) const {
			return (const_reverse_iterator(this->m_start));
		}

		/* Capacity */
		bool	  empty(void) const { return (!this->m_size); }
		size_type size(void) const { return (this->m_size); }
		size_type max_size(void) const {
			return (this->m_allocator.max_size());
		}
		void reserve(size_type new_cap) {
			if (new_cap <= this->m_capacity)
				return;
			pointer tmp = this->m_allocator.allocate(new_cap);
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.construct(tmp + i, this->m_start[i]);
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(this->m_start + i);
			this->m_allocator.deallocate(this->m_start, this->m_capacity);
			this->m_start	 = tmp;
			this->m_capacity = new_cap;
		}
		size_type capacity(void) const { return (this->m_capacity); }

		/* Modifiers */
		void clear(void) {
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(this->m_start + i);
			this->m_size = 0;
		}
		iterator insert(iterator pos, const_reference value) {
			difference_type offset = ft::distance(this->begin(), pos);
			if (this->m_capacity == 0)
				this->reserve(16);
			if (this->m_capacity <= this->m_size)
				this->reserve(this->m_capacity * 2);
			for (iterator it = this->end(); it != this->begin() + offset;
				 --it) {
				this->m_allocator.construct(&(*it), *(it - 1));
				this->m_allocator.destroy(&(*(it - 1)));
			}
			this->m_allocator.construct(&(*(this->begin() + offset)), value);
			++this->m_size;
			return (this->begin() + offset);
		}
		void insert(iterator pos, size_type count, const_reference value) {
			if (count == 0)
				return;
			difference_type offset = ft::distance(this->begin(), pos);
			if (this->m_capacity == 0)
				this->reserve(count);
			while (this->m_capacity <= this->m_size + count)
				this->reserve(this->m_capacity * 2);
			for (size_type i = 0; i < count; ++i)
				this->insert(this->begin() + offset, value);
		}
		template< class InputIt >
		void insert(iterator								pos,
					InputIt									first,
					typename ft::enable_if< !ft::is_integral< InputIt >::value,
											InputIt >::type last) {
			difference_type offset = ft::distance(this->begin(), pos);
			difference_type count  = ft::distance(first, last);
			if (this->m_capacity == 0)
				this->reserve(count);
			while (this->m_capacity <= this->m_size + count)
				this->reserve(this->m_capacity * 2);
			for (difference_type i = 0; first != last; ++i, first++)
				this->insert(this->begin() + offset + i, *first);
		}
		iterator erase(iterator pos) {
			--this->m_size;
			for (iterator it = pos; it != this->end(); ++it) {
				//*it = *(it + 1);
				this->m_allocator.destroy(&(*it));
				this->m_allocator.construct(&(*it), *(it + 1));
			}
			this->m_allocator.destroy(this->m_start + this->m_size);
			return (pos);
		}

		iterator erase(iterator first, iterator last) {
			if (first == last)
				return (first);
			if (last != this->end()) {
				for (; first != last; --last)
					this->erase(first);
				return (first);
			}
			iterator ret = first;
			for (; first != last; ++first) {
				this->m_allocator.destroy(&(*first));
				--this->m_size;
			}
			return (ret);
		}
		void push_back(T const& value) {
			if (this->m_capacity == 0)
				this->reserve(16);
			else if (this->m_size == this->m_capacity)
				this->reserve(this->m_capacity * 2);
			this->m_allocator.construct(this->m_start + this->m_size, value);
			++this->m_size;
		}
		void pop_back(void) {
			if (!this->m_size)
				return;
			this->m_allocator.destroy(this->m_start + this->m_size - 1);
			--this->m_size;
		}
		void resize(size_type count, T value = T()) {
			if (this->m_size > count) {
				for (; this->m_size > count; --this->m_size)
					this->m_allocator.destroy(this->m_start + this->m_size - 1);
			} else if (this->m_size < count) {
				if (this->m_capacity == 0)
					this->reserve(16);
				while (this->m_capacity < count)
					this->reserve(this->m_capacity * 2);
				for (size_type i = this->m_size; i < count; ++i)
					this->m_allocator.construct(this->m_start + i, value);
				this->m_size = count;
			}
		}
		void swap(vector& other) {
			std::swap(this->m_allocator, other.m_allocator);
			std::swap(this->m_capacity, other.m_capacity);
			std::swap(this->m_size, other.m_size);
			std::swap(this->m_start, other.m_start);
		}

	private:
		allocator_type m_allocator;
		size_type	   m_capacity;
		size_type	   m_size;
		pointer		   m_start;
};

/* Non member function overload */
template< class T, class Alloc >
void swap(vector< T, Alloc >& lhs, vector< T, Alloc >& rhs) {
	lhs.swap(rhs);
}
template< class T, class Alloc >
bool operator==(vector< T, Alloc > const& lhs, vector< T, Alloc > const& rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template< class T, class Alloc >
bool operator!=(vector< T, Alloc > const& lhs, vector< T, Alloc > const& rhs) {
	return (!(lhs == rhs));
}
template< class T, class Alloc >
bool operator<(vector< T, Alloc > const& lhs, vector< T, Alloc > const& rhs) {
	return (ft::lexicographical_compare(lhs.begin(),
										lhs.end(),
										rhs.begin(),
										rhs.end()));
}
template< class T, class Alloc >
bool operator<=(vector< T, Alloc > const& lhs, vector< T, Alloc > const& rhs) {
	return (!(lhs > rhs));
}
template< class T, class Alloc >
bool operator>(vector< T, Alloc > const& lhs, vector< T, Alloc > const& rhs) {
	return (ft::lexicographical_compare(rhs.begin(),
										rhs.end(),
										lhs.begin(),
										lhs.end()));
}
template< class T, class Alloc >
bool operator>=(vector< T, Alloc > const& lhs, vector< T, Alloc > const& rhs) {
	return (!(lhs < rhs));
}

} // namespace ft
