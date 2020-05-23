/*
 * @Author: Eashin
 * @Date: 2020-05-22 23:21:36
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-23 19:43:27
 * @Description: 
 * @FilePath: /greedy/122-best-time-to-buy-and-sell-stock-ii.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};