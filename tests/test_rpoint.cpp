#include "gtest/gtest.h"
#include "rpoint.h"


// Setters

TEST(PointSetTest, PushBackValues1D) {
    RPointI p;
    EXPECT_NO_THROW(p.push_back(1));
}

TEST(PointSetTest, PushBackValues2D) {
    RPointI p;
    EXPECT_NO_THROW(p.push_back(1, 2));
}

TEST(PointSetTest, PushBackValues3D) {
    RPointI p;
    EXPECT_NO_THROW(p.push_back(1, 2, 3));
}

TEST(PointSetTest, PushBackValues4D) {
    RPointI p;
    EXPECT_NO_THROW(p.push_back(1, 2, 3, 4));
}

TEST(PointSetTest, PushBackVector1D) {
    RPointI p;
    std::vector<int> vec = { 1 };
    EXPECT_NO_THROW(p.push_back(vec));
}

TEST(PointSetTest, PushBackVector2D) {
    RPointI p;
    std::vector<int> vec = { 1, 2 };
    EXPECT_NO_THROW(p.push_back(vec));
}

TEST(PointSetTest, PushBackVector3D) {
    RPointI p;
    std::vector<int> vec = { 1, 2, 3 };
    EXPECT_NO_THROW(p.push_back(vec));
}

TEST(PointSetTest, PushBackVector4D) {
    RPointI p;
    std::vector<int> vec = { 1, 2, 3, 4 };
    EXPECT_NO_THROW(p.push_back(vec));
}

//TEST(PointSetTest, PointSetValue) {
//	RPoint<double> p;
//	EXPECT_NO_THROW(p.setX(0.0));
//	EXPECT_NO_THROW(p.setY(1.0));
//	EXPECT_NO_THROW(p.setZ(2.0));
//}
//
//// Getters
//TEST(PointGetTest, PointGetValue) {
//	RPoint<double> p;
//	p.setX(0.0);
//	p.setY(1.0);
//	p.setZ(2.0);
//	EXPECT_NO_THROW(p.getX());
//	EXPECT_NO_THROW(p.getY());
//	EXPECT_NO_THROW(p.getZ());
//}
//
//TEST(PointGetTest, PointGetPoint) {
//	RPoint<double> p;
//	p.setX(0.0);
//	p.setY(1.0);
//	p.setZ(2.0);
//	EXPECT_NO_THROW(p.getPoint());
//}
//
//// Constructors
//TEST(PointCreateTest, PointCreateByValues) {
//	RPoint<double> p(0.0, 1.0, 2.0);
//	EXPECT_EQ(0.0, p.r());
//	EXPECT_EQ(1.0, p.y());
//	EXPECT_EQ(2.0, p.z());
//}

//TEST(PointCreateTest, PointCreateByVector) {
//	std::vector<double> vec = { 0.0, 1.0, 2.0 };
//	RPoint<double> p(vec);
//	EXPECT_EQ(0.0, p.r());
//	EXPECT_EQ(1.0, p.y());
//	EXPECT_EQ(2.0, p.z());
//}

