
#include "catch.hpp"
#include "rpoint.h"


// Constructors

TEST_CASE("Creating points", "[constructors]") {

    SECTION("empty") {
        REQUIRE_NOTHROW(RPointI());
    }

    SECTION("from values") {

        SECTION("in 1D") {
            REQUIRE_NOTHROW(RPointI(1));
        }

        SECTION("in 2D") {
            REQUIRE_NOTHROW(RPointI(1, 2));
        }

        SECTION("in 3D") {
            REQUIRE_NOTHROW(RPointI(1, 2, 3));
        }

        SECTION("in 4D") {
            REQUIRE_NOTHROW(RPointI(1, 2, 3, 4));
        }

    }

    SECTION("from vectors") {

        SECTION("in 1D") {
            std::vector<int> vec = { 1 };
            REQUIRE_NOTHROW(RPointI(vec));
        }

        SECTION("in 2D") {
            std::vector<int> vec = { 1, 2 };
            REQUIRE_NOTHROW(RPointI(vec));
        }

        SECTION("in 3D") {
            std::vector<int> vec = { 1, 2, 3 };
            REQUIRE_NOTHROW(RPointI(vec));
        }

        SECTION("in 4D") {
            std::vector<int> vec = { 1, 2, 3, 4 };
            REQUIRE_NOTHROW(RPointI(vec));
        }

    }

    SECTION("from iterators") {

        SECTION("in 1D") {
            std::vector<int> vec = { 1 };
            REQUIRE_NOTHROW(RPointI(vec.begin(), vec.end()));
        }

        SECTION("in 2D") {
            std::vector<int> vec = { 1, 2 };
            REQUIRE_NOTHROW(RPointI(vec.begin(), vec.end()));
        }

        SECTION("in 3D") {
            std::vector<int> vec = { 1, 2, 3 };
            REQUIRE_NOTHROW(RPointI(vec.begin(), vec.end()));
        }

        SECTION("in 4D") {
            std::vector<int> vec = { 1, 2, 3, 4 };
            REQUIRE_NOTHROW(RPointI(vec.begin(), vec.end()));
        }

    }

    SECTION("from another point") {

        SECTION("in 1D") {
            RPointI p = { 1 };
            REQUIRE_NOTHROW(RPointI(p));
        }

        SECTION("in 2D") {
            RPointI p = { 1, 2 };
            REQUIRE_NOTHROW(RPointI(p));
        }

        SECTION("in 3D") {
            RPointI p = { 1, 2, 3 };
            REQUIRE_NOTHROW(RPointI(p));
        }

        SECTION("in 4D") {
            RPointI p = { 1, 2, 3, 4 };            
            REQUIRE_NOTHROW(RPointI(p));
        }

    }

}


// Setters


