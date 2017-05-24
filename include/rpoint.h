#ifndef __RPOINT_HEADER__
#define __RPOINT_HEADER__


#include <cmath>
#include <vector>
#include <iostream>


// RPoint class
template<typename T> 
class RPoint {

private:
	T xval = NULL;
	T yval = NULL;
	T zval = NULL;
	
public:
    // Constructors
	
	RPoint(void)                            {  } ;
    RPoint(const T x, const T y, const T z) { setPoint(x, y, z);  };
    RPoint(const std::vector<T> location)   { setPoint(location); };
	RPoint(const RPoint<T> &p)              { setPoint(p);        };

    // Setters

    void setPoint(const T x, const T y, const T z) {
		xval = x;
		yval = y;
		zval = z;
	};

	void setPoint(const std::vector<T> xyz) {
		xval = xyz[0];
		yval = xyz[1];
		zval = xyz[2];
	};

	void setPoint(const RPoint<T> &p) {
		xval = p.x();
		yval = p.y();
		zval = p.z();
	};

    void setX(T x) { xval = x; };
    void setY(T y) { yval = y; };
    void setZ(T z) { zval = z; };
    
    // Getters

    RPoint<T> getPoint(void) const { return *this; };

    T getX(void) const { return xval; };
    T getY(void) const { return yval; };
    T getZ(void) const { return zval; };

    T x(void) const { return xval; };
	T y(void) const { return yval; };
	T z(void) const { return zval; };

    // Converters

	std::vector<T> toStdVector(void) { return std::vector<T> {xval, yval, zval};    };

    template <typename U> 
	RPoint<U> to() const { return RPoint<U>((U)xval, (U)yval, (U)zval); };

	// Operations on Points

    RPoint<T> operator+(const RPoint<T> &p) { return RPoint(xval + p.xval, yval + p.yval, zval + p.zval); };
    RPoint<T> operator-(const RPoint<T> &p) { return RPoint(xval - p.xval, yval - p.yval, zval - p.zval); };
    RPoint<T> operator*(const RPoint<T> &p) { return RPoint(xval * p.xval, yval * p.yval, zval * p.zval); };
    RPoint<T> operator/(const RPoint<T> &p) { return RPoint(xval / p.xval, yval / p.yval, zval / p.zval); };

    RPoint<T> operator+=(const RPoint<T> &p) {
        this->xval += p.xval;
        this->yval += p.yval;
        this->zval += p.zval;

        return *this;
    };

    RPoint<T> operator-=(const RPoint<T> &p)  {
        this->xval -= p.xval;
        this->yval -= p.yval;
        this->zval -= p.zval;

        return * this;
    };

	RPoint<T> operator*=(const RPoint<T> &p) {
		this->xval *= p.xval;
		this->yval *= p.yval;
		this->zval *= p.zval;

		return *this;
	};

	RPoint<T> operator/=(const RPoint<T> &p) {
		this->xval /= p.xval;
		this->yval /= p.yval;
		this->zval /= p.zval;

		return *this;
	};

	// Prefix increment operator.  
	RPoint<T>& operator++() {
		xval++;
		yval++;
		zval++;

		return *this;
	};

	// Postfix increment operator.  
	RPoint<T> operator++(int) {
		RPoint<T> p = *this;
		++*this;

		return p;
	};

	// Prefix decrement operator.
	RPoint<T>& operator--() {
		xval--;
		yval--;
		zval--;

		return *this;
	};

	// Postfix decrement operator.  
	RPoint<T> operator--(int) {
		RPoint<T> p = *this;
		--*this;

		return p;
	};

	// Operations on values

	RPoint<T> operator+(const T &val) { return RPoint(xval + val, yval + val, zval + val); };
	RPoint<T> operator-(const T &val) { return RPoint(xval - val, yval - val, zval - val); };
	RPoint<T> operator*(const T &val) { return RPoint(xval * val, yval * val, zval * val); };
	RPoint<T> operator/(const T &val) { return RPoint(xval / val, yval / val, zval / val); };

	RPoint<T> operator+=(const T val) {
		this->xval += val;
		this->yval += val;
		this->zval += val;

		return *this;
	};

	RPoint<T> operator-=(const T val) {
		this->xval -= val;
		this->yval -= val;
		this->zval -= val;

		return *this;
	};

	RPoint<T> operator*=(const T val) {
		this->xval *= val;
		this->yval *= val;
		this->zval *= val;

		return *this;
	};

	RPoint<T> operator/=(const T val) {
		this->xval /= val;
		this->yval /= val;
		this->zval /= val;

		return *this;
	};

	// Methods
	T min(void);
	T max(void);
	T sum(void);
	RPoint<T> add(RPoint<T> p);
	RPoint<T> sub(RPoint<T> p);
	RPoint<T> abs(void);
	RPoint<T> pow(double exponent);
	RPoint<T> sqrt(void);
	T dot(RPoint<T> p);

};

// Namespace

namespace rpoint {

	template<typename T>
	T sum(RPoint<T> p) { return p.x() + p.y() + p.z(); };

	template<typename T>
	T min(RPoint<T> p) { return std::min(std::min(p.x(), p.y()), p.z()); };

	template<typename T>
	T max(RPoint<T> p) { return std::max(std::max(p.x(), p.y()), p.z()); };

	template<typename T>
	RPoint<T> add(RPoint<T> p, RPoint<T> q) { return p + q; };

	template<typename T>
	RPoint<T> sub(RPoint<T> p, RPoint<T> q) { return p - q; };

	template<typename T>
	RPoint<T> abs(RPoint<T> p) { return RPoint<T>(std::abs(p.x()), std::abs(p.y()), std::abs(p.z())); };

	template<typename T>
	RPoint<T> pow(RPoint<T> p, double exponent) { return RPoint<T>(std::pow(p.x(), exponent), std::pow(p.y(), exponent), std::pow(p.z(), exponent)); };

	template<typename T>
	RPoint<T> sqrt(RPoint<T> p) { return pow(p, 0.5); };

	template<typename T>
	T dot(RPoint<T> p, RPoint<T> q) { return sum(p*q); };

}

// Methods 

template<typename T>
T RPoint<T>::min(void) { return rpoint::min(*this); };

template<typename T>
T RPoint<T>::max(void) { return rpoint::max(*this); };

template<typename T>
T RPoint<T>::sum(void) { return rpoint::sum(*this); };

template<typename T>
RPoint<T> RPoint<T>::add(RPoint<T> p) { return rpoint::add(*this, p); };

template<typename T>
RPoint<T> RPoint<T>::sub(RPoint<T> p) { return rpoint::sub(*this, p); };

template<typename T>
RPoint<T> RPoint<T>::abs(void) { return rpoint::abs(*this); };

template<typename T>
RPoint<T> RPoint<T>::pow(double exponent) { return rpoint::pow(*this, exponent); };

template<typename T>
RPoint<T> RPoint<T>::sqrt(void) { return rpoint::sqrt(*this); };

template<typename T>
T RPoint<T>::dot(RPoint<T> p) { return rpoint::dot(*this, p); };

// Streams

template<typename T>
std::ostream & operator<<(std::ostream & os, const RPoint<T> & p) {
	os << "Point(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
	return os;
}

// Definitions

typedef RPoint<int>    RPointI;
typedef RPoint<float>  RPointF;
typedef RPoint<double> RPointD;

// MPI Custom Types ?


#endif // __RPOINT_HEADER__
