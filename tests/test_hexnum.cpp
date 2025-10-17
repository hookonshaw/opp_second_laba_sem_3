#include "HexNum.h"
#include <gtest/gtest.h>

TEST(HexNumConstructorTest, StringConstructor) {
    HexNum h("A3F");
    HexNum expected("A3F");
    EXPECT_TRUE(equals(h, expected));
}

TEST(HexNumConstructorTest, EmptyConstructor) {
    HexNum h;
    EXPECT_TRUE(h.is_zero());
}

TEST(HexNumArithmeticTest, SubtractionNegativeResult) {
    HexNum h1("5");
    HexNum h2("A");
    HexNum res = sub(h1, h2);
    EXPECT_TRUE(res.is_zero());
}

TEST(HexNumArithmeticTest, SubtractionPositiveResult) {
    HexNum h1("A");
    HexNum h2("5");
    HexNum res = sub(h1, h2);
    EXPECT_TRUE(equals(res, HexNum("5")));
}

TEST(HexNumArithmeticTest, AdditionCheck) {
    HexNum h1("A3F");
    HexNum h2("1B4");
    HexNum res = add(h1, h2);
    EXPECT_TRUE(equals(res, HexNum("BF3")));
}

TEST(HexNumComparisonTest, Comparisons) {
    HexNum zero("0");
    HexNum one("1");
    HexNum A("A");
    
    EXPECT_TRUE(equals(zero, zero));
    EXPECT_TRUE(less(zero, one));
    EXPECT_TRUE(greater(one, zero));
    EXPECT_TRUE(less(one, A));
    EXPECT_TRUE(greater(A, one));
    EXPECT_FALSE(less(A, one));
    EXPECT_FALSE(greater(one, A));
}

TEST(HexNumCopyTest, CopyConstructor) {
    HexNum original("A3F");
    HexNum copy(original);
    
    EXPECT_TRUE(equals(copy, original));
    EXPECT_TRUE(equals(original, HexNum("A3F")));
}

TEST(HexNumEdgeCasesTest, LargeNumbers) {
    HexNum h1("FFFFFFFF");
    HexNum h2("1");
    HexNum res = add(h1, h2);
    EXPECT_TRUE(equals(res, HexNum("100000000")));
}

TEST(HexNumEdgeCasesTest, ZeroOperations) {
    HexNum zero("0");
    HexNum num("A3F");
    
    EXPECT_TRUE(equals(add(zero, num), num));
    EXPECT_TRUE(equals(add(num, zero), num));
    EXPECT_TRUE(equals(sub(num, zero), num));
    EXPECT_TRUE(sub(zero, num).is_zero());
}