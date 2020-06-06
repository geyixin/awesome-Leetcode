/*
 * @Author: Eashin
 * @Date: 2020-06-06 10:08:40
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-06 10:19:00
 * @Description: 
 * @FilePath: /one test a day/128-longest-consecutive-sequence.cpp
 */ 

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums) {
            s.insert(num);
        }
        int max_len = 0;
        for (int num : s) {
            if (!s.count(num-1)) {
                int cur_num = num;
                int cur_len = 1;
                while (s.count(cur_num+1)) {
                    cur_len ++;
                    cur_num ++;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};