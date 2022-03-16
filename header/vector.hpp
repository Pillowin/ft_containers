#pragma once

#include "algorithm.hpp"
#include "vector_iterator.hpp"
#include "vector_const_iterator.hpp"
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace ft {

template< class T, class Allocator = std::allocator< T > >
class vector {
	public:
		/* Member types */
		typedef T								  value_type;
		typedef Allocator						  allocator_type;
		typedef std::size_t						  size_type;
		typedef std::ptrdiff_t					  difference_type;
		typedef value_type&						  reference;
		typedef value_type const&				  const_reference;
		typedef typename Allocator::pointer		  pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef vector_iterator< T >			  iterator;
		typedef vector_const_iterator<T>		  const_iterator;
		// typedef std::reverse_iterator< iterator >		reverse_iterator;
		// typedef std::reverse_iterator< const_iterator >
		// const_reverse_iterator;

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
		vector(InputIt			first,
			   InputIt			last,
			   Allocator const& alloc = Allocator()) :
			m_allocator(alloc),
			m_capacity(std::distance(first, last)),
			m_size(this->m_capacity),
			m_start(this->m_allocator.allocate(this->m_capacity)) {
			for (size_type i = 0; i < this->m_capacity; ++i) {
				this->m_allocator.construct(this->m_start + i, *first);
				++first;
			}
		}
		vector(vector const& rhs) :
			m_allocator(rhs.m_allocator),
			m_capacity(rhs.m_size),
			m_size(rhs.m_size),
			m_start(this->m_allocator.allocate(this->m_capacity)) {
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.construct(this->m_start + i, rhs.m_start[i]);
		}
		~vector(void) {
			for (size_type i = 0; i <= this->m_size; ++i)
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
				this->m_allocator.construct(this->m_start + i, rhs.m_start[i]);
			this->m_size = rhs.m_size;
			return (*this);
		}
		void assign(size_type count, const T& value) {
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
		void assign(InputIt first, InputIt last) {
			size_type count = std::distance(first, last);
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(this->m_start + i);
			if (this->m_capacity < count) {
				this->m_allocator.deallocate(this->m_start, this->m_capacity);
				this->m_capacity = count;
				this->m_start	 = this->m_allocator.allocate(this->m_capacity);
			}
			for (size_type i = 0; i < count; ++i)
				this->m_allocator.construct(this->m_start + i, first[i]);
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
		iterator begin(void) { return (iterator(this->m_start)); }
		const_iterator begin(void) const { return (const_iterator(this->m_start)); }
		iterator end(void) { return (iterator(this->m_start + this->m_size)); }
		const_iterator end(void) const { return (const_iterator(this->m_start + this->m_size)); }
		// reverse_iterator rbegin(void);
		// const_reverse_iterator rbegin(void) const;
		// reverse_iterator rend(void);
		// const_reverse_iterator rend(void) const;

		/* Capacity */
		bool	  empty(void) const { return (!this->m_size); }
		size_type size(void) const { return (this->m_size); }
		size_type max_size(void) const {
			return (this->m_allocator.max_size());
		}
		void reserve(size_type new_cap) {
			if (new_cap <= this->m_capacity)
				return;
			pointer tmp	  = this->m_start;
			this->m_start = this->m_allocator.allocate(new_cap);
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.construct(this->m_start + i, tmp[i]);
			for (size_type i = 0; i < this->m_size; ++i)
				this->m_allocator.destroy(tmp + i);
			this->m_allocator.deallocate(tmp, this->m_capacity);
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
			difference_type pos_index = &(*pos) - this->m_start;
			if (this->m_capacity == 0)
				this->reserve(10);
			if (this->m_capacity <= this->m_size)
				this->reserve(this->m_capacity * 2);
			this->m_allocator.construct(this->m_start + this->m_size, this->back());
			++this->m_size;
			for (difference_type i = this->m_size - 2; i > pos_index; --i)
				this->m_start[i] = this->m_start[i - 1];
			this->m_start[pos_index] = value;
			return (iterator(this->m_start + pos_index));
		}
		void insert(iterator pos, size_type count, const_reference value) {
			difference_type pos_index = &(*pos) - this->m_start;
			if (this->m_capacity == 0)
				this->reserve(count);
			while (this->m_capacity <= this->m_size + count)
				this->reserve(this->m_capacity * 2);
			for (size_type i = 0; i < count; ++i) {
				this->m_allocator.construct(this->m_start + this->m_size, this->back());
				++this->m_size;
			}
			for (difference_type i = this->m_size - 2; i - count + 1 > 0; --i)
				this->m_start[i] = this->m_start[i - count];
			for (size_type i = 0; i < count; ++i)
				this->m_start[pos_index + i] = value;
		}
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last ) {
			difference_type pos_index = &(*pos) - this->m_start;
			difference_type count = &(*last) - &(*first);
			if (this->m_capacity == 0)
				this->reserve(count);
			while (this->m_capacity <= this->m_size + count)
				this->reserve(this->m_capacity * 2);
			for (difference_type i = 0; i < count; ++i) {
				this->m_allocator.construct(this->m_start + this->m_size, this->back());
				++this->m_size;
			}
			for (difference_type i = this->m_size - 2; i - count + 1 > 0; --i)
				this->m_start[i] = this->m_start[i - count + 1];
			for (difference_type i = 0; i < count; ++i)
				this->m_start[pos_index + i] = first[i];
		}
		iterator erase(iterator pos) {
			this->m_allocator.destroy(&(*pos));
			--this->m_size;
			for (iterator it = pos; it != end(); ++it)
				it[0] = it[1];
			return (pos);
		}
		iterator erase(iterator first, iterator last) {
			size_type count = &(*last) - &(*first);
			size_type begin = &(*first) - this->m_start;
			for (size_type i = begin; i <= count; ++i)
				this->m_allocator.destroy(this->m_start + i);
			this->m_size -= count;
			for (size_type i = begin; i <= this->m_size; ++i)
				this->m_start[i] = this->m_start[i + count];
			return (first);
		}
		void push_back(const T& value) {
			if (this->m_capacity == 0)
				this->reserve(10);
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
					this->m_allocator.destroy(this->m_start + this->m_size);
			} else if (this->m_size < count) {
				if (this->m_capacity == 0)
					this->reserve(10);
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
// template< class T, class Alloc >
// void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs);
template< class T, class Alloc >
bool operator==(vector< T, Alloc > const& lhs, vector< T, Alloc > const& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
// template< class T, class Alloc > bool operator==(std::vector< T,
// Alloc > const& lhs, std::vector< T, Alloc > const& rhs);
// template< class T, class Alloc > bool operator<(std::vector< T,
// Alloc > const& lhs, std::vector< T, Alloc > const& rhs);
// template< class T, class Alloc > bool operator<=(std::vector< T,
// Alloc > const& lhs, std::vector< T, Alloc > const& rhs);
// template< class T, class Alloc > bool operator>(std::vector< T,
// Alloc > const& lhs, std::vector< T, Alloc > const& rhs);
// template< class T, class Alloc > bool operator>=(std::vector< T,
// Alloc > const& lhs, std::vector< T, Alloc > const& rhs);


} // namespace ft
