/*
 * @Author: Eashin
 * @Date: 2020-06-06 11:20:23
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-06 11:35:29
 * @Description: 
 * @FilePath: /heap/interview-zui-xiao-de-kge-shu-lcof.cpp
 */ 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, less<int> > que;   // 大顶堆
        for(const int num : arr) {
            que.push(num);
            if (que.size() > k) que.pop();
        }
        arr.clear();
        arr.resize(que.size());
        while (!que.empty())
        {
            arr.push_back(que.top());
            que.pop();
        }
        return arr;
    }
};