//TEST(PointCreateTest, PointCreateByPoint) {
//	RPoint<double> p0(0.0, 1.0, 2.0);
//	RPoint<double> p(p0);
//	EXPECT_EQ(0.0, p.r());
//	EXPECT_EQ(1.0, p.y());
//	EXPECT_EQ(2.0, p.z());
//}
//
//// Converters
//TEST(PointConvertTest, PointConvertToVector) {
//	int r = 1, y = 2, z = 3;
//	RPointI p0(r, y, z);
//	std::vector<int> p1 = {r, y, z};
//	EXPECT_EQ(p1[0], p0.r());
//	EXPECT_EQ(p1[1], p0.y());
//	EXPECT_EQ(p1[2], p0.z());
//}
//
//TEST(PointConvertTest, PointConvertIntToFloat) {
//	float r = 1.0, y = 2.0, z = 3.0;
//	RPointI p0(static_cast<int>(r), static_cast<int>(y), static_cast<int>(z));
//	RPointF p1 = p0.to<float>();
//	EXPECT_FLOAT_EQ(r, p1.r());
//	EXPECT_FLOAT_EQ(y, p1.y());
//	EXPECT_FLOAT_EQ(z, p1.z());
//}
//
//TEST(PointConvertTest, PointConvertIntToDouble) {
//	double r = 1.0, y = 2.0, z = 3.0;
//	RPointI p0(static_cast<int>(r), static_cast<int>(y), static_cast<int>(z));
//	RPointD p1 = p0.to<double>();
//	EXPECT_DOUBLE_EQ(r, p1.r());
//	EXPECT_DOUBLE_EQ(y, p1.y());
//	EXPECT_DOUBLE_EQ(z, p1.z());
//}
//
//TEST(PointConvertTest, PointConvertFloatToInt) {
//	int r = 1, y = 2, z = 3;
//	RPointF p0(static_cast<float>(r), static_cast<float>(y), static_cast<float>(z));
//	RPointI p1 = p0.to<int>();
//	EXPECT_EQ(r, p1.r());
//	EXPECT_EQ(y, p1.y());
//	EXPECT_EQ(z, p1.z());
//}
//
//TEST(PointConvertTest, PointConvertFloatToDouble) {
//	double r = 1.0, y = 2.0, z = 3.0;
//	RPointI p0(static_cast<int>(r), static_cast<int>(y), static_cast<int>(z));
//	RPointD p1 = p0.to<double>();
//	EXPECT_DOUBLE_EQ(r, p1.r());
//	EXPECT_DOUBLE_EQ(y, p1.y());
//	EXPECT_DOUBLE_EQ(z, p1.z());
//}
//
//TEST(PointConvertTest, PointConvertDoubleToInt) {
//	int r = 1, y = 2, z = 3;
//	RPointD p0(static_cast<double>(r), static_cast<double>(y), static_cast<double>(z));
//	RPointI p1 = p0.to<int>();
//	EXPECT_EQ(r, p1.r());
//	EXPECT_EQ(y, p1.y());
//	EXPECT_EQ(z, p1.z());
//}
//
//TEST(PointConvertTest, PointConvertDoubleToFloat) {
//	float r = 1.0, y = 2.0, z = 3.0;
//	RPointD p0(static_cast<double>(r), static_cast<double>(y), static_cast<double>(z));
//	RPointF p1 = p0.to<float>();
//	EXPECT_FLOAT_EQ(r, p1.r());
//	EXPECT_FLOAT_EQ(y, p1.y());
//	EXPECT_FLOAT_EQ(z, p1.z());
//}
//

// Operators

TEST(PointOperatorTest, SubscriptMemberAccess) {
    int x = 1, y = 2, z = 3;
    RPointI p(x, y, z);
    EXPECT_EQ(p[0], x);
    EXPECT_EQ(p[1], y);
    EXPECT_EQ(p[2], z);
}

//TEST(PointOperatorTest, UnaryPlus) {
//    int x = 1, y = 2;
//    RPointI p(x, y);
//    (p).x();
//    EXPECT_EQ((+p).x(), x);
//    EXPECT_EQ((+p).y(), y);
//}
//
//TEST(PointOperatorTest, UnaryMinus) {
//    int x = 1, y = 2;
//    RPointI p(x, y);
//    EXPECT_EQ((-p).x(), x);
//    EXPECT_EQ((-p).y(), y);
//}

//TEST(PointOperatorTest, AdditionValue) {
//    int x = 1, y = 2, z = 3;
//    int val = 4;
//    RPointI p(x, y, z);
//    EXPECT_EQ((p+val).x(), x);
//    EXPECT_EQ(p.y(), y);
//    EXPECT_EQ(p.z(), z);
//}
//
//TEST(PointOperatorTest, AdditionPoint) {
//    int x = 1, y = 2, z = 3;
//    int a = 4, b = 5, c = 6;
//    RPointI p(x, y, z);
//    RPointI q(x, y, z);
//    EXPECT_EQ(p.x(), x);
//    EXPECT_EQ(p.y(), y);
//    EXPECT_EQ(p.z(), z);
//}

