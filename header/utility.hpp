#pragma once

namespace ft {

template< class T1, class T2 >
class pair {
	public:
		/* Member types */
		typedef T1 first_type;
		typedef T2 second_type;

		/* Member objects */
		T1 first;
		T2 second;

		/* Member function */
		pair(void) : first(), second() {}
		pair(T1 const& x, T2 const& y) : first(x), second(y) {}
		template< class U1, class U2 >
		pair(pair< U1, U2 > const& p) : first(p.first), second(p.second) {}
		pair(pair const& p) : first(p.first), second(p.second) {}
		~pair(void) {}
		pair& operator=(pair const& other) {
			if (this == &other)
				return (*this);
			this->first	 = other.first;
			this->second = other.second;
			return (*this);
		}
};

/* Non-member functions */
template< class T1, class T2 >
ft::pair< T1, T2 > make_pair(T1 t, T2 u) {
	return (ft::pair< T1, T2 >(t, u));
}

template< class T1, class T2 >
bool operator==(ft::pair< T1, T2 > const& lhs, ft::pair< T1, T2 > const& rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}
template< class T1, class T2 >
bool operator!=(ft::pair< T1, T2 > const& lhs, ft::pair< T1, T2 > const& rhs) {
	return (!(lhs == rhs));
}
template< class T1, class T2 >
bool operator<(ft::pair< T1, T2 > const& lhs, ft::pair< T1, T2 > const& rhs) {
	return (lhs.first < rhs.first
			|| (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}
template< class T1, class T2 >
bool operator<=(ft::pair< T1, T2 > const& lhs, ft::pair< T1, T2 > const& rhs) {
	return (!(rhs < lhs));
}
template< class T1, class T2 >
bool operator>(ft::pair< T1, T2 > const& lhs, ft::pair< T1, T2 > const& rhs) {
	return (rhs < lhs);
}
template< class T1, class T2 >
bool operator>=(ft::pair< T1, T2 > const& lhs, ft::pair< T1, T2 > const& rhs) {
	return (!(lhs < rhs));
}

} // namespace ft
