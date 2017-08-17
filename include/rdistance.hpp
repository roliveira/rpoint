#ifndef __RDISTANCE_HEADER__
#define __RDISTANCE_HEADER__

#include "rpoint.hpp"
#include "rpointvector.hpp"

template <typename T>
T euclidean(RPoint<T> p0, RPoint<T> p1) { return std::sqrt(rpoint::sum(rpoint::pow(p1 - p0, 2))); };

template <typename T>
RPointVector<T> euclidean(RPointVector<T> v0, RPointVector<T> v1) { return; };

template <typename T>
T manhattan(RPoint<T> p0, RPoint<T> p1) { return rpoint::sum(rpoint::abs(p1 - p0)); };

template <typename T>
RPointVector<T> manhattan(RPointVector<T> v0, RPointVector<T> v1) { return; };

template <typename T>
T canberra(RPoint<T> p0, RPoint<T> p1) { return rpoint::sum(rpoint::abs(p1 - p0) / (rpoint::abs(p0) + rpoint::abs(p1))); };

template <typename T>
RPointVector<T> canberra(RPointVector<T> v0, RPointVector<T> v1) { return; };

template <typename T>
T chebyshev(RPoint<T> p0, RPoint<T> p1) { return rpoint::max(rpoint::abs(p1 - p0)); };

template <typename T>
RPointVector<T> chebyshev(RPointVector<T> v0, RPointVector<T> v1) { return; };

#endif//__RDISTANCE_HEADER__