//TEST(PointOperatorTest, PointOperatorUnaryMinus) {
//    int x = 1, y = 2, z = 3;
//    RPointI p(x, y, z);
//    p = -p;
//    EXPECT_EQ(p.x(), -x);
//    EXPECT_EQ(p.y(), -y);
//    EXPECT_EQ(p.z(), -z);
//}

//TEST(PointOperatorTest, PointOperatorPointLess) {
//    int r = 1, y = 2, z = 3;
//    int a = 4, b = 5, c = 6;
//    RPointI p(r, y, z);
//    RPointI q(a, b, c);
//    EXPECT_EQ((p - q).x(), x - a);
//    EXPECT_EQ((p - q).y(), y - b);
//    EXPECT_EQ((p - q).z(), z - c);
//}
//
//TEST(PointOperatorTest, PointOperatorPointMult) {
//    float r = 1, y = 2, z = 3;
//    float a = 4, b = 5, c = 6;
//    RPointF p(r, y, z);
//    RPointF q(a, b, c);
//    EXPECT_FLOAT_EQ((p * q).r(), r * a);
//    EXPECT_FLOAT_EQ((p * q).y(), y * b);
//    EXPECT_FLOAT_EQ((p * q).z(), z * c);
//}
//
//TEST(PointOperatorTest, PointOperatorPointDiv) {
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
//TEST(PointOperatorTest, PointOperatorValueAdd) {
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
//TEST(PointOperatorTest, PointOperatorValueLess) {
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
//TEST(PointOperatorTest, PointOperatorValueMult) {
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
//TEST(PointOperatorTest, PointOperatorValueDiv) {
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
//TEST(PointOperatorTest, PointOperatorPostfixIncrement) {
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
//TEST(PointOperatorTest, PointOperatorPrefixIncrement) {
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
//TEST(PointOperatorTest, PointOperatorPostfixDecrement) {
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
//TEST(PointOperatorTest, PointOperatorPrefixDecrement) {
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

TEST(PointStreamTest, PointStreamOutput) {
	int x = 1, y = 2, z = 3;
	RPointI p0(x, y, z);

	std::string p0string = "Point(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	
    std::ostringstream ostream;
	ostream << p0;
	
    EXPECT_STREQ(p0string.c_str(), ostream.str().c_str());
}

