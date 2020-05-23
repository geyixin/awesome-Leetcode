/*
 * @Author: Eashin
 * @Date: 2020-05-23 19:44:13
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-23 20:18:11
 * @Description: 
 * @FilePath: /greedy/860-lemonade-change.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector< pair<int,int> > v;
        v.push_back(make_pair(5,0));
        v.push_back(make_pair(10,0));
        v.push_back(make_pair(20,0));
        for (auto bill : bills) {
            if (bill == v[0].first) v[0].second ++;
            else if (bill == v[1].first) {
                if (v[0].second > 0) { v[0].second --; v[1].second ++; }
                else return false;
            } 
            else {
                if (v[0].second > 0) {
                    if (v[1].second > 0) {
                        v[0].second --; v[1].second --; v[2].second ++;
                    }
                    else {
                        if (v[0].second >= 3) { v[0].second -= 3; v[2].second ++; }
                        else return false;
                    }
                }
                else return false;
            }
        }
        return true;
    }
};