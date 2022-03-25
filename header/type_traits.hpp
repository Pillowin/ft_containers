#pragma once

namespace ft {

template< class T, T v >
class integral_constant {
	public:
		typedef T				  value_type;
		typedef integral_constant type;
		static const T			  value = v;
};

typedef integral_constant< bool, true >	 true_type;
typedef integral_constant< bool, false > false_type;

template< class T >
class is_integral: public false_type {};

template<>
class is_integral< bool >: public true_type {};

template<>
class is_integral< char >: public true_type {};
template<>
class is_integral< short >: public true_type {};
template<>
class is_integral< int >: public true_type {};
template<>
class is_integral< long >: public true_type {};

template<>
class is_integral< unsigned char >: public true_type {};
template<>
class is_integral< unsigned short >: public true_type {};
template<>
class is_integral< unsigned int >: public true_type {};
template<>
class is_integral< unsigned long >: public true_type {};

template< bool B, class T = void >
class enable_if {};

template< class T >
class enable_if< true, T > {
	public:
		typedef T type;
};

} // namespace ft