TEST_CASE("Setting points by pushing back", "[setters]") {

    SECTION("values") {

        SECTION("in 1D") {
            RPointI p;
            REQUIRE_NOTHROW(p.push_back(1));
        }

        SECTION("in 2D") {
            RPointI p;
            REQUIRE_NOTHROW(p.push_back(1, 2));
        }

        SECTION("in 3D") {
            RPointI p;
            REQUIRE_NOTHROW(p.push_back(1, 2, 3));
        }

        SECTION("in 4D") {
            RPointI p;
            REQUIRE_NOTHROW(p.push_back(1, 2, 3, 4));
        }

    }

    SECTION("vectors") {

        SECTION("in 1D") {
            RPointI p;
            std::vector<int> vec = { 1 };
            REQUIRE_NOTHROW(p.push_back(vec));
        }

        SECTION("in 2D") {
            RPointI p;
            std::vector<int> vec = { 1, 2 };
            REQUIRE_NOTHROW(p.push_back(vec));
        }

        SECTION("in 3D") {
            RPointI p;
            std::vector<int> vec = { 1, 2, 3 };
            REQUIRE_NOTHROW(p.push_back(vec));
        }

        SECTION("in 4D") {
            RPointI p;
            std::vector<int> vec = { 1, 2, 3, 4 };
            REQUIRE_NOTHROW(p.push_back(vec));
        }

    }

    SECTION("iterators") {

        SECTION("in 1D") {
            RPointI p;
            std::vector<int> vec = { 1 };
            REQUIRE_NOTHROW(p.push_back(vec.begin(), vec.end()));
        }

        SECTION("in 2D") {
            RPointI p;
            std::vector<int> vec = { 1, 2 };
            REQUIRE_NOTHROW(p.push_back(vec.begin(), vec.end()));
        }

        SECTION("in 3D") {
            RPointI p;
            std::vector<int> vec = { 1, 2, 3 };
            REQUIRE_NOTHROW(p.push_back(vec.begin(), vec.end()));
        }

        SECTION("in 4D") {
            RPointI p;
            std::vector<int> vec = { 1, 2, 3, 4 };
            REQUIRE_NOTHROW(p.push_back(vec.begin(), vec.end()));
        }

    }

    SECTION("another point") {

        SECTION("in 1D") {
            RPointI p, q;
            std::vector<int> vec = { 1 };
            CHECK_NOTHROW(q.push_back(vec));
            REQUIRE_NOTHROW(p.push_back(q));
        }

        SECTION("in 2D") {
            RPointI p, q;
            std::vector<int> vec = { 1, 2 };
            CHECK_NOTHROW(q.push_back(vec));
            REQUIRE_NOTHROW(p.push_back(q));
        }

        SECTION("in 3D") {
            RPointI p, q;
            std::vector<int> vec = { 1, 2, 3 };
            CHECK_NOTHROW(q.push_back(vec));
            REQUIRE_NOTHROW(p.push_back(q));
        }

        SECTION("in 4D") {
            RPointI p, q;
            std::vector<int> vec = { 1, 2, 3, 4 };
            CHECK_NOTHROW(q.push_back(vec));
            REQUIRE_NOTHROW(p.push_back(q));
        }

    }

}


// Getters


TEST_CASE("Getting point attributes", "[getters]") {
	RPointI p(1, 2);

    SECTION("with its size") {
        REQUIRE_NOTHROW(p.size());
        REQUIRE(p.size() == 2);
    }

    SECTION("from verbose methods") {
        REQUIRE_NOTHROW(p.getX());
        REQUIRE(p.getX() == 1);
        REQUIRE_NOTHROW(p.getY());
        REQUIRE(p.getY() == 2);
        REQUIRE_THROWS(p.getZ());
    }

    SECTION("from short methods") {
        REQUIRE_NOTHROW(p.x());
        REQUIRE(p.x() == 1);
        REQUIRE_NOTHROW(p.y());
        REQUIRE(p.y() == 2);
        REQUIRE_THROWS(p.z());
    }

    SECTION("from subscript access operator") {
        REQUIRE_NOTHROW(p[0]);
        REQUIRE(p[0] == 1);
        REQUIRE_NOTHROW(p[1]);
        REQUIRE(p[1] == 2);
        REQUIRE_THROWS(p[2]);
    }

}


// Converters


TEST_CASE("Converting points", "[converters]") {
    RPointF p(1.2f, 2.7f);

    SECTION("to vectors") {
        
        SECTION("of same type") {
            REQUIRE_NOTHROW(p.toVector());
            REQUIRE(p.toVector()[0] == Approx(1.2));
            REQUIRE(p.toVector()[1] == Approx(2.7));
        }

        SECTION("of different type") {
            REQUIRE_NOTHROW(p.toVector());
            REQUIRE(p.toVector<int>()[0] == 1);
            REQUIRE(p.toVector<int>()[1] == 2);
        }

    }

    SECTION("to another point") {

        SECTION("of different type") {
            REQUIRE_NOTHROW(p.to<int>());
            REQUIRE(p.to<int>().x() == 1);
            REQUIRE(p.to<int>().y() == 2);
        }

    }

}


