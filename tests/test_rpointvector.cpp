
#include "catch.hpp"
//#include "rpoint.hpp"
#include "rpointvector.hpp"


TEST_CASE("Creating point vectors", "[constructors]") {

    SECTION("that are empty") {
        REQUIRE_NOTHROW(RVectorI());
    }

    SECTION("from a vector of points") {
        RPointI p(0, 1, 2);
        std::vector<RPointI> v(10, p);

        REQUIRE_NOTHROW(RVectorI(v));
        RVectorI vp(v);

        for (RPointI i : vp) {
            REQUIRE(i == p);
        }
    }


    SECTION("from iterators") {
        RPointI p(0, 1, 2);
        std::vector<RPointI> v(10, p);
        
        REQUIRE_NOTHROW(RVectorI(v.begin(), v.end()));
        RVectorI vp(v.begin(), v.end());

        for (RPointI i : vp) {
            REQUIRE(i == p);
        }
    }

    SECTION("from an initializer_list of points") {
        RPointI p(0, 1, 2);

        REQUIRE_NOTHROW(RVectorI({ p, p, p, p, p, p }));
        RVectorI vp = {p, p, p, p, p, p};

        for (RPointI i : vp) {
            REQUIRE(i == p);
        }
    }

    SECTION("from another point vector") {
        RPointI p(0, 1, 2);
        RVectorI v1 = { p, p, p, p, p, p };

        REQUIRE_NOTHROW(RVectorI(v1));
        RVectorI v2(v1);

        for (RPointI i : v2) {
            REQUIRE(i == p);
        }
    }

    SECTION("from points") {
        RPointI p(0, 1, 2);

        REQUIRE_NOTHROW(RVectorI(p, p, p, p, p));
        RVectorI v(p, p, p, p, p);

        for (RPointI i : v) {
            REQUIRE(i == p);
        }
    }

}

TEST_CASE("Get from point vectors", "[getters]") {
    int x = 0, y = 1, z = 2;
    RPointI p(x, y, z);

    REQUIRE_NOTHROW(RVectorI(p, p, p, p, p));
    RVectorI v(p, p, p, p, p);

    SECTION("a vector containing the individual") {
        SECTION("x-coordinate values") {
            std::vector<int> rvec(v.getX());

            for (int i : rvec) {
                REQUIRE(i == x);
            }
        }

        SECTION("y-coordinate values") {
            std::vector<int> rvec(v.getY());

            for (int i : rvec) {
                REQUIRE(i == y);
            }
        }

        SECTION("z-coordinate values") {
            std::vector<int> rvec(v.getZ());

            for (int i : rvec) {
                REQUIRE(i == z);
            }
        }

        SECTION("i-coordinate values") {
            std::vector<int> rvec(v.getIndex(2));

            for (int i : rvec) {
                REQUIRE(i == z);
            }
        }
    }

}

TEST_CASE("", "[converters]") {

}

TEST_CASE("", "[operators]") {

}

TEST_CASE("", "[methods]") {

}

TEST_CASE("", "[streams]") {

}
