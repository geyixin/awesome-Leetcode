/*
 * @Author: Eashin
 * @Date: 2020-06-03 22:24:32
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-03 22:31:38
 * @Description: 
 * @FilePath: /recursion/1137-n-th-tribonacci-number.cpp
 */ 


#include <iostream>
#include<vector>

using namespace std;

class Solution
{
public:
// 递归【到n=34的时候将超出时间限制】
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        else return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
// dp
    int tribonacci_2(int n) {
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 0; dp[1] = 1; dp[2] = 1;
        for(int i=3; i<n+1; ++i) {
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};