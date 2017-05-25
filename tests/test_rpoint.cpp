#include "gtest/gtest.h"
#include "rpoint.h"

// Setters
TEST(PointSetTest, PointSetValue) {
	RPoint<double> p;
	EXPECT_NO_THROW(p.setX(0.0));
	EXPECT_NO_THROW(p.setY(1.0));
	EXPECT_NO_THROW(p.setZ(2.0));
}

// Getters
TEST(PointGetTest, PointGetValue) {
	RPoint<double> p;
	p.setX(0.0);
	p.setY(1.0);
	p.setZ(2.0);
	EXPECT_NO_THROW(p.getX());
	EXPECT_NO_THROW(p.getY());
	EXPECT_NO_THROW(p.getZ());
}

TEST(PointGetTest, PointGetPoint) {
	RPoint<double> p;
	p.setX(0.0);
	p.setY(1.0);
	p.setZ(2.0);
	EXPECT_NO_THROW(p.getPoint());
}

// Constructors
TEST(PointCreateTest, PointCreateByValues) {
	RPoint<double> p(0.0, 1.0, 2.0);
	EXPECT_EQ(0.0, p.x());
	EXPECT_EQ(1.0, p.y());
	EXPECT_EQ(2.0, p.z());
}

TEST(PointCreateTest, PointCreateByVector) {
	std::vector<double> xyz = { 0.0, 1.0, 2.0 };
	RPoint<double> p(xyz);
	EXPECT_EQ(0.0, p.x());
	EXPECT_EQ(1.0, p.y());
	EXPECT_EQ(2.0, p.z());
}

TEST(PointCreateTest, PointCreateByPoint) {
	RPoint<double> p0(0.0, 1.0, 2.0);
	RPoint<double> p(p0);
	EXPECT_EQ(0.0, p.x());
	EXPECT_EQ(1.0, p.y());
	EXPECT_EQ(2.0, p.z());
}

// Converters
TEST(PointConvertTest, PointConvertToVector) {
	int x = 1, y = 2, z = 3;
	RPointI p0(x, y, z);
	std::vector<int> p1 = {x, y, z};
	EXPECT_EQ(p1[0], p0.x());
	EXPECT_EQ(p1[1], p0.y());
	EXPECT_EQ(p1[2], p0.z());
}

TEST(PointConvertTest, PointConvertIntToFloat) {
	float x = 1.0, y = 2.0, z = 3.0;
	RPointI p0(static_cast<int>(x), static_cast<int>(y), static_cast<int>(z));
	RPointF p1 = p0.to<float>();
	EXPECT_FLOAT_EQ(x, p1.x());
	EXPECT_FLOAT_EQ(y, p1.y());
	EXPECT_FLOAT_EQ(z, p1.z());
}

TEST(PointConvertTest, PointConvertIntToDouble) {
	double x = 1.0, y = 2.0, z = 3.0;
	RPointI p0(static_cast<int>(x), static_cast<int>(y), static_cast<int>(z));
	RPointD p1 = p0.to<double>();
	EXPECT_DOUBLE_EQ(x, p1.x());
	EXPECT_DOUBLE_EQ(y, p1.y());
	EXPECT_DOUBLE_EQ(z, p1.z());
}

TEST(PointConvertTest, PointConvertFloatToInt) {
	int x = 1, y = 2, z = 3;
	RPointF p0(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z));
	RPointI p1 = p0.to<int>();
	EXPECT_EQ(x, p1.x());
	EXPECT_EQ(y, p1.y());
	EXPECT_EQ(z, p1.z());
}

TEST(PointConvertTest, PointConvertFloatToDouble) {
	double x = 1.0, y = 2.0, z = 3.0;
	RPointI p0(static_cast<int>(x), static_cast<int>(y), static_cast<int>(z));
	RPointD p1 = p0.to<double>();
	EXPECT_DOUBLE_EQ(x, p1.x());
	EXPECT_DOUBLE_EQ(y, p1.y());
	EXPECT_DOUBLE_EQ(z, p1.z());
}

