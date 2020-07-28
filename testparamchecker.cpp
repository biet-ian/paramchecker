#include "paramchecker.h"
#include <gtest/gtest.h>

TEST(VitalsTest, RANGE) { 
    ASSERT_EQ(false, out_of_range( -1,2,0) );
    ASSERT_EQ(true, out_of_range(-1,2,2.001) );
    ASSERT_EQ(true, out_of_range(-1,2,-1.001) );
}

TEST(VitalsTest, BPM) { 
    ASSERT_EQ(true, bpmOk(100));
    ASSERT_EQ(false, bpmOk(69));
    ASSERT_EQ(false, bpmOk(151));
}

TEST(VitalsTest, SPO2) {
    ASSERT_EQ(false, spo2Ok(40));
    ASSERT_EQ(true, spo2Ok(80.0));
}
 
TEST(VitalsTest, RESP_RATE) {
    ASSERT_EQ(true, respRateOk(50));
    ASSERT_EQ(false, respRateOk(29.99));
    ASSERT_EQ(false, respRateOk(60.01));
}

TEST(VitalsTest, VITALS) {
    vital arr1[] = {
        {vital_param::bpm,80},
        {vital_param::bpm,80},
        {vital_param::bpm,80},
    };
    ASSERT_EQ(true, vitalsAreOk( arr1, sizeof(arr1)/sizeof(arr1[0])));

    vital arr2[] = { 
        {vital_param::bpm,80},
        {vital_param::spo2,90},
        {vital_param::respRate,50},
    };
    ASSERT_EQ(true, vitalsAreOk( arr2, sizeof(arr2)/sizeof(arr2[0])));

    vital arr3[] = { 
        {vital_param::bpm,80},
        {vital_param::spo2,60},
        {vital_param::respRate,50},
    };
    ASSERT_EQ(false, vitalsAreOk( arr3, sizeof(arr3)/sizeof(arr3[0])));

    vital arr4[] = { 
        {vital_param::bpm,80},
        {vital_param::spo2,60},
        {vital_param::respRate,0},
    };
    ASSERT_EQ(false, vitalsAreOk( arr4, sizeof(arr4)/sizeof(arr4[0])));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
