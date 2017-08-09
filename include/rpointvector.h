#ifndef __RPOINTVECTOR_HEADER__
#define __RPOINTVECTOR_HEADER__


#include "rpoint.h"


// RPointVector class
template<typename T>
class RPointVector {
public:

    // Definitions

    typedef typename RPoint<T>                             rpoint_t;
    typedef typename std::vector<rpoint_t>::iterator       iterator;
    typedef typename std::vector<rpoint_t>::const_iterator const_iterator;

    // Iterators

    iterator       begin()        { return v.begin();  };
    iterator       end()          { return v.end();    };
    const_iterator cbegin() const { return v.cbegin(); };
    const_iterator cend()   const { return v.cend();   };

    // Constructors

    RPointVector(void)                                       : v(std::vector<rpoint_t>(0)) { };
    RPointVector(const std::vector<rpoint_t> vec)            : v(vec) { };
    RPointVector(const std::initializer_list<rpoint_t> ivec) : v(ivec) { };
    RPointVector(const iterator begin, const iterator end)   : v(begin, end) { };
    RPointVector(const RPointVector<rpoint_t> &pv)           : v(pv.r) { };
    template<typename... Ts> RPointVector(const Ts&... args) : v({ static_cast<rpoint_t>(args)... }) { };

    // Destructors

    ~RPointVector(void) { };

    // Getters

    size_t size(void) { return v.size(); }

    // Converters

    // Operators

    // Methods

private:
    std::vector<rpoint_t> v;
};

// Namespace

// Free Operators

// Methods

// Streams

// Defenitions

typedef RPointVector<RPointI> RVectorI;
typedef RPointVector<RPointF> RVectorF;
typedef RPointVector<RPointD> RVectorD;
typedef RPointVector<RPointB> RVectorB;


#endif//__RPOINTVECTOR_HEADER__