TEST(PointConvertTest, PointConvertDoubleToInt) {
	int x = 1, y = 2, z = 3;
	RPointD p0(static_cast<double>(x), static_cast<double>(y), static_cast<double>(z));
	RPointI p1 = p0.to<int>();
	EXPECT_EQ(x, p1.x());
	EXPECT_EQ(y, p1.y());
	EXPECT_EQ(z, p1.z());
}

TEST(PointConvertTest, PointConvertDoubleToFloat) {
	float x = 1.0, y = 2.0, z = 3.0;
	RPointD p0(static_cast<double>(x), static_cast<double>(y), static_cast<double>(z));
	RPointF p1 = p0.to<float>();
	EXPECT_FLOAT_EQ(x, p1.x());
	EXPECT_FLOAT_EQ(y, p1.y());
	EXPECT_FLOAT_EQ(z, p1.z());
}

// Operators
TEST(PointOperatorTest, PointOperatorPostfixIncrement) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	p++;
	x++;
	y++;
	z++;
	EXPECT_EQ(p.x(), x);
	EXPECT_EQ(p.y(), y);
	EXPECT_EQ(p.z(), z);
}

TEST(PointOperatorTest, PointOperatorPrefixIncrement) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	++p;
	++x;
	++y;
	++z;
	EXPECT_EQ(p.x(), x);
	EXPECT_EQ(p.y(), y);
	EXPECT_EQ(p.z(), z);
}

TEST(PointOperatorTest, PointOperatorPostfixDecrement) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	p--;
	x--;
	y--;
	z--;
	EXPECT_EQ(p.x(), x);
	EXPECT_EQ(p.y(), y);
	EXPECT_EQ(p.z(), z);
}

TEST(PointOperatorTest, PointOperatorPrefixDecrement) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	--p;
	--x;
	--y;
	--z;
	EXPECT_EQ(p.x(), x);
	EXPECT_EQ(p.y(), y);
	EXPECT_EQ(p.z(), z);
}

// Streams
TEST(PointStreamTest, PointStreamOutput) {
	int x = 1, y = 2, z = 3;
	RPointI p0(x, y, z);
	std::string p0string = "Point(" + std::to_string(p0.x()) + ", " + std::to_string(p0.y()) + ", " + std::to_string(p0.z()) + ")";
	std::ostringstream ostream;
	ostream << p0;
	EXPECT_STREQ(p0string.c_str(), ostream.str().c_str());
}

// Class methods

TEST(PointClassMethodTest, PointMethodMin) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_EQ(p.min(), x);
}

TEST(PointClassMethodTest, PointMethodMax) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_EQ(p.max(), z);
}

TEST(PointClassMethodTest, PointMethodSum) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_EQ(p.sum(), x + y + z);
}

TEST(PointClassMethodTest, PointMethodAdd) {
	int x = 1, y = 2, z = 3;
	int a = 4, b = 5, c = 6;
	RPointI p(x, y, z);
	RPointI q(a, b, c);
	EXPECT_EQ(p.add(q).x(), (p + q).x());
	EXPECT_EQ(p.add(q).y(), (p + q).y());
	EXPECT_EQ(p.add(q).z(), (p + q).z());
}

TEST(PointClassMethodTest, PointMethodSub) {
	int x = 1, y = 2, z = 3;
	int a = 4, b = 5, c = 6;
	RPointI p(x, y, z);
	RPointI q(a, b, c);
	EXPECT_EQ(q.sub(p).x(), (q - p).x());
	EXPECT_EQ(q.sub(p).y(), (q - p).y());
	EXPECT_EQ(q.sub(p).z(), (q - p).z());
}

TEST(PointClassMethodTest, PointMethodAbs) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_GE(p.abs().x(), 0);
	EXPECT_GE(p.abs().y(), 0);
	EXPECT_GE(p.abs().z(), 0);
}

