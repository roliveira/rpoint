#ifndef __DISTANCE_HEADER__
#define __DISTANCE_HEADER__


#include "rpoint.h"


template <typename T> T euclidean(RPoint<T> p0, RPoint<T> p1) {
	RPoint<T> xd = p1 - p0;
	return std::sqrt(rpoint::sum(rpoint::pow(xd, 2)));
};

template <typename T> T manhattan(RPoint<T> p0, RPoint<T> p1) {
	RPoint<T> xd = rpoint::abs(p1 - p0);
	return rpoint::sum(xd);
};

template <typename T> T canberra(RPoint<T> p0, RPoint<T> p1) {
	RPoint<T> xd = rpoint::abs(p1 - p0);
	return rpoint::sum(xd / (rpoint::abs(p0) + rpoint::abs(p1)));
};

template <typename T> T chebyshev(RPoint<T> p0, RPoint<T> p1) {
	RPoint<T> xd = rpoint::abs(p1 - p0);
	return rpoint::max(xd);
};


#endif // __DISTANCE_HEADER__