// Operators


TEST_CASE("SubscriptMemberAccess", "[PointOperatorTest]") {
    int x = 1, y = 2, z = 3;
    RPointI p(x, y, z);
    REQUIRE(p[0] == x);
    REQUIRE(p[1] == y);
    REQUIRE(p[2] == z);
}

//TEST_CASE(PointOperatorTest, UnaryPlus) {
//    int x = 1, y = 2;
//    RPointI p(x, y);
//    (p).x();
//    EXPECT_EQ((+p).x(), x);
//    EXPECT_EQ((+p).y(), y);
//}
//
//TEST_CASE(PointOperatorTest, UnaryMinus) {
//    int x = 1, y = 2;
//    RPointI p(x, y);
//    EXPECT_EQ((-p).x(), x);
//    EXPECT_EQ((-p).y(), y);
//}

//TEST_CASE(PointOperatorTest, AdditionValue) {
//    int x = 1, y = 2, z = 3;
//    int val = 4;
//    RPointI p(x, y, z);
//    EXPECT_EQ((p+val).x(), x);
//    EXPECT_EQ(p.y(), y);
//    EXPECT_EQ(p.z(), z);
//}
//
//TEST_CASE(PointOperatorTest, AdditionPoint) {
//    int x = 1, y = 2, z = 3;
//    int a = 4, b = 5, c = 6;
//    RPointI p(x, y, z);
//    RPointI q(x, y, z);
//    EXPECT_EQ(p.x(), x);
//    EXPECT_EQ(p.y(), y);
//    EXPECT_EQ(p.z(), z);
//}

//TEST_CASE(PointOperatorTest, PointOperatorUnaryMinus) {
//    int x = 1, y = 2, z = 3;
//    RPointI p(x, y, z);
//    p = -p;
//    EXPECT_EQ(p.x(), -x);
//    EXPECT_EQ(p.y(), -y);
//    EXPECT_EQ(p.z(), -z);
//}

