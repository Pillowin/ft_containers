#pragma once

#include "iterator.hpp"
#include "vector_const_iterator.hpp"

namespace ft {

template< class T >
class vector_const_iterator;

/* Basic iterator */
template< class T >
class vector_iterator {
	public:
		/* Member types */
		typedef ft::random_access_iterator_tag iterator_category;
		typedef T							   value_type;
		typedef std::ptrdiff_t				   difference_type;
		typedef value_type*					   pointer;
		typedef value_type&					   reference;

		/* Constructors/Destructor */
		vector_iterator(void) : ptr(0) {}
		vector_iterator(pointer ptr) : ptr(ptr) {}
		vector_iterator(vector_iterator const& rhs) { *this = rhs; }
		~vector_iterator(void) {}

		/* Assignment operator */
		vector_iterator& operator=(vector_iterator const& rhs) {
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
		vector_iterator& operator++(void) {
			this->ptr++;
			return (*this);
		}
		vector_iterator& operator--(void) {
			this->ptr--;
			return (*this);
		}
		vector_iterator operator++(int) {
			vector_iterator tmp = *this;
			this->ptr++;
			return (tmp);
		}
		vector_iterator operator--(int) {
			vector_iterator tmp = *this;
			this->ptr--;
			return (tmp);
		}

		/* Arithmetic operators */
		vector_iterator operator+(difference_type rhs) const {
			return (this->ptr + rhs);
		}
		vector_iterator operator-(difference_type rhs) const {
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
		friend vector_iterator operator+(difference_type		n,
										 vector_iterator const& rhs) {
			return (vector_iterator(rhs.ptr + n));
		}
		friend difference_type operator-(vector_iterator const& lhs,
										 vector_iterator const& rhs) {
			return (lhs.ptr - rhs.ptr);
		}

		/* Comparaison operators */
		bool operator==(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr == &(*rhs));
		}
		bool operator!=(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr != &(*rhs));
		}
		bool operator<(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr < &(*rhs));
		}
		bool operator>(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr > &(*rhs));
		}
		bool operator<=(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr <= &(*rhs));
		}
		bool operator>=(ft::vector_const_iterator< T > const& rhs) const {
			return (this->ptr >= &(*rhs));
		}

	private:
		pointer ptr;
};

} // namespace ft
