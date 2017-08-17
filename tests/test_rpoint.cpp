
#include "catch.hpp"
#include "rpoint.hpp"


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


TEST_CASE("Converting points of one type", "[converters]") {
    RPointF p(1.2f, 2.7f);

    SECTION("to vectors") {
        
        SECTION("of same type") {
            REQUIRE_NOTHROW(p.toVector<float>());
            REQUIRE(p.toVector<float>()[0] == Approx(1.2));
            REQUIRE(p.toVector<float>()[1] == Approx(2.7));
        }

        SECTION("of different type") {
            REQUIRE_NOTHROW(p.toVector<int>());
            REQUIRE(p.toVector<int>()[0] == 1);
            REQUIRE(p.toVector<int>()[1] == 2);
        }

    }

    SECTION("to another point") {

        SECTION("of same type") {
            REQUIRE_NOTHROW(p.to<float>());
            REQUIRE(p.to<float>()[0] == Approx(1.2));
            REQUIRE(p.to<float>()[1] == Approx(2.7));
        }

        SECTION("of different type") {
            REQUIRE_NOTHROW(p.to<int>());
            REQUIRE(p.to<int>().x() == 1);
            REQUIRE(p.to<int>().y() == 2);
        }

    }

}


// Operators


TEST_CASE("Operations on points", "[operators]") {

    int x = 1,  y = 2,  z = 3;
    int a = 10, b = 20, c = 30;
    int val = 10;

    RPointI p(x, y, z);
    RPointI q(a, b, c);

    SECTION("member access") {
        REQUIRE(p[0] == x);
        REQUIRE(p[1] == y);
        REQUIRE(p[2] == z);
    }

    SECTION("comparison operations") {
        RPointI r(x, x, x);
        
        SECTION("equality with") {

            SECTION("a value") {
                REQUIRE_FALSE(p == x);
                REQUIRE(r == x);
            }

            SECTION("another point") {
                REQUIRE_FALSE(p == q);
                REQUIRE(p == p);
            }

        }

        SECTION("inequality with") {

            SECTION("a value") {
                REQUIRE(p != x);
                REQUIRE_FALSE(r != x);
            }

            SECTION("another point") {
                REQUIRE(p != q);
                REQUIRE_FALSE(p != p);
            }

        }

        SECTION("less than") {

            SECTION("a value") {
                REQUIRE(p < a);
                REQUIRE_FALSE(p < y);
            }

            SECTION("another point") {
                REQUIRE(p < q);
                REQUIRE_FALSE(p < p);
            }

        }

        SECTION("less or equal to") {

            SECTION("a value") {
                REQUIRE(p <= a);
                REQUIRE_FALSE(p <= y);
            }

            SECTION("another point") {
                REQUIRE(p <= q);
                REQUIRE(p <= p);
            }

        }


        SECTION("greater than") {

            SECTION("a value") {
                REQUIRE_FALSE(p > a);
                REQUIRE(q > x);
            }

            SECTION("another point") {
                REQUIRE(q > p);
                REQUIRE_FALSE(p > q);
            }

        }

        SECTION("greater or equal to") {

            SECTION("a value") {
                REQUIRE_FALSE(p >= a);
                REQUIRE(p >= r);
                REQUIRE(q >= r);
            }

            SECTION("another point") {
                REQUIRE(q >= p);
                REQUIRE(p >= p);
                REQUIRE_FALSE(p >= q);
            }

        }

    }

    SECTION("Arithimetic operations") {

        SECTION("Addition of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p + val);
                REQUIRE((p + val)[0] == x + val);
                REQUIRE((p + val)[1] == y + val);
                REQUIRE((p + val)[2] == z + val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p + q);
                REQUIRE((p + q)[0] == x + a);
                REQUIRE((p + q)[1] == y + b);
                REQUIRE((p + q)[2] == z + c);
            }

        }

        SECTION("Subtraction of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p - val);
                REQUIRE((p - val)[0] == x - val);
                REQUIRE((p - val)[1] == y - val);
                REQUIRE((p - val)[2] == z - val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p - q);
                REQUIRE((p - q)[0] == x - a);
                REQUIRE((p - q)[1] == y - b);
                REQUIRE((p - q)[2] == z - c);
            }

        }

        SECTION("Multiplication of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p * val);
                REQUIRE((p * val)[0] == x * val);
                REQUIRE((p * val)[1] == y * val);
                REQUIRE((p * val)[2] == z * val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p * q);
                REQUIRE((p * q)[0] == x * a);
                REQUIRE((p * q)[1] == y * b);
                REQUIRE((p * q)[2] == z * c);
            }

        }

        SECTION("Division of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p / val);
                REQUIRE((p / val)[0] == x / val);
                REQUIRE((p / val)[1] == y / val);
                REQUIRE((p / val)[2] == z / val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p / q);
                REQUIRE((p / q)[0] == x / a);
                REQUIRE((p / q)[1] == y / b);
                REQUIRE((p / q)[2] == z / c);
            }

        }

    }

    SECTION("Assignment operations") {

        SECTION("Addition of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p += val);
                RPointI p(x, y, z);
                REQUIRE((p + val)[0] == x + val);
                REQUIRE((p + val)[1] == y + val);
                REQUIRE((p + val)[2] == z + val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p += q);
                RPointI p(x, y, z);
                REQUIRE((p + q)[0] == x + a);
                REQUIRE((p + q)[1] == y + b);
                REQUIRE((p + q)[2] == z + c);
            }

        }

        SECTION("Subtraction of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p -= val);
                RPointI p(x, y, z);
                REQUIRE((p - val)[0] == x - val);
                REQUIRE((p - val)[1] == y - val);
                REQUIRE((p - val)[2] == z - val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p -= q);
                RPointI p(x, y, z);
                REQUIRE((p - q)[0] == x - a);
                REQUIRE((p - q)[1] == y - b);
                REQUIRE((p - q)[2] == z - c);
            }

        }

        SECTION("Multiplication of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p *= val);
                RPointI p(x, y, z);
                REQUIRE((p * val)[0] == x * val);
                REQUIRE((p * val)[1] == y * val);
                REQUIRE((p * val)[2] == z * val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p *= q);
                RPointI p(x, y, z);
                REQUIRE((p * q)[0] == x * a);
                REQUIRE((p * q)[1] == y * b);
                REQUIRE((p * q)[2] == z * c);
            }

        }

        SECTION("Division of") {
        
            SECTION("a value") {
                REQUIRE_NOTHROW(p /= val);
                RPointI p(x, y, z);
                REQUIRE((p / val)[0] == x / val);
                REQUIRE((p / val)[1] == y / val);
                REQUIRE((p / val)[2] == z / val);
            }

            SECTION("another point") {
                REQUIRE_NOTHROW(p /= q);
                RPointI p(x, y, z);
                REQUIRE((p / q)[0] == x / a);
                REQUIRE((p / q)[1] == y / b);
                REQUIRE((p / q)[2] == z / c);
            }

        }

    }

    SECTION("Postfix") {
        
        SECTION("increment") {
            REQUIRE_NOTHROW(p++);
            REQUIRE(p[0] == ++x);
            REQUIRE(p[1] == ++y);
            REQUIRE(p[2] == ++z);
        }

        SECTION("decrement") {
            REQUIRE_NOTHROW(p--);
            REQUIRE(p[0] == --x);
            REQUIRE(p[1] == --y);
            REQUIRE(p[2] == --z);
        }

    }
    
    SECTION("Prefix") {
        
        SECTION("increment") {
            REQUIRE_NOTHROW(++p);
            REQUIRE(p[0] == ++x);
            REQUIRE(p[1] == ++y);
            REQUIRE(p[2] == ++z);
        }

        SECTION("decrement") {
            REQUIRE_NOTHROW(--p);
            REQUIRE(p[0] == --x);
            REQUIRE(p[1] == --y);
            REQUIRE(p[2] == --z);
        }
        
    }

}


