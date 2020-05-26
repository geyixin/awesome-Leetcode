/*
 * @Author: Eashin
 * @Date: 2020-05-26 20:44:13
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-26 21:38:02
 * @Description: 
 * @FilePath: /dynamic-programming/198-house-robber.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
// dp常规做法
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0],nums[1]);
        vector<int> dp(n,0);
        dp[0] = nums[0]; dp[1] = max(nums[0],nums[1]);
        for (int i=2; i<n; i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
// dp不用额外空间做法
    int rob2(vector<int> &nums) {
        int a = 0, b = 0;
        int pre_a = 0, pre_b = 0;
        for (auto num : nums) {
            pre_a = a; pre_b = b;
            a = pre_b + num;
            b = max(pre_a,pre_b);
        }
        return max(a,b);
    }
};