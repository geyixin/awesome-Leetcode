/*
 * @Author: Eashin
 * @Date: 2020-05-23 20:26:24
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-23 22:08:02
 * @Description: 
 * @FilePath: /greedy/455-assign-cookies.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_index = 0, s_index = 0, cnt = 0;
        while (g_index < g.size() && s_index < s.size()) {
            if (s[s_index] >= g[g_index]) {
                g_index ++; s_index ++; cnt ++;
            }
            else s_index ++;
        }
        return cnt;
    }
};