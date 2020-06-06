/*
 * @Author: Eashin
 * @Date: 2020-06-06 11:39:52
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-06 11:45:32
 * @Description: 
 * @FilePath: /heap/1046-last-stone-weight.cpp
 */ 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int> > que;
        for(const int stone : stones) {
            que.push(stone);
        }
        int first, second;
        while (!que.empty())
        {
            first = que.top(); que.pop();
            if (que.empty()) return first;
            second = que.top(); que.pop();
            if (first > second) que.push(first-second);
        }
        return 0;
    }
};