//#include "gtest/gtest.h"
//#include "rpoint.h"
//#include "rdistance.h"
//
//
//// Euclidean
//TEST_CASE(DistanceTest, DistanceEuclidean) {
//	RPoint<double> p(1.0, 2.0, 3.0);
//	RPoint<double> q(2.5, 6.1, 7.3);
//	double d = euclidean(p, q);
//	double r = std::sqrt(std::pow(p.x() - q.x(), 2) + std::pow(p.y() - q.y(), 2) + std::pow(p.z() - q.z(), 2));
//	EXPECT_DOUBLE_EQ(d, r);
//}
//
//// Manhattan
//TEST_CASE(DistanceTest, DistanceManhattan) {
//	RPoint<double> p(1.0, 2.0, 3.0);
//	RPoint<double> q(2.5, 6.1, 7.3);
//	double d = manhattan(p, q);
//	double r = std::abs(p.x() - q.x()) + std::abs(p.y() - q.y()) + std::abs(p.z() - q.z());
//	EXPECT_DOUBLE_EQ(d, r);
//}
//
//// Canberra
//TEST_CASE(DistanceTest, DistanceCanberra) {
//	RPoint<double> p(1.0, 2.0, 3.0);
//	RPoint<double> q(2.5, 6.1, 7.3);
//	double d = canberra(p, q);
//	double r = std::abs(p.x() - q.x()) / (std::abs(p.x()) + std::abs(q.x())) \
//		+ std::abs(p.y() - q.y()) / (std::abs(p.y()) + std::abs(q.y())) \
//		+ std::abs(p.z() - q.z()) / (std::abs(p.z()) + std::abs(q.z()));
//	EXPECT_DOUBLE_EQ(d, r);
//}
//
//// Chebyshev
//TEST_CASE(DistanceTest, DistanceChebyshev) {
//	RPoint<double> p(1.0, 2.0, 3.0);
//	RPoint<double> q(2.5, 6.1, 7.3);
//	double d = chebyshev(p, q);
//	double r = std::max(std::max(std::abs(p.x() - q.x()), std::abs(p.y() - q.y())), std::abs(p.z() - q.z()));
//	EXPECT_DOUBLE_EQ(d, r);
//}
