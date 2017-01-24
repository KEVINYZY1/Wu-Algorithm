#include"BubbleSort.h"
#include"BucketSort.h"
#include"CountSort.h"
#include"HeapSort.h"
#include"InsertSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"RadixSort.h"
#include"SelectSort.h"
#include"ShellSort.h"

#include "../google_test/gtest.h"

#include<vector>
#include<algorithm>
using namespace std;

TEST(SortTest, BubbleSort){
    vector<int> data1={1,2,3,4,5,6,7,8,9,10};
    vector<int> data2={10,9,8,7,6,5,4,3,2,1};
    vector<int> data3={5,5,5,5,5,4,4,4,4,4};
    vector<int> data4={2};
    vector<int> comparedata1={1,2,3,4,5,6,7,8,9,10};
    vector<int> comparedata2={10,9,8,7,6,5,4,3,2,1};
    vector<int> comparedata3={5,5,5,5,5,4,4,4,4,4};
    vector<int> comparedata4={2};

    sort(comparedata1.begin(),comparedata1.end());
    bubbleSort(data1);
    sort(comparedata2.begin(),comparedata2.end());
    bubbleSort(data2);
    sort(comparedata3.begin(),comparedata3.end());
    bubbleSort(data3);
    sort(comparedata4.begin(),comparedata4.end());
    bubbleSort(data4);

    EXPECT_EQ(data1,comparedata1)<<"测试升序数组排序";
    EXPECT_EQ(data2,comparedata2)<<"测试降序数组排序";
    EXPECT_EQ(data3,comparedata3)<<"测试有重复数组排序";
    EXPECT_EQ(data4,comparedata4)<<"测试只含单个元素数组排序";
}

TEST(SortTest, InsertSort){
    vector<int> data1={1,2,3,4,5,6,7,8,9,10};
    vector<int> data2={10,9,8,7,6,5,4,3,2,1};
    vector<int> data3={5,5,5,5,5,4,4,4,4,4};
    vector<int> data4={2};
    vector<int> comparedata1={1,2,3,4,5,6,7,8,9,10};
    vector<int> comparedata2={10,9,8,7,6,5,4,3,2,1};
    vector<int> comparedata3={5,5,5,5,5,4,4,4,4,4};
    vector<int> comparedata4={2};

    sort(comparedata1.begin(),comparedata1.end());
    insertSort(data1);
    sort(comparedata2.begin(),comparedata2.end());
    insertSort(data2);
    sort(comparedata3.begin(),comparedata3.end());
    insertSort(data3);
    sort(comparedata4.begin(),comparedata4.end());
    insertSort(data4);

    EXPECT_EQ(data1,comparedata1)<<"测试升序数组排序";
    EXPECT_EQ(data2,comparedata2)<<"测试降序数组排序";
    EXPECT_EQ(data3,comparedata3)<<"测试有重复数组排序";
    EXPECT_EQ(data4,comparedata4)<<"测试只含单个元素数组排序";
}