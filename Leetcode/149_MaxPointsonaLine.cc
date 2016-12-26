#include<unordered_map>
#include<vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

//求二维平面上n个点中，最多共线的点数。
//选定一个点，分别计算其他点和它构成的直线的斜率，斜率相同的点肯定在同一条直线上。
//对每个点进行计算。
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty())
            return 0;
        const int len=points.size();
        unordered_map<float,int> mp;  
        int maxNum = 0;  
        for(int i = 0; i < len; i++){  
            mp.clear();  
            mp[INT_MIN] = 0;  
            int duplicate = 1;//坐标完全相同点的个数  
            for(int j = 0; j < len; j++){  
                if(j == i) continue;  
                if(points[i].x == points[j].x && points[i].y == points[j].y){  
                    duplicate++;  
                    continue;  
                }
                //这里默认计算出的斜率，虽然是浮点数，但是可以直接比较大小。  
                float k = points[i].x == points[j].x ? INT_MAX : 
                                        (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);  
                mp[k]++;  
            }  
            unordered_map<float, int>::iterator it = mp.begin();  
            for(; it != mp.end(); it++)  
                if(it->second + duplicate > maxNum)  
                    maxNum = it->second + duplicate;  
        }  
        return maxNum;  
    }
};