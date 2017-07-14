#ifndef __RPOINT_HEADER__
#define __RPOINT_HEADER__

#include <cmath>
#include <iostream>
#include <cstdarg>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>


// RPoint class
template <typename T>
class RPoint {

private:

    std::vector<T> r = std::vector<T>(0);  // Vector containing the point values
    int dim = 0;                           // Dimension of the point

    // Setters

    // Sets values (T val1, T val2, ...)
    template<typename... Ts>
    void setValue(const Ts&... args) {
        dim = sizeof...(args);
        r = { args... };
    };

    // Sets values from a std::vector
    void setValue(const std::vector<T> vec) {
        dim = static_cast<int>(vec.size());
        std::copy(vec.begin(), vec.end(), r.begin());
    }

    // Sets values from another point
    void setValue(const RPoint<T> p) {
        dim = p.dim;
        std::copy(p.begin(), p.end(), r.begin());
    }

    // Extend point's dimension appending values to the end
    template<typename... Ts>
    void appendValue(const Ts&... args) {
        std::vector<T> vec = { args... };
        appendValue(vec);
    }

    // Extend point's dimension appending a vector to the end
    void appendValue(const std::vector<T> vec) {
        dim += static_cast<int>(vec.size());
        r.insert(r.begin(), vec.begin(), vec.end());
    }

public:

    typedef typename std::vector<T>::iterator       iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator       begin()       { return &r.begin(); };
    iterator       end()         { return &r.end();   };
    const_iterator begin() const { return r.begin();  };
    const_iterator end() const   { return r.end();    };

    // Constructors
    RPoint(void)                     {  };
    template<typename... Ts>
    RPoint(const Ts&... args)        { setValue(args...); };
    RPoint(const std::vector<T> vec) { setValue(vec);     };
    RPoint(const RPoint<T> &p)       { setValue(p);       };

    // Setters

    template<typename... Ts>
    void push_back(const Ts&... args)        { appendValue(args...); };
    void push_back(const std::vector<T> vec) { appendValue(vec);     };

    // Getters

    RPoint<T> getPoint(void) const { return *this; };
    T getX(void) { return r[0]; };
    T getY(void) { return r[1]; };
    T getZ(void) { return r[2]; };
    T x(void) { return r[0]; };
    T y(void) { return r[1]; };
    T z(void) { return r[2]; };

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
    RPoint<U> to(void) const { return toVector<U>(); };

    // Operators

    // Member access operators

    // Subscript
    T& operator[](const int index) { return r.at(index); };
    const T& operator[](const int index) const { return r.at(index); };

    // Arithmetic operators

    // Unary plus
    //RPoint<T> operator+(void) const;

    //// Addition - point + point
    //template <typename U>
    //RPoint<T> operator+(const RPoint<U> &p) const {
    //    std::vector<T> vec(p.dim);
    //    std::transform(p.begin(), p.end(), vec.begin(), std::plus<U>());
    //    return RPoint<T>(vec);
    //};

    //// Addition - point + value
    //template <typename U>
    //RPoint<T> operator+(const U val) const {
    //    std::vector<T> vec(dim, val);
    //    std::transform(r.begin(), r.end(), vec.begin(), std::plus<U>());
    //    return RPoint<T>(vec);
    //};

    // Unary minus
    //RPoint<T> operator-(void) const ;

    //// Subtraction
    //RPoint<T> operator-(const RPoint<T> &p) const {
    //    std::transform(p.begin(), p.end(), r.begin(), std::minus<T>());
    //    return *this;
    //};

    //RPoint<T> operator*(const RPoint<T> &p) const {
    //    std::transform(p.begin(), p.end(), r.begin(), std::multiplies<T>());
    //    return *this;
    //};

    //RPoint<T> operator/(const RPoint<T> &p) const {
    //    std::transform(p.begin(), p.end(), r.begin(), std::divides<T>());
    //    return *this;
    //};

};