//// Class methods
//
//TEST(PointClassMethodTest, PointMethodMin) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.min(), r);
//}
//
//TEST(PointClassMethodTest, PointMethodMax) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.max(), z);
//}
//
//TEST(PointClassMethodTest, PointMethodSum) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.sum(), r + y + z);
//}
//
//TEST(PointClassMethodTest, PointMethodAdd) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(p.add(q).r(), (p + q).r());
//	EXPECT_EQ(p.add(q).y(), (p + q).y());
//	EXPECT_EQ(p.add(q).z(), (p + q).z());
//}
//
//TEST(PointClassMethodTest, PointMethodSub) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(q.sub(p).r(), (q - p).r());
//	EXPECT_EQ(q.sub(p).y(), (q - p).y());
//	EXPECT_EQ(q.sub(p).z(), (q - p).z());
//}
//
//TEST(PointClassMethodTest, PointMethodAbs) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_GE(p.abs().r(), 0);
//	EXPECT_GE(p.abs().y(), 0);
//	EXPECT_GE(p.abs().z(), 0);
//}
//
//TEST(PointClassMethodTest, PointMethodPow) {
//	int r = 1, y = 2, z = 3;
//	int exponent = 2;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.pow(exponent).r(), std::pow(r, exponent));
//	EXPECT_EQ(p.pow(exponent).y(), std::pow(y, exponent));
//	EXPECT_EQ(p.pow(exponent).z(), std::pow(z, exponent));
//}
//
//TEST(PointClassMethodTest, PointMethodSqrt) {
//	int r = 1, y = 4, z = 9;
//	RPointI p(r, y, z);
//	EXPECT_EQ(p.sqrt().r(), std::sqrt(r));
//	EXPECT_EQ(p.sqrt().y(), std::sqrt(y));
//	EXPECT_EQ(p.sqrt().z(), std::sqrt(z));
//}
//
//TEST(PointClassMethodTest, PointMethodDir) {
//    float r = 1, y = 2, z = 3;
//    RPointF p(r, y, z);
//    float m = std::sqrt(std::pow(r, 2) + std::pow(y, 2) + std::pow(z, 2));
//    EXPECT_FLOAT_EQ(p.dir().r(), r / m);
//    EXPECT_FLOAT_EQ(p.dir().y(), y / m);
//    EXPECT_FLOAT_EQ(p.dir().z(), z / m);
//}
//
//TEST(PointClassMethodTest, PointMethodDot) {
//	float r = 1.0, y = 2.0, z = 3.0;
//	float a = 4.0, b = 5.0, c = 6.0;
//	RPointF p(r, y, z);
//	RPointF q(a, b, c);
//	EXPECT_FLOAT_EQ(p.dot(q), r*a + y*b + z*c);
//}
//
//// Namespace methods
//
//TEST(PointNamespaceMethodTest, PointMethodMin) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::min(p), r);
//}
//
//TEST(PointNamespaceMethodTest, PointMethodMax) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::max(p), z);
//}
//
//TEST(PointNamespaceMethodTest, PointMethodSum) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::sum(p), r + y + z);
//}
//
//TEST(PointNamespaceMethodTest, PointMethodAdd) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(rpoint::add(p, q).r(), (p + q).r());
//	EXPECT_EQ(rpoint::add(p, q).y(), (p + q).y());
//	EXPECT_EQ(rpoint::add(p, q).z(), (p + q).z());
//}
//
//TEST(PointNamespaceMethodTest, PointMethodSub) {
//	int r = 1, y = 2, z = 3;
//	int a = 4, b = 5, c = 6;
//	RPointI p(r, y, z);
//	RPointI q(a, b, c);
//	EXPECT_EQ(rpoint::sub(q, p).r(), (q - p).r());
//	EXPECT_EQ(rpoint::sub(q, p).y(), (q - p).y());
//	EXPECT_EQ(rpoint::sub(q, p).z(), (q - p).z());
//}
//
//TEST(PointNamespaceMethodTest, PointMethodAbs) {
//	int r = 1, y = 2, z = 3;
//	RPointI p(r, y, z);
//	EXPECT_GE(rpoint::abs(p).r(), 0);
//	EXPECT_GE(rpoint::abs(p).y(), 0);
//	EXPECT_GE(rpoint::abs(p).z(), 0);
//}
//
//TEST(PointNamespaceMethodTest, PointMethodPow) {
//	int r = 1, y = 2, z = 3;
//	int exponent = 2;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::pow(p, exponent).r(), std::pow(r, exponent));
//	EXPECT_EQ(rpoint::pow(p, exponent).y(), std::pow(y, exponent));
//	EXPECT_EQ(rpoint::pow(p, exponent).z(), std::pow(z, exponent));
//}
//
//TEST(PointNamespaceMethodTest, PointMethodSqrt) {
//	int r = 1, y = 4, z = 9;
//	RPointI p(r, y, z);
//	EXPECT_EQ(rpoint::sqrt(p).r(), std::sqrt(r));
//	EXPECT_EQ(rpoint::sqrt(p).y(), std::sqrt(y));
//	EXPECT_EQ(rpoint::sqrt(p).z(), std::sqrt(z));
//}
//
//TEST(PointNamespaceMethodTest, PointMethodDir) {
//    float r = 1, y = 2, z = 3;
//    RPointF p(r, y, z);
//    float m = std::sqrt(std::pow(r, 2) + std::pow(y, 2) + std::pow(z, 2));
//    EXPECT_FLOAT_EQ(rpoint::dir(p).r(), r / m);
//    EXPECT_FLOAT_EQ(rpoint::dir(p).y(), y / m);
//    EXPECT_FLOAT_EQ(rpoint::dir(p).z(), z / m);
//}
//
//TEST(PointNamespaceMethodTest, PointMethodDot) {
//	float r = 1.0, y = 2.0, z = 3.0;
//	float a = 4.0, b = 5.0, c = 6.0;
//	RPointF p(r, y, z);
//	RPointF q(a, b, c);
//	EXPECT_FLOAT_EQ(rpoint::dot(p, q), r*a + y*b + z*c);
//}
