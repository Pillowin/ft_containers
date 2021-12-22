/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:06:38 by agautier          #+#    #+#             */
/*   Updated: 2021/12/22 17:55:39 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <memory>

namespace ft {

template< typename T, typename Allocator = std::allocator< T > >
class Vector {
	private:
		typedef T		  value_type;
		typedef Allocator allocator_type;
		typedef T&		  reference;
		typedef const T&  const_reference;
		typedef T*		  pointer;
		typedef const T*  const_pointer;
		// TODO: iterators
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t	   size_type;

	public:
		Vector(void) {}
		Vector(Vector const& rhs) { *this = rhs; }
		Vector(size_type n, value_type const& val = value_type()) {
			// TODO: implement
			(void)n;
			(void)val;
		}
		// TODO: Iterator constructor

		~Vector(void) {
			// TODO: This destroys all container elements, and
			// deallocates all the storage capacity allocated by
			// the vector using its allocator.
		}

		Vector& operator=(Vector const& rhs) {
			if (this == &rhs)
				return (*this);
			// TODO: add values
			return (*this);
		}
};

} // namespace ft

#endif
