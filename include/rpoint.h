#ifndef __RPOINT_HEADER__
#define __RPOINT_HEADER__

#include <cmath>
#include <iostream>
#include <cstdarg>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <typeinfo>
#include <string>
#include <memory>


// RPoint class
template <typename T>
class RPoint {
private:
    std::vector<T> r;  // Vector containing the point values

    // Extend point's dimension appending values to the end
    template<typename... Ts>
    void appendValue(const Ts&... args) {
        appendValue({ args... });
    }

    // Extend point's dimension appending a vector to the end
    void appendValue(const std::vector<T> vec) {
        r.insert(r.begin(), vec.begin(), vec.end());
    }

public:

    typedef typename std::vector<T>::iterator       iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator       begin()        { return r.begin();  };
    iterator       end()          { return r.end();    };
    const_iterator cbegin() const { return r.cbegin(); };
    const_iterator cend()   const { return r.cend();   };

    // Constructors

    RPoint(void)                                       : r(std::vector<T>(0)) { };
    RPoint(const std::vector<T> vec)                   : r(vec)               { };
    RPoint(const std::initializer_list<T> ivec)        : r(ivec)              { };
    RPoint(const iterator begin, const iterator end)   : r(begin, end)        { };
    RPoint(const RPoint<T> &p)                         : r(p.r)               { };
    template<typename... Ts> RPoint(const Ts&... args) : r({ args... })       { };

    // Setters

    template<typename... Ts>
    void push_back(const Ts&... args)        { appendValue(args...); };
    void push_back(const std::vector<T> vec) { appendValue(vec);     };
    void push_back(const iterator cbegin, const iterator cend) { appendValue({ cbegin, cend }); };
    void push_back(const RPoint<T> p)        { appendValue(p.r);     };

    // Getters

    size_t size(void) { return r.size(); }

    RPoint<T> get(void) const { return *this; };
    T getX(void)              { return (*this)[0];  };
    T getY(void)              { return (*this)[1];  };
    T getZ(void)              { return (*this)[2];  };
    T x(void)                 { return (*this)[0];  };
    T y(void)                 { return (*this)[1];  };
    T z(void)                 { return (*this)[2];  };

    // Converters

    std::vector<T> toVector(void) const {
        std::vector<T> vec;
        std::copy(r.begin(), r.end(), std::back_inserter(vec));
        return vec;
    };

    template <typename U>
    std::vector<U> toVector(void) const {
        std::vector<U> vec;
        std::copy(r.begin(), r.end(), std::back_inserter(vec));
        return vec;
    };

    template <typename U>
    RPoint<U> to(void) const { return RPoint<U>((*this).toVector<U>()); };

    // Operators

    // Member access operators

    // Subscript
    T& operator[](const int index) { return r.at(index); };
    const T& operator[](const int index) const { return r.at(index); };

    // Arithmetic operators

    // Addition : point + value

    template <typename U>
    RPoint<T> operator+(const U val) {
        std::vector<T> vout = std::vector<T>(r.size());
        std::transform(r.begin(), r.end(), vout.begin(), std::bind2nd(std::plus<T>(), val));
        return RPoint<T>(vout);
    };

    // Addition : point + point

    template <typename U>
    RPoint<T> operator+(const RPoint<U> p) {
        std::vector<T> vout = p.r;
        std::transform(r.begin(), r.end(), p.r.begin(), vout.begin(), std::plus<T>());
        return RPoint<T>(vout);
    };

    // Subtraction : point - value

    template <typename U>
    RPoint<T> operator-(const U val) {
        std::vector<T> vout = std::vector<T>(r.size());
        std::transform(r.begin(), r.end(), vout.begin(), std::bind2nd(std::minus<T>(), val));
        return RPoint<T>(vout);
    };

    // Subtraction : point - point

    template <typename U>
    RPoint<T> operator-(const RPoint<U> p) {
        std::vector<T> vout = p.r;
        std::transform(r.begin(), r.end(), p.r.begin(), vout.begin(), std::minus<T>());
        return RPoint<T>(vout);
    };


    // Multiplication : point * value

    template <typename U>
    RPoint<T> operator*(const U val) {
        std::vector<T> vout = std::vector<T>(r.size());
        std::transform(r.begin(), r.end(), vout.begin(), std::bind2nd(std::multiplies<T>(), val));
        return RPoint<T>(vout);
    };

    // Multiplication : point * point

    template <typename U>
    RPoint<T> operator*(const RPoint<U> p) {
        std::vector<T> vout = p.r;
        std::transform(r.begin(), r.end(), p.r.begin(), vout.begin(), std::multiplies<T>());
        return RPoint<T>(vout);
    };

    // Division : point / value

    template <typename U>
    RPoint<T> operator/(const U val) {
        std::vector<T> vout = std::vector<T>(r.size());
        std::transform(r.begin(), r.end(), vout.begin(), std::bind2nd(std::divides<T>(), val));
        return RPoint<T>(vout);
    };

    // Division : point / point

    template <typename U>
    RPoint<T> operator/(const RPoint<U> p) {
        std::vector<T> vout = p.r;
        std::transform(r.begin(), r.end(), p.r.begin(), vout.begin(), std::divides<T>());
        return RPoint<T>(vout);
    };

    // Increment/decrement operators

    // Increment : prefix

    RPoint<T> &operator++() {
        std::transform(r.begin(), r.end(), r.begin(), std::bind2nd(std::plus<T>(), 1));
        return *this;
    };

    // Increment : postfix

    RPoint<T> operator++(int) {
        RPoint<T> p = *this;
        ++*this;
        return p;
    };

    // Decrement : prefix

