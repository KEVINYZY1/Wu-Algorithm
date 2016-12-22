#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch){
        vec.push_back(ch);
        mapdata[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
    	vector<char>::iterator it;
  		for(it=vec.begin();it!=vec.end();it++){
   			if(mapdata[*it]==1)
    			return *it;
  		}
  		return '#';
    }
private:
    unordered_map<char,int> mapdata;
	vector<char> vec;
};