//TEST_CASE(PointOperatorTest, PointOperatorPointLess) {
//    int r = 1, y = 2, z = 3;
//    int a = 4, b = 5, c = 6;
//    RPointI p(r, y, z);
//    RPointI q(a, b, c);
//    EXPECT_EQ((p - q).x(), x - a);
//    EXPECT_EQ((p - q).y(), y - b);
//    EXPECT_EQ((p - q).z(), z - c);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorPointMult) {
//    float r = 1, y = 2, z = 3;
//    float a = 4, b = 5, c = 6;
//    RPointF p(r, y, z);
//    RPointF q(a, b, c);
//    EXPECT_FLOAT_EQ((p * q).r(), r * a);
//    EXPECT_FLOAT_EQ((p * q).y(), y * b);
//    EXPECT_FLOAT_EQ((p * q).z(), z * c);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorPointDiv) {
//    float r = 1, y = 2, z = 3;
//    float a = 4, b = 5, c = 6;
//    RPointF p(r, y, z);
//    RPointF q(a, b, c);
//    EXPECT_FLOAT_EQ((p / q).r(), r / a);
//    EXPECT_FLOAT_EQ((p / q).y(), y / b);
//    EXPECT_FLOAT_EQ((p / q).z(), z / c);
//}
//
//// Operators on values
//
//TEST_CASE(PointOperatorTest, PointOperatorValueAdd) {
//    int r = 1, y = 2, z = 3;
//    int a = 4, b = 5, c = 6;
//    RPointI p(r, y, z);
//    EXPECT_EQ((p + a).r(), r + a);
//    EXPECT_EQ((p + b).y(), y + b);
//    EXPECT_EQ((p + c).z(), z + c);
//    EXPECT_EQ((a + p).r(), r + a);
//    EXPECT_EQ((b + p).y(), y + b);
//    EXPECT_EQ((c + p).z(), z + c);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorValueLess) {
//    int r = 1, y = 2, z = 3;
//    int a = 4, b = 5, c = 6;
//    RPointI p(r, y, z);
//    EXPECT_EQ((p - a).r(), r - a);
//    EXPECT_EQ((p - b).y(), y - b);
//    EXPECT_EQ((p - c).z(), z - c);
//    EXPECT_EQ((a - p).r(), a - r);
//    EXPECT_EQ((b - p).y(), b - y);
//    EXPECT_EQ((c - p).z(), c - z);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorValueMult) {
//    float r = 1, y = 2, z = 3;
//    float a = 4, b = 5, c = 6;
//    RPointF p(r, y, z);
//    EXPECT_FLOAT_EQ((p * a).r(), r * a);
//    EXPECT_FLOAT_EQ((p * b).y(), y * b);
//    EXPECT_FLOAT_EQ((p * c).z(), z * c);
//    EXPECT_FLOAT_EQ((a * p).r(), r * a);
//    EXPECT_FLOAT_EQ((b * p).y(), y * b);
//    EXPECT_FLOAT_EQ((c * p).z(), z * c);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorValueDiv) {
//    float r = 1, y = 2, z = 3;
//    float a = 4, b = 5, c = 6;
//    RPointF p(r, y, z);
//    EXPECT_FLOAT_EQ((p / a).r(), r / a);
//    EXPECT_FLOAT_EQ((p / b).y(), y / b);
//    EXPECT_FLOAT_EQ((p / c).z(), z / c);
//    EXPECT_FLOAT_EQ((a / p).r(), a / r) ;
//    EXPECT_FLOAT_EQ((b / p).y(), b / y) ;
//    EXPECT_FLOAT_EQ((c / p).z(), c / z) ;
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorPostfixIncrement) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	p++;
//	r++;
//	y++;
//	z++;
//	EXPECT_EQ(p.r(), r);
//	EXPECT_EQ(p.y(), y);
//	EXPECT_EQ(p.z(), z);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorPrefixIncrement) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	++p;
//	++r;
//	++y;
//	++z;
//	EXPECT_EQ(p.r(), r);
//	EXPECT_EQ(p.y(), y);
//	EXPECT_EQ(p.z(), z);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorPostfixDecrement) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	p--;
//	r--;
//	y--;
//	z--;
//	EXPECT_EQ(p.r(), r);
//	EXPECT_EQ(p.y(), y);
//	EXPECT_EQ(p.z(), z);
//}
//
//TEST_CASE(PointOperatorTest, PointOperatorPrefixDecrement) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	--p;
//	--r;
//	--y;
//	--z;
//	EXPECT_EQ(p.r(), r);
//	EXPECT_EQ(p.y(), y);
//	EXPECT_EQ(p.z(), z);
//}
//
// Streams

TEST_CASE("PointStreamOutput", "[PointStreamTest]") {
	int x = 1, y = 2, z = 3;
	RPointI p0(x, y, z);

	std::string p0string = "Point(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	
    std::ostringstream ostream;
	ostream << p0;
	
    REQUIRE(p0string.c_str() == ostream.str().c_str());
}

