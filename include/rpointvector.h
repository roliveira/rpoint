#ifndef __RPOINTVECTOR_HEADER__
#define __RPOINTVECTOR_HEADER__


#include "rpoint.h"


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

    size_t size(void) { return v.size(); }

    rvector_t get(void) const { return *this; };
    vector_t  getX(void) { return ; };
    vector_t  getY(void) { return ; };
    vector_t  getZ(void) { return ; };
    vector_t  x(void)    { return ; };
    vector_t  y(void)    { return ; };
    vector_t  z(void)    { return ; };

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
    
}

// Free Operators

// Methods

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
