#pragma once

#include "iterator.hpp"
#include "vector_iterator.hpp"

namespace ft {

/* Basic iterator */
template< class T >
class vector_const_iterator {
	public:
		/* Member types */
		typedef ft::random_access_iterator_tag iterator_category;
		typedef T							   value_type;
		typedef std::ptrdiff_t				   difference_type;
		typedef T const*					   pointer;
		typedef T const&					   reference;

		/* Constructors/Destructor */
		vector_const_iterator(void) : ptr(0) {}
		vector_const_iterator(pointer ptr) : ptr(ptr) {}
		vector_const_iterator(vector_const_iterator const& rhs) { *this = rhs; }
		vector_const_iterator(vector_iterator<T> const& rhs) : ptr(&(*rhs)) {}
		~vector_const_iterator(void) {}

		/* Assignment operator */
		vector_const_iterator& operator=(reference rhs) {
			if (this == &rhs)
				return (*this);
			this->ptr = rhs.ptr;
			return (*this);
		}

		/* Access operators */
		reference operator*(void) const { return (*this->ptr); }
		pointer	  operator->(void) const { return (this->ptr); }
		reference operator[](difference_type off) const { return (ptr[off]); }

		/* Increment/Decrement operators */
		vector_const_iterator& operator++(void) {
			this->ptr++;
			return (*this);
		}
		vector_const_iterator& operator--(void) {
			this->ptr--;
			return (*this);
		}
		vector_const_iterator operator++(int) {
			vector_const_iterator tmp = *this;
			this->ptr++;
			return (tmp);
		}
		vector_const_iterator operator--(int) {
			vector_const_iterator tmp = *this;
			this->ptr--;
			return (tmp);
		}

		/* Arithmetic operators */
		vector_const_iterator operator+(difference_type rhs) const {
			return (this->ptr + rhs);
		}
		vector_const_iterator operator-(difference_type rhs) const {
			return (this->ptr - rhs);
		}
		vector_const_iterator& operator+=(difference_type rhs) {
			this->ptr += rhs;
			return (*this);
		}
		vector_const_iterator& operator-=(difference_type rhs) {
			this->ptr -= rhs;
			return (*this);
		}
		friend vector_const_iterator operator+(difference_type n, const vector_const_iterator&rhs) {
			return (vector_const_iterator(rhs.ptr + n));
		}
		friend difference_type operator-(const vector_const_iterator &lhs, const vector_const_iterator &rhs) {
			return (lhs.ptr - rhs.ptr);
		}

		/* Comparaison operators */
		bool operator==(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr == rhs.ptr);
		}
		bool operator!=(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr != rhs.ptr);
		}
		bool operator<(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr < rhs.ptr);
		}
		bool operator>(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr > rhs.ptr);
		}
		bool operator<=(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr <= rhs.ptr);
		}
		bool operator>=(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr >= rhs.ptr);
		}

	private:
		pointer ptr;
};

} // namespace ft