TEST(PointClassMethodTest, PointMethodPow) {
	int x = 1, y = 2, z = 3;
	int exponent = 2;
	RPointI p(x, y, z);
	EXPECT_EQ(p.pow(exponent).x(), std::pow(x, exponent));
	EXPECT_EQ(p.pow(exponent).y(), std::pow(y, exponent));
	EXPECT_EQ(p.pow(exponent).z(), std::pow(z, exponent));
}

TEST(PointClassMethodTest, PointMethodSqrt) {
	int x = 1, y = 4, z = 9;
	RPointI p(x, y, z);
	EXPECT_EQ(p.sqrt().x(), std::sqrt(x));
	EXPECT_EQ(p.sqrt().y(), std::sqrt(y));
	EXPECT_EQ(p.sqrt().z(), std::sqrt(z));
}

TEST(PointClassMethodTest, PointMethodDot) {
	float x = 1.0, y = 2.0, z = 3.0;
	float a = 4.0, b = 5.0, c = 6.0;
	RPointF p(x, y, z);
	RPointF q(a, b, c);
	EXPECT_FLOAT_EQ(p.dot(q), x*a + y*b + z*c);
}

// Namespace methods

TEST(PointNamespaceMethodTest, PointMethodMin) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_EQ(rpoint::min(p), x);
}

TEST(PointNamespaceMethodTest, PointMethodMax) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_EQ(rpoint::max(p), z);
}

TEST(PointNamespaceMethodTest, PointMethodSum) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_EQ(rpoint::sum(p), x + y + z);
}

TEST(PointNamespaceMethodTest, PointMethodAdd) {
	int x = 1, y = 2, z = 3;
	int a = 4, b = 5, c = 6;
	RPointI p(x, y, z);
	RPointI q(a, b, c);
	EXPECT_EQ(rpoint::add(p, q).x(), (p + q).x());
	EXPECT_EQ(rpoint::add(p, q).y(), (p + q).y());
	EXPECT_EQ(rpoint::add(p, q).z(), (p + q).z());
}

TEST(PointNamespaceMethodTest, PointMethodSub) {
	int x = 1, y = 2, z = 3;
	int a = 4, b = 5, c = 6;
	RPointI p(x, y, z);
	RPointI q(a, b, c);
	EXPECT_EQ(rpoint::sub(q, p).x(), (q - p).x());
	EXPECT_EQ(rpoint::sub(q, p).y(), (q - p).y());
	EXPECT_EQ(rpoint::sub(q, p).z(), (q - p).z());
}

TEST(PointNamespaceMethodTest, PointMethodAbs) {
	int x = 1, y = 2, z = 3;
	RPointI p(x, y, z);
	EXPECT_GE(rpoint::abs(p).x(), 0);
	EXPECT_GE(rpoint::abs(p).y(), 0);
	EXPECT_GE(rpoint::abs(p).z(), 0);
}

TEST(PointNamespaceMethodTest, PointMethodPow) {
	int x = 1, y = 2, z = 3;
	int exponent = 2;
	RPointI p(x, y, z);
	EXPECT_EQ(rpoint::pow(p, exponent).x(), std::pow(x, exponent));
	EXPECT_EQ(rpoint::pow(p, exponent).y(), std::pow(y, exponent));
	EXPECT_EQ(rpoint::pow(p, exponent).z(), std::pow(z, exponent));
}

TEST(PointNamespaceMethodTest, PointMethodSqrt) {
	int x = 1, y = 4, z = 9;
	RPointI p(x, y, z);
	EXPECT_EQ(rpoint::sqrt(p).x(), std::sqrt(x));
	EXPECT_EQ(rpoint::sqrt(p).y(), std::sqrt(y));
	EXPECT_EQ(rpoint::sqrt(p).z(), std::sqrt(z));
}

TEST(PointNamespaceMethodTest, PointMethodDot) {
	float x = 1.0, y = 2.0, z = 3.0;
	float a = 4.0, b = 5.0, c = 6.0;
	RPointF p(x, y, z);
	RPointF q(a, b, c);
	EXPECT_FLOAT_EQ(rpoint::dot(p, q), x*a + y*b + z*c);
}
