#pragma once

#include "iterator_trait.hpp"
#include "vector_iterator.hpp"
#include "vector_const_iterator.hpp"

namespace ft
{

template< class Iterator >
class reverse_iterator {
	public:
		/* Member types */
		typedef Iterator iterator_type;
		typedef typename iterator_traits< Iterator >::iterator_category iterator_category;
		typedef typename iterator_traits< Iterator >::value_type value_type;
		typedef typename iterator_traits< Iterator >::difference_type difference_type;
		typedef typename iterator_traits< Iterator >::pointer pointer;
		typedef typename iterator_traits< Iterator >::reference reference;

		/* Member functions */
		reverse_iterator(void) : current(NULL) {}
		explicit reverse_iterator( iterator_type x ) : current(x) {}
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ) { *this = other; }
		~reverse_iterator(void) {}
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ) {
			if (this == &other)
				return (*this);
			this->current = other.current;
			return (*this);
		}
		iterator_type base(void) const {return (this->current);}
		reference operator*(void) const {
			Iterator tmp = this->current;
			return (*--tmp);
		}
		pointer operator->() const {
			Iterator tmp = this->current;
			return (&(*--tmp));
		}
		reference operator[]( difference_type n ) const {
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
		reverse_iterator operator++( int ) {
			reverse_iterator tmp(*this);
			--current;
			return (tmp);
		}
		reverse_iterator operator--( int ) {
			reverse_iterator tmp(*this);
			++current;
			return (tmp);
		}
		reverse_iterator operator+( difference_type n ) const {
			return (reverse_iterator(this->current - n));
		}
		reverse_iterator operator-( difference_type n ) const {
			return (reverse_iterator(this->current + n));
		}
		reverse_iterator& operator+=( difference_type n ) {
			this->current -= n;
			return (*this);
		}
		reverse_iterator& operator-=( difference_type n ) {
			this->current += n;
			return (*this);
		}

	protected:
		iterator_type current;
};

/* Non-member functions */
template< class Iterator1, class Iterator2 >
bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() == rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() != rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() > rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() >= rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() < rhs.base());
}
template< class Iterator1, class Iterator2 >
bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() <= rhs.base());
}
template< class Iter >
reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
{
	return (it.base() - n);
}
template< class Iterator >
typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
{
	return (rhs.base() - lhs.base());
}

} // namespace ft
