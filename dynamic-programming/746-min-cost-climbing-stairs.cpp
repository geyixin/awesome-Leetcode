/*
 * @Author: Eashin
 * @Date: 2020-05-26 17:37:56
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-26 18:44:37
 * @Description: 
 * @FilePath: /dynamic-programming/746-min-cost-climbing-stairs.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
// 借用数组
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);
        dp[1] = 1; dp[2] = 1;
        for (int i=2; i<dp.size(); ++i) {
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return *(dp.end()-1);
    }

// 不用数组
    int minCostClimbingStairs_2(vector<int>& cost) {
        int a = 0, b = 0, t = 0;
        for (auto c : cost) {
            t = min(a,b) + c;
            a = b;
            b = t;
        }
        return min(a,b);
    }    
};
