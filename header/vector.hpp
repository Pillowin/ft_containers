/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:06:38 by agautier          #+#    #+#             */
/*   Updated: 2022/01/04 19:13:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"
#include <cstddef>
#include <memory>

// TODO: public / private
// TODO: change std namespace to ft

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
		typedef iterator< random_access_iterator_tag,
						  T,
						  difference_type,
						  pointer,
						  reference >
			iterator;
		// typedef class const_iterator					const_iterator;
		// typedef std::reverse_iterator< iterator >		reverse_iterator;
		// typedef std::reverse_iterator< const_iterator >
		// const_reverse_iterator;

		/* Member functions */
		// vector();
		vector(void) {}
		// explicit vector(Allocator const& alloc);
		// explicit vector(size_type		 count,
		// 				const T&		 value = T(),
		// 				Allocator const& alloc = Allocator());
		// template< class InputIt >
		// vector(InputIt			first,
		// 	   InputIt			last,
		// 	   Allocator const& alloc = Allocator());
		// vector(vector const& other);
		vector(vector const& other) { *this = other; }
		// ~vector();
		~vector(void) {
			// TODO: This destroys all container elements, and
			// deallocates all the storage capacity allocated by
			// the vector using its allocator.
		}
		// vector& operator=( const vector& other );
		vector& operator=(vector const& other) {
			if (this == &other)
				return (*this);
			// TODO: add values
			return (*this);
		}
		// void assign( size_type count, const T& value );
		// template< class InputIt >
		// void assign( InputIt first, InputIt last );
		// allocator_type get_allocator() const;

		vector(size_type n, value_type const& val = value_type()) {
			// TODO: implement
			(void)n;
			(void)val;
		}

		/* Element access */

		// reference at( size_type pos );
		// const_reference at( size_type pos ) const;
		// reference operator[]( size_type pos );
		// const_reference operator[]( size_type pos ) const;
		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;
		// T* data();
		// const T* data() const;

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

		// bool empty() const;
		// size_type size() const;
		// size_type max_size() const;
		// void reserve( size_type new_cap );
		// size_type capacity() const;

		/* Modifiers */

		// void clear();
		// iterator insert( iterator pos, const T& value );
		// void insert( iterator pos, size_type count, const T& value );
		// template< class InputIt >
		// void insert( iterator pos, InputIt first, InputIt last );
		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );
		// void push_back( const T& value );
		// void pop_back();
		// void resize( size_type count, T value = T() );
		// void swap( vector& other );

		/* Non member function overload */

		// template< class T, class Alloc >
		// void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );
		// template< class T, class Alloc >
		// bool operator==(std::vector< T, Alloc > const& lhs, std::vector< T,
		// Alloc > const& rhs); template< class T, class Alloc > bool
		// operator==(std::vector< T, Alloc > const& lhs, std::vector< T, Alloc
		// > const& rhs); template< class T, class Alloc > bool
		// operator<(std::vector< T, Alloc > const& lhs, std::vector< T, Alloc >
		// const& rhs); template< class T, class Alloc > bool
		// operator<=(std::vector< T, Alloc > const& lhs, std::vector< T, Alloc
		// > const& rhs); template< class T, class Alloc > bool
		// operator>(std::vector< T, Alloc > const& lhs, std::vector< T, Alloc >
		// const& rhs); template< class T, class Alloc > bool
		// operator>=(std::vector< T, Alloc > const& lhs, std::vector< T, Alloc
		// > const& rhs);
};

} // namespace ft
