#pragma once

#include <cstddef>

namespace ft {

/* Iterator tags */
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};

/* Iterator traits */
template< class Iterator >
class iterator_traits {
	public:
		typedef typename Iterator::difference_type	 difference_type;
		typedef typename Iterator::value_type		 value_type;
		typedef typename Iterator::pointer			 pointer;
		typedef typename Iterator::reference		 reference;
		typedef typename Iterator::iterator_category iterator_category;
};

/* Iterator traits specialized for pointers */
template< class T >
class iterator_traits< T* > {
	public:
		typedef std::ptrdiff_t			   difference_type;
		typedef T						   value_type;
		typedef T*						   pointer;
		typedef T&						   reference;
		typedef random_access_iterator_tag iterator_category;
};

/* Iterator traits specialized for pointers to const */
template< class T >
class iterator_traits< const T* > {
	public:
		typedef std::ptrdiff_t			   difference_type;
		typedef T						   value_type;
		typedef T const*				   pointer;
		typedef T const&				   reference;
		typedef random_access_iterator_tag iterator_category;
};


template <class InputIter>
typename ft::iterator_traits<InputIter>::difference_type
distance(InputIter first, InputIter last)
{
	typename ft::iterator_traits<InputIter>::difference_type r(0);
	for (; first != last; ++first)
		++r;
	return r;
}

} // namespace ft
