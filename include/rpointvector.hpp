#ifndef __RPOINTVECTOR_HEADER__
#define __RPOINTVECTOR_HEADER__


#include "rpoint.hpp"


// RPointVector class
template<typename T>
class RPointVector {
public:

    // Definitions

    typedef std::vector<T>                     vector_t;
    typedef RPoint<T>                          rpoint_t;
    typedef std::vector<rpoint_t>              rvector_t;

    typedef typename rvector_t::iterator       iterator;
    typedef typename rvector_t::const_iterator const_iterator;

    // Iterators

    iterator       begin()        { return v.begin();  };
    iterator       end()          { return v.end();    };
    const_iterator cbegin() const { return v.cbegin(); };
    const_iterator cend()   const { return v.cend();   };

    // Constructors

    RPointVector(void)                                       : v(rvector_t(0))                       { };
    RPointVector(const rvector_t vec)                        : v(vec)                                { };
    RPointVector(const std::initializer_list<rpoint_t> ivec) : v(ivec)                               { };
    RPointVector(const iterator begin, const iterator end)   : v(begin, end)                         { };
    RPointVector(const RPointVector<rpoint_t> &pv)           : v(pv.r)                               { };
    template<typename... Ts> RPointVector(const Ts&... args) : v({ static_cast<rpoint_t>(args)... }) { };

    // Destructors

    ~RPointVector(void) { };

    // Getters

    size_t    size(void)      { return v.size();    };
    rvector_t get(void) const { return *this;       };
    vector_t  getX(void)      { return getIndex(0); };
    vector_t  getY(void)      { return getIndex(1); };
    vector_t  getZ(void)      { return getIndex(2); };
    vector_t  x(void)         { return getIndex(0); };
    vector_t  y(void)         { return getIndex(1); };
    vector_t  z(void)         { return getIndex(2); };

    vector_t getIndex(int i) {
        vector_t vec(size());
        std::transform(begin(), end(), vec.begin(), [i](rpoint_t p) {return p[i]; });
        return vec;
    }

    // Converters

    template <typename U>
    rvector_t toVector(void) const {
        std::vector<U> vec;
        std::copy(v.begin(), v.end(), std::back_inserter(vec));
        return vec;
    };

    template <typename U>
    RPointVector<U> to(void) const { return RPointVector<U>(toVector<U>()); };

    // Operators

    // Member access operators

    // Subscript

          rpoint_t& operator[](const int index)       { return v.at(index); };
    const rpoint_t& operator[](const int index) const { return v.at(index); };

    // Comparison operators

    // Equal: vector point == point

    // Equal: vector point == vector point

    // Not equal: vector point != point

    // Not equal: vector point != vector point

    // Less than: vector point < point

    // Less than: vector point < vector point

    // Less than or equal: vector point <= point

    // Less than or equal: vector point <= vector point

    // Greater than: vector point > point

    // Greater than: vector point > vector point

    // Greater than or equal: vector point >= point

    // Greater than or equal: vector point >= vector point

    // Arithmetic operators

    // Addition : vector point + point

    // Addition : vector point + vector point

    // Subtraction : vector point - point

    // Subtraction : vector point - vector point

    // Multiplication : vector point * point

    // Multiplication : vector point * vector point

    // Division : vector point / point

    // Division : vector point / vector point

    // Increment/decrement operators

    // Increment : prefix

    // Increment : postfix

    // Decrement : prefix

    // Decrement : postfix

    // Assignment operators

    // Addition assignment : vector point += point

    // Addition assignment : vector point += vector point

    // Subtraction assignment : vector point -= point

    // Subtraction assignment : vector point -= vector point

    // Multiplication assignment : vector point *= point

    // Multiplication assignment : vector point *= vector point

    // Division assignment : vector point /= point

    // Division assignment : vector point /= vector point

    // Methods

    vector_t  flat(void);
    rpoint_t  min(void);
    rpoint_t  max(void);
    rpoint_t  sum(void);
    rvector_t add(rvector_t v);
    rvector_t sub(rvector_t v);
    rvector_t abs(void);
    rvector_t pow(double exponent);
    rvector_t sqrt(void);

private:
    rvector_t v;
};


// Namespace

namespace rpoint {
    template <typename T>
    std::vector<T> flat(RPointVector<RPoint<T>> v) { return; }

    template <typename T>
    RPoint<T> min(RPointVector<RPoint<T>> v) { return; };

    template <typename T>
    RPoint<T> max(RPointVector<RPoint<T>> v) { return; };

    template <typename T>
    RPoint<T> sum(RPointVector<RPoint<T>> v) { return; };

    template <typename T>
    RPointVector<RPoint<T>> add(RPointVector<RPoint<T>> v1, RPointVector<RPoint<T>> v2) { return; };

    template <typename T>
    RPointVector<RPoint<T>> sub(RPointVector<RPoint<T>> v1, RPointVector<RPoint<T>> v2) { return; };

    template <typename T>
    RPointVector<RPoint<T>> abs(RPointVector<RPoint<T>> v) { return; };

    template <typename T>
    RPointVector<RPoint<T>> pow(RPointVector<RPoint<T>> v, double exponent) { return; };

    template <typename T>
    RPointVector<RPoint<T>> sqrt(RPointVector<RPoint<T>> v) { return; };
};

// Free Operators

// Methods

template <typename T>
typename RPointVector<T>::vector_t RPointVector<T>::flat() { return; }

template <typename T>
typename RPointVector<T>::rpoint_t RPointVector<T>::min(void) { return; };

template <typename T>
typename RPointVector<T>::rpoint_t RPointVector<T>::max(void) { return; };

template <typename T>
typename RPointVector<T>::rpoint_t RPointVector<T>::sum(void) { return; };

template <typename T>
typename RPointVector<T>::rvector_t RPointVector<T>::add(rvector_t v) { return; };

template <typename T>
typename RPointVector<T>::rvector_t RPointVector<T>::sub(rvector_t v) { return; };

template <typename T>
typename RPointVector<T>::rvector_t RPointVector<T>::abs(void) { return; };

template <typename T>
typename RPointVector<T>::rvector_t RPointVector<T>::pow(double exponent) { return; };

template <typename T>
typename RPointVector<T>::rvector_t sqrt(void) { return; };

// Streams

template <typename T>
std::ostream &operator<<(std::ostream &os, const RPointVector<T> &v) {
    os << "RPointVector(" << *v.cbegin();
    for (typename RPoint<T>::const_iterator it = v.cbegin() + 1; it != v.cend(); ++it) {
        os << ", " << *it;
    }
    os << ")";
    return os;
}

// Defenitions

typedef RPointVector<int>    RVectorI;
typedef RPointVector<float>  RVectorF;
typedef RPointVector<double> RVectorD;
typedef RPointVector<bool>   RVectorB;


#endif//__RPOINTVECTOR_HEADER__
