/*

请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。

所有的IP地址划分为 A,B,C,D,E五类

A类地址1.0.0.0~126.255.255.255;

B类地址128.0.0.0~191.255.255.255;

C类地址192.0.0.0~223.255.255.255;

D类地址224.0.0.0~239.255.255.255；

E类地址240.0.0.0~255.255.255.255



私网IP范围是：

10.0.0.0～10.255.255.255

172.16.0.0～172.31.255.255

192.168.0.0～192.168.255.255



子网掩码为前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
本题暂时默认以0开头的IP地址是合法的，比如0.1.1.2，是合法地址


输入描述:
多行字符串。每行一个IP地址和掩码，用~隔开。


输出描述:
统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开。
示例1
输入

10.70.44.68~255.254.255.0
1.0.0.1~255.0.0.0
192.168.0.2~255.255.255.0
19..0.~255.255.255.0
输出

1 0 1 0 0 2 1
*/
/** 
  * 1. Mask 255.255.255.255 , 0.0.0.0 为非法。
  * 2. IP和Mask必须同时正确，才能被分类到A, B, C, D, E以及私有。
  * 3. IP和Mask同时错误时，只算一次错误
  * 4. 注意0.*.*.*以及127.*.*.*不属于任何类别。
  */
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

// 初步判断输入的点十分进制表示法是否正确
bool isValid(const string& str, vector<int> & data) {
    for(int i=0; i<str.size(); ++i) {
        int j = i;
        for(; j<=str.size(); ++j)
            if(str[j] == '.' || j == str.size()) {
                string number(str.begin()+i, str.begin()+j);
                if(number.empty())
                    return false;
                int num = atoi(number.c_str());
                data.push_back(num);
                break;
            }
        i = j;
    }
 
    if(data.size() != 4)
        return false;
 
    for(int i=0; i<data.size(); ++i)
        if(data[i]<0 || data[i]>255)
            return false;
 
    return true;
}
 
// 判断IP地址是否正确
bool ipValidHandle(const string& ip, vector<int> & data) {
    return isValid(ip, data); 
}
 
// 将整形转化为二进制表示，只取低8位 128 --> 10000000
void dec2binary(int num, list<char> & mask_binary) {
    for(int i=0; i<8; ++i) {
        mask_binary.push_front((num & 1)+'0');
        num = num>>1;
    }
}
 
// 判断子网掩码是否正确
bool maskValidHandle(const string& mask) {
    vector<int> res;
    list<char> mask_binary;
    if(!isValid(mask, res))
        return false;
     
    // 将子网掩码转化为二进制的字符串表示
    // 255.255.255.0 --> 1111111111111111111111110000000
    for(int i=res.size()-1; i>=0; --i)
        dec2binary(res[i], mask_binary);
     
    bool find1 = false, find0 = false;
    for(list<char>::iterator it=mask_binary.begin(); it!=mask_binary.end(); ++it)
        if(!find1 && *it == '1')
            find1 = true;
        else if(!find0 && *it== '0')
            find0 = true;
        else if(find0 && *it== '1')
            return false;
 
    if(find0 && find1)
        return true;
    return false;
}
 
int main() {
    string line;
    int ip_A = 0, ip_B = 0, ip_C = 0, ip_D = 0;
    int ip_E = 0, ip_Err = 0, ip_private = 0;
 
    while(getline(cin, line)) {
        for(int i=0; i<line.size(); ++i)
            if(line[i] == '~') {
                string ip(line.begin(), line.begin()+i);
                string mask(line.begin()+i+1, line.end());
                vector<int> data;
                if(ipValidHandle(ip, data) && maskValidHandle(mask)) {
                    if(data[0] >=1 && data[0] <= 126) {
                        if(data[0] == 10)
                            ip_private++;
                        ip_A++;
                    }
                    else if(data[0] >=128 && data[0]<=191 ) {
                        if(data[0] == 172 && (data[1]>=16 && data[1]<=31))
                            ip_private++;
                        ip_B++;
                    }
                    else if(data[0] >=192 && data[0] <= 223) {
                        if(data[0] == 192 && data[1]==168)
                            ip_private++;
                        ip_C++;
                    }
                    else if(data[0] >=224 && data[0] <= 239)
                        ip_D++;
                    else if(data[0] >=240 && data[0] <= 255)
                        ip_E++;
                }
                else
                    ++ip_Err;
                break;
            }
    }
 
    cout<<ip_A<<" "<<ip_B<<" "<<ip_C<<" "<<ip_D<<" "<<ip_E<<" "<<ip_Err<<" "<<ip_private<<endl;
 
    return 0;
}