//// Class methods
//
//TEST_CASE(PointClassMethodTest, PointMethodMin) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.min(), r);
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodMax) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.max(), z);
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodSum) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.sum(), r + y + z);
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodAdd) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(p.add(q).r(), (p + q).r());
//	EXPECT_EQ(p.add(q).y(), (p + q).y());
//	EXPECT_EQ(p.add(q).z(), (p + q).z());
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodSub) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(q.sub(p).r(), (q - p).r());
//	EXPECT_EQ(q.sub(p).y(), (q - p).y());
//	EXPECT_EQ(q.sub(p).z(), (q - p).z());
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodAbs) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_GE(p.abs().r(), 0);
//	EXPECT_GE(p.abs().y(), 0);
//	EXPECT_GE(p.abs().z(), 0);
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodPow) {
//	int r = 1, y = 2, z = 3;
//	int exponent = 2;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.pow(exponent).r(), std::pow(r, exponent));
//	EXPECT_EQ(p.pow(exponent).y(), std::pow(y, exponent));
//	EXPECT_EQ(p.pow(exponent).z(), std::pow(z, exponent));
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodSqrt) {
//	int r = 1, y = 4, z = 9;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.sqrt().r(), std::sqrt(r));
//	EXPECT_EQ(p.sqrt().y(), std::sqrt(y));
//	EXPECT_EQ(p.sqrt().z(), std::sqrt(z));
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodDir) {
//    float r = 1, y = 2, z = 3;
//    RPointF p(r, y, z);
//    float m = std::sqrt(std::pow(r, 2) + std::pow(y, 2) + std::pow(z, 2));
//    EXPECT_FLOAT_EQ(p.dir().r(), r / m);
//    EXPECT_FLOAT_EQ(p.dir().y(), y / m);
//    EXPECT_FLOAT_EQ(p.dir().z(), z / m);
//}
//
//TEST_CASE(PointClassMethodTest, PointMethodDot) {
//	float r = 1.0, y = 2.0, z = 3.0;
//	float a = 4.0, b = 5.0, c = 6.0;
//	RPointF p(r, y, z);
//	RPointF q(a, b, c);
//	EXPECT_FLOAT_EQ(p.dot(q), r*a + y*b + z*c);
//}
//
//// Namespace methods
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodMin) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::min(p), r);
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodMax) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::max(p), z);
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodSum) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::sum(p), r + y + z);
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodAdd) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(rpoint::add(p, q).r(), (p + q).r());
//	EXPECT_EQ(rpoint::add(p, q).y(), (p + q).y());
//	EXPECT_EQ(rpoint::add(p, q).z(), (p + q).z());
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodSub) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(rpoint::sub(q, p).r(), (q - p).r());
//	EXPECT_EQ(rpoint::sub(q, p).y(), (q - p).y());
//	EXPECT_EQ(rpoint::sub(q, p).z(), (q - p).z());
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodAbs) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_GE(rpoint::abs(p).r(), 0);
//	EXPECT_GE(rpoint::abs(p).y(), 0);
//	EXPECT_GE(rpoint::abs(p).z(), 0);
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodPow) {
//	int r = 1, y = 2, z = 3;
//	int exponent = 2;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::pow(p, exponent).r(), std::pow(r, exponent));
//	EXPECT_EQ(rpoint::pow(p, exponent).y(), std::pow(y, exponent));
//	EXPECT_EQ(rpoint::pow(p, exponent).z(), std::pow(z, exponent));
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodSqrt) {
//	int r = 1, y = 4, z = 9;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::sqrt(p).r(), std::sqrt(r));
//	EXPECT_EQ(rpoint::sqrt(p).y(), std::sqrt(y));
//	EXPECT_EQ(rpoint::sqrt(p).z(), std::sqrt(z));
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodDir) {
//    float r = 1, y = 2, z = 3;
//    RPointF p(r, y, z);
//    float m = std::sqrt(std::pow(r, 2) + std::pow(y, 2) + std::pow(z, 2));
//    EXPECT_FLOAT_EQ(rpoint::dir(p).r(), r / m);
//    EXPECT_FLOAT_EQ(rpoint::dir(p).y(), y / m);
//    EXPECT_FLOAT_EQ(rpoint::dir(p).z(), z / m);
//}
//
//TEST_CASE(PointNamespaceMethodTest, PointMethodDot) {
//	float r = 1.0, y = 2.0, z = 3.0;
//	float a = 4.0, b = 5.0, c = 6.0;
//	RPointF p(r, y, z);
//	RPointF q(a, b, c);
//	EXPECT_FLOAT_EQ(rpoint::dot(p, q), r*a + y*b + z*c);
//}
