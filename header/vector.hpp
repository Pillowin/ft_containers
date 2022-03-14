#pragma once

#include "iterator.hpp"
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace ft {

/* Basic iterator */
template< class T >
class vector_iterator {
	public:
		/* Member types */
		typedef ft::random_access_iterator_tag iterator_category;
		typedef T							   value_type;
		typedef std::ptrdiff_t				   difference_type;
		typedef T const*					   pointer;
		typedef T const&					   reference;

		/* Constructors/Destructor */
		vector_iterator(void) : ptr(0) {}
		vector_iterator(pointer ptr) : ptr(ptr) {}
		vector_iterator(vector_iterator const& rhs) { *this = rhs; }
		~vector_iterator(void) {}

		/* Assignment operator */
		vector_iterator& operator=(reference rhs) {
			if (this == &rhs)
				return (*this);
			this->ptr = rhs.ptr;
			return (*this);
		}

		/* Access operators */
		reference operator*(void) { return (*this->ptr); }
		pointer	  operator->(void) { return (this->ptr); }
		reference operator[](difference_type off) { return (ptr[off]); }

		/* Increment/Decrement operators */
		reference operator++(void) { return (this->ptr++); }
		reference operator--(void) { return (this->ptr--); }
		reference operator++(int) {
			vector_iterator tmp = *this;
			this->ptr++;
			return (tmp);
		}
		reference operator--(int) {
			vector_iterator tmp = *this;
			this->ptr--;
			return (tmp);
		}

		/* Arithmetic operators */
		vector_iterator operator+(difference_type rhs) {
			return (this->ptr + rhs);
		}
		vector_iterator operator-(difference_type rhs) {
			return (this->ptr - rhs);
		}
		vector_iterator& operator+=(difference_type rhs) {
			this->ptr += rhs;
			return (*this);
		}
		vector_iterator& operator-=(difference_type rhs) {
			this->ptr -= rhs;
			return (*this);
		}
		// TODO: friends ?

		/* Comparaison operators */
		bool operator==(ft::vector_iterator< T > const& rhs) {
			return (this->ptr == rhs.ptr);
		}
		bool operator!=(ft::vector_iterator< T > const& rhs) {
			return (this->ptr != rhs.ptr);
		}
		bool operator<(ft::vector_iterator< T > const& rhs) {
			return (this->ptr < rhs.ptr);
		}
		bool operator>(ft::vector_iterator< T > const& rhs) {
			return (this->ptr > rhs.ptr);
		}
		bool operator<=(ft::vector_iterator< T > const& rhs) {
			return (this->ptr <= rhs.ptr);
		}
		bool operator>=(ft::vector_iterator< T > const& rhs) {
			return (this->ptr >= rhs.ptr);
		}

	private:
		pointer ptr;
};

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
		typedef ft::vector_iterator< T >		  iterator;
		// typedef class const_iterator					const_iterator;
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
		allocator_type get_allocator() const { return (this->m_allocator); }

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
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		/* Capacity */
		bool	  empty() const { return (!this->m_size); }
		size_type size() const { return (this->m_size); }
		size_type max_size() const { return (this->m_allocator.max_size()); }
		// void reserve( size_type new_cap );
		size_type capacity() const { return (this->m_capacity); }

		/* Modifiers */
		// void clear();
		// iterator insert( iterator pos, const T& value );
		// void insert( iterator pos, size_type count, const T& value );
		// template< class InputIt >
		// void insert( iterator pos, InputIt first, InputIt last );
		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );
		// void push_back( const T& value );
		void pop_back() {
			if (!this->m_size)
				return;
			this->m_allocator.destroy(this->m_start + this->m_size - 1);
			--this->m_size;
		}
		// void resize( size_type count, T value = T() );
		// void swap( vector& other );

		/* Non member function overload */
		// template< class T, class Alloc >
		// void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs
		// ); template< class T, class Alloc > bool operator==(std::vector<
		// T, Alloc > const& lhs, std::vector< T, Alloc > const& rhs);
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

	private:
		allocator_type m_allocator;
		size_type	   m_capacity;
		size_type	   m_size;
		pointer		   m_start;
};

} // namespace ft
