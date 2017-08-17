#ifndef __REXPRESSION_HEADER__
#define __REXPRESSION_HEADER__

#include "rpoint.hpp"
#include "rpointvector.hpp"


template<typename E>
class Expression {
public:
    operator const E & () const {
        return *static_cast<const E*>(this);
    }
};


#endif//__REXPRESSION_HEADER__
