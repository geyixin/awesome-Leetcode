/*
 * @Author: Eashin
 * @Date: 2020-06-29 22:44:40
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-29 23:22:44
 * @Description: 1436. 旅行终点站 【https://leetcode-cn.com/problems/destination-city/】
 * @FilePath: /string/1436-destination-city.cpp
 */ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string destCity(vector< vector<string> >& paths) {
        vector<string> v1, v2;
        for (auto path : paths) {
            v1.push_back(path[0]);
            v2.push_back(path[1]);
        }

        int i = 0;
        for (;i < v2.size(); ++i) {
            vector<string>::iterator iter = find(v1.begin(),v1.end(),v2[i]);
            if (iter == v1.end()) {
                break;
            }
            else continue;
        }
        return v2[i];
    }
};

int main() {
    vector<string> v,v1,v2;
    v.push_back("London"); v.push_back("New York");
    v1.push_back("New York"); v1.push_back("Lima");
    v2.push_back("Lima"); v2.push_back("Sao Paulo");
    vector< vector<string> > paths;
    paths.push_back(v);
    paths.push_back(v1);
    paths.push_back(v2);
    Solution so;
    cout << so.destCity(paths);
    return 0;
}