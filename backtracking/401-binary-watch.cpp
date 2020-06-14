/*
 * @Author: Eashin
 * @Date: 2020-06-14 15:59:06
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-14 18:21:55
 * @Description: 
 * @FilePath: /backtracking/401-binary-watch.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
// 粗暴版
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int i = 0; i<12; i++) {
            for(int j = 0; j<60; j++) {
                if(__builtin_popcount(i) + __builtin_popcount(j) == num) {
                    res.push_back(to_string(i)+":"+(j < 10 ? "0" + to_string(j) : to_string(j)));
                }
            }
        }
        return res;
    }

// 回溯版
    vector<string> readBinaryWatch_2(int num) {
        vector<string> res;
        int a[10] = {1,2,4,8,1,2,4,8,16,32};
        vector<int> v(a,a+10);
        backtrack(num,0,0,0,res,v);   // num,start,hour,minute,res
        return res;
    }

    void backtrack(int num, int start, int hour, int minute, vector<string>& res, vector<int>& v) {
        if(num == 0) {
            if(hour > 11 || minute > 59) return;
            res.push_back(to_string(hour)+":"+(minute < 10 ? "0" + to_string(minute) : to_string(minute)));
            return;
        }
        for(int i=start; i<v.size(); ++i) {
            if(hour > 11 || minute > 59) continue;
            int store_h = hour; int store_m = minute;
            if(i<4) hour += v[i];
            else minute += v[i];
            backtrack(num-1,i+1,hour,minute,res,v);
            hour = store_h; minute = store_m;
        }
    }
};