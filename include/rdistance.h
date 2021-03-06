#ifndef __DISTANCE_HEADER__
#define __DISTANCE_HEADER__

#include "rpoint.h"

template <typename T>
T euclidean(RPoint<T> p0, RPoint<T> p1) { return std::sqrt(rpoint::sum(rpoint::pow(p1 - p0, 2))); };

template <typename T>
T manhattan(RPoint<T> p0, RPoint<T> p1) { return rpoint::sum(rpoint::abs(p1 - p0)); };

template <typename T>
T canberra(RPoint<T> p0, RPoint<T> p1) { return rpoint::sum(rpoint::abs(p1 - p0) / (rpoint::abs(p0) + rpoint::abs(p1))); };

template <typename T>
T chebyshev(RPoint<T> p0, RPoint<T> p1) { return rpoint::max(rpoint::abs(p1 - p0)); };

#endif // __DISTANCE_HEADER__
