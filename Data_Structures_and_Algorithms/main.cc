//使用Google-test，运行所有数据结构和算法的测试用例
#include"./google_test/gtest.h"

//测试用例头文件
#include"./Sort/SortTest.h"
#include "./String/StringTest.h"

int main(int argc,char** argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
