#include <cxxtest/TestSuite.h>
#include "CIVec2D.hpp"

/*
Edit CIVec2D.cxxtest.hpp to get 100% line coverage of CIVec2D.cpp.
*/

class CIVec2DTestSuite : public CxxTest::TestSuite
{
public:
  void testAccess() {
    TS_ASSERT_EQUALS(CIVec2D(0, 0).x(), 0);
    TS_ASSERT_EQUALS(CIVec2D(0, 0).y(), 0);

    TS_ASSERT_EQUALS(CIVec2D(5, 6).x(), 5);
    TS_ASSERT_EQUALS(CIVec2D(5, 6).y(), 6);

    TS_ASSERT_EQUALS(CIVec2D(-1, -2).x(), -1);
    TS_ASSERT_EQUALS(CIVec2D(-1, -2).y(), -2);
  }

  void testEquals() {
    TS_ASSERT_EQUALS(CIVec2D(0, 0), CIVec2D(0, 0));
    TS_ASSERT_EQUALS(CIVec2D(5, 6), CIVec2D(5, 6));
    TS_ASSERT_EQUALS(CIVec2D(5, 6), CIVec2D(5, 6));
    TS_ASSERT_EQUALS(CIVec2D(-5, -6), CIVec2D(-5, -6));

    TS_ASSERT_DIFFERS(CIVec2D(0, 0), CIVec2D(0, 1));
    TS_ASSERT_DIFFERS(CIVec2D(0, 0), CIVec2D(1, 0));
    TS_ASSERT_DIFFERS(CIVec2D(1, 2), CIVec2D(2, 1));
    TS_ASSERT_DIFFERS(CIVec2D(4, 5), CIVec2D(-4, -5));
  }

  void testAddition() {
    TS_ASSERT_EQUALS(CIVec2D(0, 0) + CIVec2D(5, 6), CIVec2D(5, 6));
    TS_ASSERT_EQUALS(CIVec2D(2, 5) + CIVec2D(1, 2), CIVec2D(3, 7));
    TS_ASSERT_EQUALS(CIVec2D(1, 2) + CIVec2D(-1, -2), CIVec2D(0, 0));
  }

  void testSubtraction() {
    TS_ASSERT_EQUALS(CIVec2D(0, 0) - CIVec2D(5, 6), CIVec2D(-5, -6));
    TS_ASSERT_EQUALS(CIVec2D(2, 5) - CIVec2D(1, 2), CIVec2D(1, 3));
    TS_ASSERT_EQUALS(CIVec2D(1, 2) - CIVec2D(-1, -2), CIVec2D(2, 4));
  }

  void testDivision() {
    TS_ASSERT_EQUALS(CIVec2D(0, 0) / 1, CIVec2D(0, 0));
    TS_ASSERT_EQUALS(CIVec2D(3, 5) / 2, CIVec2D(1, 2));
    TS_ASSERT_EQUALS(CIVec2D(5, 6) / -1, CIVec2D(-5, -6));
    TS_ASSERT_THROWS_ANYTHING(CIVec2D(0, 0) / 0);
    TS_ASSERT_THROWS_ANYTHING(CIVec2D(6, 7) / 0);
  }

  void testMultiplication() {
    TS_ASSERT_EQUALS(CIVec2D(3, 4) * 2, CIVec2D(6, 8));
    TS_ASSERT_EQUALS(CIVec2D(-1, -2) * 3, CIVec2D(-3, -6));
    TS_ASSERT_EQUALS(CIVec2D(5, 6) * -1, CIVec2D(-5, -6));
    TS_ASSERT_EQUALS(CIVec2D(7, 8) * 0, CIVec2D(0, 0));
  }

  void testCompoundOperators() {
    CIVec2D v(3, 4);
    v += CIVec2D(1, 2);
    TS_ASSERT_EQUALS(v, CIVec2D(4, 6));
    v -= CIVec2D(1, 1);
    TS_ASSERT_EQUALS(v, CIVec2D(3, 5));
    v *= 2;
    TS_ASSERT_EQUALS(v, CIVec2D(6, 10));
    v /= 2;
    TS_ASSERT_EQUALS(v, CIVec2D(3, 5));
    TS_ASSERT_THROWS_ANYTHING(v /= 0);
  }

  void testNegation() {
    TS_ASSERT_EQUALS(-CIVec2D(3, 4), CIVec2D(-3, -4));
    TS_ASSERT_EQUALS(-CIVec2D(-3, -4), CIVec2D(3, 4));
    TS_ASSERT_EQUALS(-CIVec2D(0, 0), CIVec2D(0, 0));
  }

  void testDot() {
    TS_ASSERT_EQUALS(dot(CIVec2D(0, 0), CIVec2D(5, 6)), 0);
    TS_ASSERT_EQUALS(dot(CIVec2D(1, 0), CIVec2D(5, 6)), 5);
    TS_ASSERT_EQUALS(dot(CIVec2D(0, 1), CIVec2D(5, 6)), 6);
    TS_ASSERT_EQUALS(dot(CIVec2D(2, 5), CIVec2D(1, 2)), 12);
    TS_ASSERT_EQUALS(dot(CIVec2D(1, 2), CIVec2D(-1, -2)), -5);
  }
};