#pragma once

#include "iterator.hpp"
#include "vector_const_iterator.hpp"
#include "vector_iterator.hpp"

namespace ft {

template< class Iterator >
class reverse_iterator {
	public:
		/* Member types */
		typedef Iterator iterator_type;
		typedef typename iterator_traits< Iterator >::iterator_category
			iterator_category;
		typedef typename iterator_traits< Iterator >::value_type value_type;
		typedef typename iterator_traits< Iterator >::difference_type
																difference_type;
		typedef typename iterator_traits< Iterator >::pointer	pointer;
		typedef typename iterator_traits< Iterator >::reference reference;

		/* Member functions */
		reverse_iterator(void) : current(NULL) {}
		explicit reverse_iterator(iterator_type x) : current(x) {}
		template< class U >
		reverse_iterator(reverse_iterator< U > const& other) : current(other.base()) { }
		~reverse_iterator(void) {}
		template< class U >
		reverse_iterator& operator=(reverse_iterator< U > const& other) {
			this->current = other.base();
			return (*this);
		}
		iterator_type base(void) const { return (this->current); }
		reference	  operator*(void) const {
				Iterator tmp = this->current;
				return (*--tmp);
		}
		pointer operator->() const {
			Iterator tmp = this->current;
			return (&(*--tmp));
		}
		reference operator[](difference_type n) const {
			Iterator tmp = this->current;
			return (*(--tmp - n));
		}
		reverse_iterator& operator++(void) {
			--this->current;
			return (*this);
		}
		reverse_iterator& operator--(void) {
			++this->current;
			return (*this);
		}
		reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			--current;
			return (tmp);
		}
		reverse_iterator operator--(int) {
			reverse_iterator tmp(*this);
			++current;
			return (tmp);
		}
		reverse_iterator operator+(difference_type n) const {
			return (reverse_iterator(this->current - n));
		}
		reverse_iterator operator-(difference_type n) const {
			return (reverse_iterator(this->current + n));
		}
		reverse_iterator& operator+=(difference_type n) {
			this->current -= n;
			return (*this);
		}
		reverse_iterator& operator-=(difference_type n) {
			this->current += n;
			return (*this);
		}

	protected:
		iterator_type current;
};

/* Non-member functions */
template< class Iterator1, class Iterator2 >
bool operator==(reverse_iterator< Iterator1 > const& lhs,
				reverse_iterator< Iterator2 > const& rhs) {
	return (lhs.base() == rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator!=(reverse_iterator< Iterator1 > const& lhs,
				reverse_iterator< Iterator2 > const& rhs) {
	return (lhs.base() != rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator<(reverse_iterator< Iterator1 > const& lhs,
			   reverse_iterator< Iterator2 > const& rhs) {
	return (lhs.base() > rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator<=(reverse_iterator< Iterator1 > const& lhs,
				reverse_iterator< Iterator2 > const& rhs) {
	return (lhs.base() >= rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator>(reverse_iterator< Iterator1 > const& lhs,
			   reverse_iterator< Iterator2 > const& rhs) {
	return (lhs.base() < rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator>=(reverse_iterator< Iterator1 > const& lhs,
				reverse_iterator< Iterator2 > const& rhs) {
	return (lhs.base() <= rhs.base());
}
template< class Iter >
reverse_iterator< Iter >
	operator+(typename reverse_iterator< Iter >::difference_type n,
			  reverse_iterator< Iter > const&					 it) {
	return (ft::reverse_iterator<Iter>(it.base() - n));
}
template< class Iterator >
typename reverse_iterator< Iterator >::difference_type
	operator-(reverse_iterator< Iterator > const& lhs,
			  reverse_iterator< Iterator > const& rhs) {
	return (rhs.base() - lhs.base());
}
template< class Iterator1, class Iterator2 >
typename reverse_iterator< Iterator1 >::difference_type
	operator-(reverse_iterator< Iterator1 > const& lhs,
			  reverse_iterator< Iterator2 > const& rhs) {
	return (rhs.base() - lhs.base());
}

} // namespace ft
