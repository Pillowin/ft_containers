#pragma once

namespace ft {

template< class InputIterator1, class InputIterator2 >
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
	for (InputIterator1 it = first1; it != last1; ++it)
		if (*it != *first2++)
			return (false);
	return (true);
}

template< class InputIterator1, class InputIterator2, class BinaryPredicate >
bool equal(InputIterator1  first1,
		   InputIterator1  last1,
		   InputIterator2  first2,
		   BinaryPredicate p) {
	for (InputIterator1 it = first1; first1 != last1; ++it)
		if (!p(*it, *first2++))
			return (false);
	return (true);
}

template< class InputIterator1, class InputIterator2 >
bool lexicographical_compare(InputIterator1 first1,
							 InputIterator1 last1,
							 InputIterator2 first2,
							 InputIterator2 last2) {
	while (first1 != last1 && first2 != last2) {
		if (*first1 < *first2)
			return (true);
		if (*first2 < *first1)
			return (false);
		++first1;
		++first2;
	}
	return (first1 == last1 && first2 != last2);
}

template< class InputIterator1, class InputIterator2, class Compare >
bool lexicographical_compare(InputIterator1 first1,
							 InputIterator1 last1,
							 InputIterator2 first2,
							 InputIterator2 last2,
							 Compare		comp) {
	while (first1 != last1 && first2 != last2) {
		if (comp(*first1, *first2))
			return (true);
		if (comp(*first2, *first1))
			return (false);
		++first1;
		++first2;
	}
	return (first1 == last1 && first2 != last2);
}

} // namespace ft
