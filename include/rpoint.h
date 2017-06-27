#ifndef __RPOINT_HEADER__
#define __RPOINT_HEADER__

#include <cmath>
#include <iostream>
#include <cstdarg>
#include <vector>
#include <algorithm>


// RPoint class
template <typename T>
class RPoint {

private:

    std::vector<T> x = std::vector<T>(0);  // Vector containing the point values
    int dim = 0;                           // Dimension of the point

    // Setters
    // The content size sets the dimension of the class

    // Sets values (T val1, T val2, ...)
    template<typename... Ts>
    void setValue(const Ts&... args) {
        dim = sizeof...(args);
        x = { args... };
    };

    // Sets values from a std::vector
    void setValue(const std::vector<T> vec) {
        dim = static_cast<int>(vec.size());
        std::copy(vec.begin(), vec.end(), x.begin());
    }

    // Sets values from another point
    void setValue(const RPoint<T> p) {
        dim = p.dim;
        std::copy(p.begin(), p.end(), x.begin());
    }

    // Extend point's dimension appending values to the end
    template<typename... Ts>
    void appendValue(const T&... args) {
        std::vector<T> vec = { args... };
        appendValue(vec);
    }

    // Extend point's dimension appending a vector to the end
    void appendValue(const std::vector<T> vec) {
        dim += vec.size();
        x.push_back(vec);
    }

public:

    typedef typename std::vector<T>::iterator       iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator       begin()       { return &x.begin(); };
    iterator       end()         { return &x.end();   };
    const_iterator begin() const { return x.begin();  };
    const_iterator end() const   { return x.end();    };

    // Constructors

    template<typename... Ts>
    RPoint(const Ts&... args)        { setValue(args...); };
    RPoint(const std::vector<T> vec) { setValue(vec);     };
    RPoint(const RPoint<T> p)        { setValue(p);       };

    // Setters

    template<typename... Ts>
    void push_back(const Ts&... args)        { appendValue(args...); };
    void push_back(const std::vector<T> vec) { appendValue(vec);     };

    // Getters

    RPoint<T> getPoint(void) const { return *this; };

    // Converters

    std::vector<T> toVector(void) const {
        std::vector<T> vec;
        std::copy(x.begin(), x.end(), std::back_inserter(vec));
        return vec;
    };

    template <typename U>
    std::vector<U> toVector(void) const {
        std::vector<U> vec;
        std::copy(x.begin(), x.end(), std::back_inserter(vec));
        return vec;
    };

    template <typename U>
    RPoint<U> to(void) const { return toVector<U>(); };

    // Operators

    // Arithmetic operators

    // Unary plus
    template <typename U>
    RPoint<T> operator+(void) const {
        return *this;
    };

    template <typename U>
    RPoint<T> operator+(const RPoint<U> &p) const {
        std::vector<T> vec(p.dim);
        std::transform(p.begin(), p.end(), vec.begin(), std::plus<U>());
        return vec;
    };

    // Unary minus
    template <typename U>
    RPoint<T> operator-(void) const {
        std::vector<T> vec(p.dim);
        std::transform(x.begin(), x.end(), vec.begin(), std::negate<U>());
        return vec;
    };

    RPoint<T> operator-(const RPoint<T> &p) const {
        std::transform(p.begin(), p.end(), x.begin(), std::minus<T>());
        return *this;
    };

    RPoint<T> operator*(const RPoint<T> &p) const {
        std::transform(p.begin(), p.end(), x.begin(), std::multiplies<T>());
        return *this;
    };

    RPoint<T> operator/(const RPoint<T> &p) const {
        std::transform(p.begin(), p.end(), x.begin(), std::divides<T>());
        return *this;
    };

};

//    void setX(T x) { xval = x; };
//    void setY(T y) { yval = y; };
//    void setZ(T z) { zval = z; };
//
//    T getX(void) const { return xval; };
//    T getY(void) const { return yval; };
//    T getZ(void) const { return zval; };
//
//    T x(void) const { return xval; };
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
//    T sum(RPoint<T> p) { return p.x() + p.y() + p.z(); };
//
//    template <typename T>
//    T min(RPoint<T> p) { return std::min(std::min(p.x(), p.y()), p.z()); };
//
//    template <typename T>
//    T max(RPoint<T> p) { return std::max(std::max(p.x(), p.y()), p.z()); };
//
//    template <typename T>
//    RPoint<T> add(RPoint<T> p, RPoint<T> q) { return p + q; };
//
//    template <typename T>
//    RPoint<T> sub(RPoint<T> p, RPoint<T> q) { return p - q; };
//
//    template <typename T>
//    RPoint<T> abs(RPoint<T> p) { return RPoint<T>(std::abs(p.x()), std::abs(p.y()), std::abs(p.z())); };
//
//    template <typename T>
//    RPoint<T> pow(RPoint<T> p, double exponent) { return RPoint<T>(std::pow(p.x(), exponent), std::pow(p.y(), exponent), std::pow(p.z(), exponent)); };
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
//// Operators on values, "free operator"
//
//template <typename T>
//RPoint<T> operator+(const T &val, RPoint<T> p) { return p + val; };
//
//template <typename T>
//RPoint<T> operator-(const T &val, RPoint<T> p) { return RPoint<T>(val - p.x(), val - p.y(), val - p.z()); };
//
//template <typename T>
//RPoint<T> operator*(const T &val, RPoint<T> p) { return p * val; };
//
//template <typename T>
//RPoint<T> operator/(const T &val, RPoint<T> p) { return RPoint<T>(val / p.x(), val / p.y(), val / p.z()); };
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

// MPI Custom Types ?

#endif // __RPOINT_HEADER__