    RPoint<T> &operator--() {
        std::transform(r.begin(), r.end(), r.begin(), std::bind2nd(std::minus<T>(), 1));
        return *this;
    };

    // Decrement : postfix

    RPoint<T> operator--(int) {
        RPoint<T> p = *this;
        --*this;
        return p;
    };

    // Assignment operators

    // Addition assignment : point += value

    template <typename U>
    RPoint<T> operator+=(const U val) {
        *this = *this + val;
        return *this;
    }

    // Addition assignment : point += point

    template <typename U>
    RPoint<T> operator+=(const RPoint<U> p) {
        *this = *this + p;
        return *this;
    }

    // Subtraction assignment : point -= value

    template <typename U>
    RPoint<T> operator-=(const U val) {
        *this = *this - val;
        return *this;
    }

    // Subtraction assignment : point -= point

    template <typename U>
    RPoint<T> operator-=(const RPoint<U> p) {
        *this = *this - p;
        return *this;
    }

    // Multiplication assignment : point *= value

    template <typename U>
    RPoint<T> operator*=(const U val) {
        *this = *this * val;
        return *this;
    }

    // Multiplication assignment : point *= point

    template <typename U>
    RPoint<T> operator*=(const RPoint<U> p) {
        *this = *this * p;
        return *this;
    }

    // Division assignment : point /= value

    template <typename U>
    RPoint<T> operator/=(const U val) {
        *this = *this / val;
        return *this;
    }

    // Division assignment : point /= point

    template <typename U>
    RPoint<T> operator/=(const RPoint<U> p) {
        *this = *this / p;
        return *this;
    }

    // Methods

    T min(void);
    T max(void);
    T sum(void);
    RPoint<T> add(RPoint<T> p);
    RPoint<T> sub(RPoint<T> p);
    RPoint<T> abs(void);
    RPoint<T> pow(double exponent);
    RPoint<T> sqrt(void);
    RPoint<T> dir(void);
    T dot(RPoint<T> p);

};

// Namespace

namespace rpoint {

    template <typename T>
    T sum(RPoint<T> p) {
        T res;
        std::accumulate(p.begin(), p.end(), res);
        return res;
    };

    template <typename T>
    T min(RPoint<T> p) { return *std::min_element(p.begin(), p.end()); };

    template <typename T>
    T max(RPoint<T> p) { return *std::max_element(p.begin(), p.end()); };

    template <typename T>
    RPoint<T> add(RPoint<T> p, RPoint<T> q) { return p + q; };

    template <typename T>
    RPoint<T> sub(RPoint<T> p, RPoint<T> q) { return p - q; };

    template <typename T>
    RPoint<T> abs(RPoint<T> p) {
        RPoint<T> pout;
        for(T v : p) pout.push_back(std::abs(v));
        return pout;
    };

    template <typename T>
    RPoint<T> pow(RPoint<T> p, double exponent) {
        RPoint<T> pout;
        for(T v : p) pout.push_back(std::pow(v, exponent));
        return pout;
    };

    template <typename T>
    RPoint<T> sqrt(RPoint<T> p) { return pow(p, 0.5); };

    template <typename T>
    RPoint<T> dir(RPoint<T> p) { return p / std::sqrt(p.pow(2).sum()); };

    template <typename T>
    T dot(RPoint<T> p, RPoint<T> q) { return sum(p * q); };
}


// Free Operators

template <typename T>
RPoint<T> operator+(const T &val, RPoint<T> p) { return p + val; };

template <typename T>
RPoint<T> operator-(const T &val, RPoint<T> p) { return val - p; };

template <typename T>
RPoint<T> operator*(const T &val, RPoint<T> p) { return p * val; };

template <typename T>
RPoint<T> operator/(const T &val, RPoint<T> p) { return val / p; };

// Methods

template <typename T>
T RPoint<T>::min(void) { return rpoint::min(*this); };

template <typename T>
T RPoint<T>::max(void) { return rpoint::max(*this); };

template <typename T>
T RPoint<T>::sum(void) { return rpoint::sum(*this); };

template <typename T>
RPoint<T> RPoint<T>::add(RPoint<T> p) { return rpoint::add(*this, p); };

template <typename T>
RPoint<T> RPoint<T>::sub(RPoint<T> p) { return rpoint::sub(*this, p); };

template <typename T>
RPoint<T> RPoint<T>::abs(void) { return rpoint::abs(*this); };

template <typename T>
RPoint<T> RPoint<T>::pow(double exponent) { return rpoint::pow(*this, exponent); };

template <typename T>
RPoint<T> RPoint<T>::sqrt(void) { return rpoint::sqrt(*this); };

template <typename T>
RPoint<T> RPoint<T>::dir(void) { return rpoint::dir(*this); };

template <typename T>
T RPoint<T>::dot(RPoint<T> p) { return rpoint::dot(*this, p); };

// Streams

template <typename T>
std::ostream &operator<<(std::ostream &os, const RPoint<T> &p) {

    int status = -4;

    //std::unique_ptr<char, void(*)(void*)> res {
    //    abi::__cxa_demangle(typeid(T).name(), NULL, NULL, &status),
    //    &std::free
    //};

    //const char *tname = (status == 0) ? res.get() : typeid(T).name();
    //os << "RPoint<" << tname << ">(" << *p.cbegin();

    for (typename RPoint<T>::const_iterator it = p.cbegin()+1; it != p.cend(); ++it) {
        os << ", " << *it;
    }

    os << ")";
    
    return os;
}

// Definitions

typedef RPoint<int>    RPointI;
typedef RPoint<float>  RPointF;
typedef RPoint<double> RPointD;
typedef RPoint<bool>   RPointB;

// MPI Custom Types ?

#endif // __RPOINT_HEADER__
