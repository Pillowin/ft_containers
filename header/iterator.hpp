/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:26:59 by agautier          #+#    #+#             */
/*   Updated: 2022/01/04 19:00:16 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		typedef const T*				   pointer;
		typedef const T&				   reference;
		typedef random_access_iterator_tag iterator_category;
};

/* Basic iterator */
template< class Category,
		  class T,
		  class Distance  = std::ptrdiff_t,
		  class Pointer	  = T*,
		  class Reference = T& >
class iterator {
	public:
		/* Member types */
		typedef Category  iterator_category;
		typedef T		  value_type;
		typedef Distance  difference_type;
		typedef Pointer	  pointer;
		typedef Reference reference;
};

/* advance */
template< class InputIterator, class Distance >
void advance(InputIterator& i, Distance n) {
	// TODO: Requires: n may be negative only for random access and
	// bidirectional iterators.
	// TODO: Effects: increments (or decrements for negative n) iterator
	// reference i by n.
	(void)i;
	(void)n;
}

/* distance */
template< class InputIterator >
typename iterator_traits< InputIterator >::difference_type
	distance(InputIterator first, InputIterator last) {
	// TODO: Requires: last must be reachable from first.
	// TODO: Effects: Returns the number of increments or decrements needed o
	// get from first to last.
	(void)first;
	(void)last;
	return (0);
}

} // namespace ft
