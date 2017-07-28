#include<unordered_map>
#include<list>
using namespace std;

//和lru算法相似的，利用了哈希表O(1)时间访问到对应链表的节点
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!keyValue.count(key)) 
            return -1;
        auto it = locator[key];
        frequency[keyValue[key].second++].erase(it);//删除原来的频率
        frequency[keyValue[key].second].push_front(key);//插入链表头
        locator[key] = frequency[keyValue[key].second].begin();//保存它
        if(frequency[minFreq].empty())//维护最小频率 
            minFreq++;
        return keyValue[key].first;

    }

    void put(int key, int value) {
        if(cap <= 0) 
            return;
        if(get(key) != -1){
            keyValue[key].first = value;
        }
        else{
            if(keyValue.size() == cap){
                int temp = frequency[minFreq].back();
                frequency[minFreq].pop_back();
                locator.erase(temp);
                keyValue.erase(temp);
            }
            keyValue[key] = {value, 1};
            frequency[1].push_front(key);
            locator[key] = frequency[1].begin();
            minFreq = 1;
        }
    }
private:
    int cap, minFreq;//记录一下最小频率，方便删除时候迅速定位
    unordered_map<int, pair<int, int> > keyValue;//key，value，freq
    unordered_map<int, list<int> > frequency;//freq，每种频率对应一个链表
    unordered_map<int, list<int>::iterator> locator;//key，为了保证O(1)时间访问到对应的频率链表的节点
};