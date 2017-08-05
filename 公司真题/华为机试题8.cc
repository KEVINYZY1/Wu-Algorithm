/*
点. 表示1，-表示0，将二进制转换整数，其中每个序列用#隔开
其中整数对应相关字母
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct node {
    string function;
    vector<node*> v;
};

int main() {
    //构建映射表
    string mapping = "FGRSTLMNOPQWXYZUAGHIJKBCDElmnopijkfgheqrwxyzstuv";
    
    string str;
    while (cin >> str) {
        //分解输入的字符串
        int start = 0;
        string res;
        bool fool = false;
        while (start < str.size()) {
            int end = str.find_first_of('#', start);
            //转换数字
            string temp;
            if (end != string::npos) {
                temp = str.substr(start, end - start);
            } else temp = str.substr(start);

            if (temp.empty())
                res += 'F';//空字符串
            else {
                int num = 0;
                for (int i = 0; i < temp.size(); i++) {
                    if (temp[i] == '.') {
                        num *= 2;
                        num += 1;
                    } else if (temp[i] == '-') {
                        num *= 2;
                    } else { //出问题
                        fool = true;
                        goto Error;
                    }
                }
                if (!fool) 
                    res += mapping[num];
            }
        } 
        if (!fool)
            cout << res << endl;   
        Error:
            if (fool) //防止被误执行
                cout << "ERROR" << endl;    
    }
}