// Streams


TEST_CASE("Streaming point", "[stream]") {
	int x = 1, y = 2, z = 3;
	RPointI p0(x, y, z);

	std::string p0string = "RPoint(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	
    std::ostringstream ostream;
	ostream << p0;
	
    REQUIRE(p0string == ostream.str());
}


// Methods


TEST_CASE("Methods on points", "[methods]") {

    RPointF p(1, 4, 9);
    RPointF q(-3, 4, 5);

    SECTION("from the own class") {

        SECTION("to find the minimum coordinate") {
            REQUIRE_NOTHROW(p.min());
            REQUIRE(p.min() == p[0]);
        }

        SECTION("to find the maximum coordinate") {
            REQUIRE_NOTHROW(p.max());
            REQUIRE(p.max() == p[2]);
        }

        SECTION("to sum the coordinates") {
            REQUIRE_NOTHROW(p.sum());
            REQUIRE(p.sum() == p[0] + p[1] + p[2]);
        }

        SECTION("to get the absolute value") {
            REQUIRE_NOTHROW(p.abs());
            REQUIRE(q.abs()[0] == std::abs(q[0]));
            REQUIRE(q.abs()[1] == std::abs(q[1]));
            REQUIRE(q.abs()[2] == std::abs(q[2]));
        }

        SECTION("to get the power to a value") {
            REQUIRE_NOTHROW(p.pow(2));
            REQUIRE(p.pow(2)[0] == std::pow(p[0], 2));
            REQUIRE(p.pow(2)[1] == std::pow(p[1], 2));
            REQUIRE(p.pow(2)[2] == std::pow(p[2], 2));
        }

        SECTION("to get the square root") {
            REQUIRE_NOTHROW(p.sqrt());
            REQUIRE(p.sqrt()[0] == std::sqrt(p[0]));
            REQUIRE(p.sqrt()[1] == std::sqrt(p[1]));
            REQUIRE(p.sqrt()[2] == std::sqrt(p[2]));
        }
        
        SECTION("to get the unit direction vector") {
            REQUIRE_NOTHROW(p.dir());
        }

        SECTION("to get the dot product") {
            REQUIRE_NOTHROW(p.dot(q));
            REQUIRE(p.dot(q) == p[0]*q[0] + p[1]*q[1] + p[2]*q[2]);
        }
    
    }

    SECTION("from the namespace") {
    }

}
