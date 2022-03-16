#pragma once

namespace ft
{

template< class InputIt1, class InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
{
	for (InputIt1 it = first1; first1 != last1; ++it)
		if (*it != *first2)
			return (false);
	return (true);
}

template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
{
	for (InputIt1 it = first1; first1 != last1; ++it && ++first2)
		if (!p(*it, *first2))
			return (false);
	return (true);
}

} // namespace ft
