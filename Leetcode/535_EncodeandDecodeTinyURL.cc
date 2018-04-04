//短url解析
#include <string>
#include <vector>
using namespace std;

//自增字段来实现，坏处是容易暴露系统的短url数目
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        originUrls.push_back(longUrl);
        return "http://fuckyou.com/" + to_string(originUrls.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index = shortUrl.find_last_of("/");
        int num = stoi(shortUrl.substr(index + 1));
        return originUrls[num];
    }
   
private:
    vector<string> originUrls;
};