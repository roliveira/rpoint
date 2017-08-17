
#include "catch.hpp"
#include "rpoint.hpp"
#include "rdistance.hpp"



TEST_CASE("Calculate the distance between two points using the ", "[distance]") {

    // Euclidean
    SECTION("Euclidean method") {
        RPoint<double> p(1.0, 2.0, 3.0);
        RPoint<double> q(2.5, 6.1, 7.3);
        double d = euclidean(p, q);
        double r = std::sqrt(std::pow(q.x() - p.x(), 2) + std::pow(q.y() - p.y(), 2) + std::pow(q.z() - p.z(), 2));
        REQUIRE(d == Approx(r));
    }

    // Manhattan
    SECTION("Manhattan method") {
        RPoint<double> p(1.0, 2.0, 3.0);
        RPoint<double> q(2.5, 6.1, 7.3);
        double d = manhattan(p, q);
        double r = std::abs(p.x() - q.x()) + std::abs(p.y() - q.y()) + std::abs(p.z() - q.z());
        REQUIRE(d == Approx(r));
    }

    // Canberra
    SECTION("Canberra method") {
        RPoint<double> p(1.0, 2.0, 3.0);
        RPoint<double> q(2.5, 6.1, 7.3);
        double d = canberra(p, q);
        double r = std::abs(p.x() - q.x()) / (std::abs(p.x()) + std::abs(q.x())) \
            + std::abs(p.y() - q.y()) / (std::abs(p.y()) + std::abs(q.y())) \
            + std::abs(p.z() - q.z()) / (std::abs(p.z()) + std::abs(q.z()));
        REQUIRE(d == Approx(r));
    }

    // Chebyshev
    SECTION("Chebyshev method") {
        RPoint<double> p(1.0, 2.0, 3.0);
        RPoint<double> q(2.5, 6.1, 7.3);
        double d = chebyshev(p, q);
        double r = std::max(std::max(std::abs(p.x() - q.x()), std::abs(p.y() - q.y())), std::abs(p.z() - q.z()));
        REQUIRE(d == Approx(r));
    }

}