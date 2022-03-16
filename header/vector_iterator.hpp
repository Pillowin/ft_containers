#pragma once

#include "iterator.hpp"

namespace ft {

/* Basic iterator */
template< class T >
class vector_iterator {
	public:
		/* Member types */
		typedef ft::random_access_iterator_tag iterator_category;
		typedef T							   value_type;
		typedef std::ptrdiff_t				   difference_type;
		typedef T*							   pointer;
		typedef T&							   reference;

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

} // namespace ft