//    void setX(T r) { xval = r; };
//    void setY(T y) { yval = y; };
//    void setZ(T z) { zval = z; };
//
//    T getX(void) const { return xval; };
//    T getY(void) const { return yval; };
//    T getZ(void) const { return zval; };
//
//    T r(void) const { return xval; };
//    T y(void) const { return yval; };
//    T z(void) const { return zval; };
//
//    // Operations on Points
//
//    RPoint<T> operator+(const RPoint<T> &p) { return RPoint(xval + p.xval, yval + p.yval, zval + p.zval); };
//    RPoint<T> operator-(const RPoint<T> &p) { return RPoint(xval - p.xval, yval - p.yval, zval - p.zval); };
//    RPoint<T> operator*(const RPoint<T> &p) { return RPoint(xval * p.xval, yval * p.yval, zval * p.zval); };
//    RPoint<T> operator/(const RPoint<T> &p) { return RPoint(xval / p.xval, yval / p.yval, zval / p.zval); };
//
//    RPoint<T> operator+=(const RPoint<T> &p) {
//        this->xval += p.xval;
//        this->yval += p.yval;
//        this->zval += p.zval;
//
//        return *this;
//    };
//
//    RPoint<T> operator-=(const RPoint<T> &p) {
//        this->xval -= p.xval;
//        this->yval -= p.yval;
//        this->zval -= p.zval;
//
//        return *this;
//    };
//
//    RPoint<T> operator*=(const RPoint<T> &p) {
//        this->xval *= p.xval;
//        this->yval *= p.yval;
//        this->zval *= p.zval;
//
//        return *this;
//    };
//
//    RPoint<T> operator/=(const RPoint<T> &p) {
//        this->xval /= p.xval;
//        this->yval /= p.yval;
//        this->zval /= p.zval;
//
//        return *this;
//    };
//
//    // Prefix increment operator.
//    RPoint<T> &operator++() {
//        xval++;
//        yval++;
//        zval++;
//
//        return *this;
//    };
//
//    // Postfix increment operator.
//    RPoint<T> operator++(int) {
//        RPoint<T> p = *this;
//        ++*this;
//
//        return p;
//    };
//
//    // Prefix decrement operator.
//    RPoint<T> &operator--() {
//        xval--;
//        yval--;
//        zval--;
//
//        return *this;
//    };
//
//    // Postfix decrement operator.
//    RPoint<T> operator--(int) {
//        RPoint<T> p = *this;
//        --*this;
//
//        return p;
//    };
//
//    // Operations on values
//
//    RPoint<T> operator+(const T &val) { return RPoint(xval + val, yval + val, zval + val); };
//    RPoint<T> operator-(const T &val) { return RPoint(xval - val, yval - val, zval - val); };
//    RPoint<T> operator*(const T &val) { return RPoint(xval * val, yval * val, zval * val); };
//    RPoint<T> operator/(const T &val) { return RPoint(xval / val, yval / val, zval / val); };
//
//    RPoint<T> operator+=(const T val) {
//        this->xval += val;
//        this->yval += val;
//        this->zval += val;
//
//        return *this;
//    };
//
//    RPoint<T> operator-=(const T val) {
//        this->xval -= val;
//        this->yval -= val;
//        this->zval -= val;
//
//        return *this;
//    };
//
//    RPoint<T> operator*=(const T val) {
//        this->xval *= val;
//        this->yval *= val;
//        this->zval *= val;
//
//        return *this;
//    };
//
//    RPoint<T> operator/=(const T val) {
//        this->xval /= val;
//        this->yval /= val;
//        this->zval /= val;
//
//        return *this;
//    };
//
//    // Methods
//
//    T min(void);
//    T max(void);
//    T sum(void);
//    RPoint<T> add(RPoint<T> p);
//    RPoint<T> sub(RPoint<T> p);
//    RPoint<T> abs(void);
//    RPoint<T> pow(double exponent);
//    RPoint<T> sqrt(void);
//    RPoint<T> dir(void);
//    T dot(RPoint<T> p);
//};
//
//// Namespace
//
//namespace rpoint {
//
//    template <typename T>
//    T sum(RPoint<T> p) { return p.r() + p.y() + p.z(); };
//
//    template <typename T>
//    T min(RPoint<T> p) { return std::min(std::min(p.r(), p.y()), p.z()); };
//
//    template <typename T>
//    T max(RPoint<T> p) { return std::max(std::max(p.r(), p.y()), p.z()); };
//
//    template <typename T>
//    RPoint<T> add(RPoint<T> p, RPoint<T> q) { return p + q; };
//
//    template <typename T>
//    RPoint<T> sub(RPoint<T> p, RPoint<T> q) { return p - q; };
//
//    template <typename T>
//    RPoint<T> abs(RPoint<T> p) { return RPoint<T>(std::abs(p.r()), std::abs(p.y()), std::abs(p.z())); };
//
//    template <typename T>
//    RPoint<T> pow(RPoint<T> p, double exponent) { return RPoint<T>(std::pow(p.r(), exponent), std::pow(p.y(), exponent), std::pow(p.z(), exponent)); };
//
//    template <typename T>
//    RPoint<T> sqrt(RPoint<T> p) { return pow(p, 0.5); };
//
//    template <typename T>
//    RPoint<T> dir(RPoint<T> p) { return p / std::sqrt(p.pow(2).sum()); };
//
//    template <typename T>
//    T dot(RPoint<T> p, RPoint<T> q) { return sum(p * q); };
//}
//

