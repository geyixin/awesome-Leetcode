/*
 * @Author: Eashin
 * @Date: 2020-05-26 17:33:03
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-26 17:37:47
 * @Description: 
 * @FilePath: /dynamic-programming/70-climbing-stairs.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        vector<int> dp(n+1,0);
        dp[1] = 1; dp[2] = 2;
        for (int i=3; i<n+1; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};