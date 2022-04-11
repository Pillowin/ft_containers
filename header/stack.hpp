#pragma once

#include "vector.hpp"

namespace ft {

template< class T, class Container = ft::vector< T > >
class stack {
	protected:
		Container c;

	public:
		/* Member types */
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference const_reference;

		/* Member functions */
		explicit stack(Container const& cont = Container()) : c(cont) {}
		stack(stack const& other) : c(other.c) {}
		~stack(void) {}
		stack& operator=(stack const& other) {
			if (this == &other)
				return (*this);
			this->c = other.c;
			return (*this);
		}

		/* Element access */
		reference		top(void) { return (this->c.back()); }
		const_reference top(void) const { return (this->c.back()); }

		/* Capacity */
		bool	  empty(void) const { return (this->c.empty()); }
		size_type size(void) const { return (this->c.size()); }

		/* Modifiers */
		void push(value_type const& value) { this->c.push_back(value); }
		void pop(void) { this->c.pop_back(); }

		/* Non-member functions */
		friend bool operator==(ft::stack< T, Container > const& lhs,
							   ft::stack< T, Container > const& rhs) {
			return (lhs.c == rhs.c);
		}
		friend bool operator>=(ft::stack< T, Container > const& lhs,
							   ft::stack< T, Container > const& rhs) {
			return (lhs.c >= rhs.c);
		}
		friend bool operator<=(ft::stack< T, Container > const& lhs,
							   ft::stack< T, Container > const& rhs) {
			return (lhs.c <= rhs.c);
		}
		friend bool operator!=(ft::stack< T, Container > const& lhs,
							   ft::stack< T, Container > const& rhs) {
			return (lhs.c != rhs.c);
		}
		friend bool operator>(ft::stack< T, Container > const& lhs,
							  ft::stack< T, Container > const& rhs) {
			return (lhs.c > rhs.c);
		}
		friend bool operator<(ft::stack< T, Container > const& lhs,
							  ft::stack< T, Container > const& rhs) {
			return (lhs.c < rhs.c);
		}
};

} // namespace ft
