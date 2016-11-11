#include<string>
#include<vector>
using namespace std;

//简化绝对路径，针对有..和.的情况
//如果有重复的//等于不起作用
class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty())
            return "";
        //将各个/ /之间的字符串都存起来
        vector<string> name;
        int lastIndex=0;
        for(int i=1;i<path.size();++i){
            if(path[i]=='/'){
                auto temp=path.substr(lastIndex+1,i-lastIndex-1);
                if(!temp.empty())
                    name.push_back(temp);
                lastIndex=i;
            }
        }
        if(path[path.size()-1]!='/')
            name.push_back(path.substr(lastIndex+1,path.size()-1-lastIndex));
        //开始构建绝对路径
        if(name.empty())
            return "/";
        string result;
        vector<string> newName;
        for(int i=0;i<name.size();i++){
            if(name[i]==".")
                continue;
            else if(name[i]==".."){
                if(!newName.empty())
                    newName.pop_back();
            }
            else newName.push_back(name[i]);
        }
        for(int i=0;i<newName.size();i++){
            result+='/'+newName[i];    
        }
        if(result.empty() && newName.empty())//针对"/.."和"/."情况
            return "/";
        return result;
    }
};