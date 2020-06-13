/*
 * @Author: Eashin
 * @Date: 2020-06-13 23:24:38
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-13 23:44:34
 * @Description: 
 * @FilePath: /sort/1403-minimum-subsequence-in-non-increasing-order.cpp
 */ 

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        return a>b;
    }
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end(),cmp);
        int tmp = 0; int i = 0; vector<int> s;
        while(2*tmp <= sum) {
            tmp += nums[i];
            s.push_back(nums[i++]);
        }
        return s;
    }
}; 