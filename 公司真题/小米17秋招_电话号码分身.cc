/*
继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，然后使用对应的大写字母代替
（"ZERO", "ONE", "TWO", "THREE", "FOUR", 
"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"），
然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。

输入
第一行是一个整数T（1<=T<=100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。
输出
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*方法1
想用回溯法和哈希来确定字符串到底含哪几个digit，过于繁琐
vector<string> digits={"ZERO", "ONE", "TWO", "THREE", "FOUR", 
"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool findDigits(vector<int> &a, unordered_map<char, int> &m){
	for(int i=0; i<10; i++){
    	if(isDigitsInMap(i)){
          	//修改a和m
			a.push_back(i);
          	if(findDigits(a, m)){
            	return true;
            }
          	//把a和m恢复原样
          	
        }
    }
  	//都执行完了，m中还有int大于0
  	return false;
}

//难点在于，如何在乱序的字符串中，确定哪几个字符串使我们想要的
int main(){
	int n;
  	cin>>n;
    vector<string> v(n);
  	for(int i=0; i<n; i++){
    	cin>>v[i];
    }
  	for(int i=0; i<n; i++){
    	//确定每行字符串究竟有几个对应数字的字符串，关键！
      	//使用hash？使用回溯法？
      	vector<int> a;
      	unordered_map<char, int> m;
      	for(int j=0; j<v[i].size(); j++){
        	m[v[i][j]]++;
        }
      	
    }
}
*/

//方法2，使用digit字符串中独一无二的字符来判断是否存在该字符串
int main(){
	int n;
  	cin>>n;
    vector<string> v(n);
  	for(int i=0; i<n; i++){
    	cin>>v[i];
    }
  	for(int i=0; i<n; i++){
      	vector<int> a(10, 0);
      	unordered_map<char, int> m;
      	for(int j=0; j<v[i].size(); j++){
        	m[v[i][j]]++;
        }
      	//寻找规律，用digit字符串中独一无二的字符来代表它
      	if(m['Z']>0){//唯一对应0
        	a[2]+=m['Z'];
        }
      	if(m['X']>0){//唯一对应6
        	a[8]+=m['X'];
        }
      	if(m['W']>0){//唯一对应2
        	a[4]+=m['W'];
        }
      	if(m['U']>0){//唯一对应4
        	a[6]+=m['U'];
        }
      	if(m['G']>0){//唯一对应8
        	a[0]+=m['G'];
        }
      	if(m['H']>0){//3
        	a[5]+=m['H']-m['G'];
        }
      	if(m['F']>0){//5
        	a[7]+=m['F']-m['U'];
        }
      	if(m['S']>0){//7
        	a[9]+=m['S']-m['X'];
        }
      	if(m['O']>0){//1
        	a[3]+=m['O']-m['Z']-m['W']-m['U'];
        }
      	if(m['I']>0){//9
        	a[1]+=m['I']-m['X']-m['G']-a[7];
        }
      	string res;
      	for(int i=0; i<10; i++){
        	while(a[i]--){
            	res+='0'+i;
            }
        }
      	cout<<res<<endl;
    }
}