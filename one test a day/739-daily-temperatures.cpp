/*
 * @Author: Eashin
 * @Date: 2020-06-11 09:14:59
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-11 09:47:52
 * @Description: 
 * @FilePath: /one test a day/739-daily-temperatures.cpp
 */ 

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
// n*n 复杂度，超时
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> res(len,0);
        for(int i=0; i<len-1; ++i){
            for(int j=i+1; j<len; ++j){
                if(T[i]<T[j]) {
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }

// 递减栈[push进去的元素只能越来越小]
    vector<int> dailyTemperatures_2(vector<int>& T) {
        int len = T.size();
        vector<int> res(len,0);
        stack<int> s;
        for(int i=0; i<len; ++i){
            while(!s.empty() && T[i]>T[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};