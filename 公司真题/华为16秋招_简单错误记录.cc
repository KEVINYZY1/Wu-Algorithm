/*
题目描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325


输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符

输入例子:
E:\V1R2\product\fpgadrive.c 1325

输出例子:
fpgadrive.c 1325 1
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

//华为很喜欢出这种输出的题目啊
int main(){
	string s;
    map<string, pair<int, int>> m;
    int count = 0;
    while(cin >> s){
        stringstream ss;
        ss << s;
        string path;
        ss >> path;
        string rows;
        ss >> rows;
        //处理路径
        auto pos = path.find_last_of('\\');
        if(pos != string::npos){//如果没找到'\\'
            path = path.substr(pos+1);
        }
        //路径长于16字符
        if(path.size() > 16){
            path = path.substr(path.size()-16, 16);
        }
        //文件名称和行号完全匹配
        path = path + ' ' + rows;
        m[path].first++;//错误记录数
        m[path].second = count++;//排位，数目相同的情况下，按照输入第一次出现顺序排序
    }
    vector<pair<string, pair<int, int>>> v(m.begin(), m.end());
    //数目相同的情况下，按照输入第一次出现顺序排序
    sort(v.begin(), v.end(), [](pair<string, pair<int, int>> l, pair<string, pair<int, int>> r){
        if (l.second.first > r.second.first)
            return true;
        else if(l.second.first == r.second.first){
            return l.second.second < r.second.second;
        }
        else return false;
    });
    for(int i = 0; i < v.size() && i < 8; i++){
        cout << v[i].first << ' ' << v[i].second.first << endl;
    }
}