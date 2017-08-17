#ifndef __ROPERATORS_HEADER__
#define __ROPERATORS_HEADER__

#include "rexpression.hpp"


// Operators

// Addition

template <typename LHS, typename RHS>
class Addition : public Expression<Addition<LHS, RHS>> {
private:
    const LHS & _lhs;
    const RHS & _rhs;

public:
    explicit Addition(const LHS& lhs, const RHS& rhs)
        : _lhs(lhs)
        , _rhs(rhs)
    { }

    std::size_t size() const {
        return _lhs.size();
    }

    auto operator [] (std::size_t i) const {
        return _lhs[i] + _rhs[i];
    }

};


template<typename LHS, typename RHS>
Addition<LHS, RHS> operator+(const LHS & lhs, const RHS & rhs) {
    return Addition<LHS, RHS>(lhs, rhs);
}


#endif//__ROPERATORS_HEADER__