// Operators 

//template <typename T> 
//RPoint<T> RPoint<T>::operator+(void) const {
//    std::vector<T> vec(dim, 0);
//    std::transform(r.begin(), r.end(), vec.begin(), std::plus<T>());
//    return RPoint<T>(vec);
//};

//template <typename T> 
//RPoint<T> RPoint<T>::operator-(void) const {
//    RPoint<T> p(0);
//    std::transform(begin(), end(), p.begin(), std::negate<T>());
//    return &p;
//};

//// Operators on values, "free operator"
//
//template <typename T>
//RPoint<T> operator+(const T &val, RPoint<T> p) { return p + val; };
//
//template <typename T>
//RPoint<T> operator-(const T &val, RPoint<T> p) { return RPoint<T>(val - p.r(), val - p.y(), val - p.z()); };
//
//template <typename T>
//RPoint<T> operator*(const T &val, RPoint<T> p) { return p * val; };
//
//template <typename T>
//RPoint<T> operator/(const T &val, RPoint<T> p) { return RPoint<T>(val / p.r(), val / p.y(), val / p.z()); };
//
//// Methods
//
//template <typename T>
//T RPoint<T>::min(void) { return rpoint::min(*this); };
//
//template <typename T>
//T RPoint<T>::max(void) { return rpoint::max(*this); };
//
//template <typename T>
//T RPoint<T>::sum(void) { return rpoint::sum(*this); };
//
//template <typename T>
//RPoint<T> RPoint<T>::add(RPoint<T> p) { return rpoint::add(*this, p); };
//
//template <typename T>
//RPoint<T> RPoint<T>::sub(RPoint<T> p) { return rpoint::sub(*this, p); };
//
//template <typename T>
//RPoint<T> RPoint<T>::abs(void) { return rpoint::abs(*this); };
//
//template <typename T>
//RPoint<T> RPoint<T>::pow(double exponent) { return rpoint::pow(*this, exponent); };
//
//template <typename T>
//RPoint<T> RPoint<T>::sqrt(void) { return rpoint::sqrt(*this); };
//
//template <typename T>
//RPoint<T> RPoint<T>::dir(void) { return rpoint::dir(*this); };
//
//template <typename T>
//T RPoint<T>::dot(RPoint<T> p) { return rpoint::dot(*this, p); };
//
// Streams

template <typename T>
std::ostream &operator<<(std::ostream &os, const RPoint<T> &p) {
    os << "Point(" << *p.begin();

    for (std::vector<T>::const_iterator it = p.begin()+1; it != p.end(); ++it) {
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
