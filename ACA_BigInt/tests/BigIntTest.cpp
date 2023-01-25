#include <BigInt/BigInt.h>
#include <gtest/gtest.h>

#include <vector>

using namespace ACA;
using namespace std;

TEST(BigInt, Increment) {
    const vector<pair<BigInt, BigInt>> ExpectedActualList = {
        { BigInt("0"), BigInt("1") },
        { BigInt("8"), BigInt("9") },
        { BigInt("9"), BigInt("10") },
        { BigInt("99999"), BigInt("100000") }
    };

    for (auto [num, num_plus_one] : ExpectedActualList) {
        EXPECT_EQ(++num, num_plus_one);
    }
}
TEST(BigInt,equality){
    const vector<pair<BigInt, BigInt>> ExpectedActualList = {
        { BigInt("66"), BigInt("66") },
       { BigInt("11"), BigInt("11") },
         { BigInt("12345"), BigInt("12345") },
       { BigInt("121"), BigInt("121") }
    };
    for (auto [num, num2] : ExpectedActualList) {
        EXPECT_EQ(num, num2);
    }
}

TEST(BigInt,sumOfTwoInts){
    EXPECT_EQ(BigInt("99")+BigInt("11"),BigInt("110"));
    EXPECT_EQ(BigInt("999999")+BigInt("1111"),BigInt("1001110"));
    EXPECT_EQ(BigInt("0")+BigInt("11"),BigInt("11"));
    EXPECT_EQ(BigInt("445584")+BigInt("5547"),BigInt("451131"));
    EXPECT_EQ(BigInt("888585")+BigInt("0"),BigInt("888585"));
    EXPECT_EQ(BigInt("666")+BigInt("8888"),BigInt("9554"));

}
TEST(BigInt,diferanceOfTwo){
    EXPECT_EQ(BigInt("1000")-BigInt("1"),BigInt("999"));
    EXPECT_EQ(BigInt("999999")-BigInt("11"),BigInt("999988"));
    EXPECT_EQ(BigInt("100")-BigInt("90"),BigInt("10"));
    EXPECT_EQ(BigInt("5637")-BigInt("2898"),BigInt("2739"));
    EXPECT_EQ(BigInt("10000000000")-BigInt("1"),BigInt("9999999999"));
    EXPECT_EQ(BigInt("666")-BigInt("666"),BigInt("0"));

}
TEST(BigInt,greaterFirst){
   EXPECT_TRUE(BigInt("999")>BigInt("990"));
   EXPECT_TRUE(BigInt("8888")>BigInt("999"));
   EXPECT_TRUE(BigInt("15555558")>BigInt("4888882"));
   EXPECT_TRUE(BigInt("1")>BigInt("0"));
   EXPECT_TRUE(BigInt("778899")>BigInt("778896"));
     EXPECT_TRUE(BigInt("44444")>=BigInt("44444"));
   EXPECT_TRUE(BigInt("116")>=BigInt("116"));
}
TEST(BigInt,smallerFirst){
   EXPECT_TRUE(BigInt("981")<BigInt("990"));
   EXPECT_TRUE(BigInt("88")<BigInt("999"));
   EXPECT_TRUE(BigInt("15555558")<BigInt("4888885552"));
   EXPECT_TRUE(BigInt("0")<BigInt("1"));
   EXPECT_TRUE(BigInt("7768899")<BigInt("7778896"));
   EXPECT_TRUE(BigInt("0")<=BigInt("0"));
   EXPECT_TRUE(BigInt("555")<=BigInt("555"));
}

TEST(BigInt,multipleANDdivision){
   EXPECT_TRUE((BigInt("981")*BigInt("990"))==BigInt("971190"));
   EXPECT_TRUE((BigInt("88")*BigInt("999"))==BigInt(87912));
   EXPECT_TRUE((BigInt("9999")*BigInt("222222"))==BigInt("2221997778"));
   EXPECT_TRUE((BigInt("0")*BigInt("1"))==BigInt(0));
   EXPECT_TRUE((BigInt("100000")/BigInt("50"))==BigInt(2000));
   EXPECT_TRUE((BigInt("78778")/BigInt("27"))==BigInt(2917));
  
}
TEST(BigInt,modulo){
   EXPECT_TRUE((BigInt("10001")%BigInt("10"))==BigInt("1"));
   EXPECT_TRUE((BigInt("88")%BigInt("22"))==BigInt(0));
   EXPECT_TRUE((BigInt("54151")%BigInt("222222"))==BigInt("54151"));

}

TEST(BigInt,power){
   EXPECT_TRUE((BigInt("10")^BigInt("10"))==BigInt("10000000000"));
   EXPECT_TRUE((BigInt("7")^BigInt("4"))==BigInt(2401));
   EXPECT_TRUE((BigInt("0")^BigInt("0"))==BigInt("1"));
EXPECT_TRUE((BigInt("0")^BigInt("10"))==BigInt("0"));
}
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

