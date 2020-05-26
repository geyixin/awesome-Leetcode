/*
 * @Author: Eashin
 * @Date: 2020-05-26 16:24:17
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-26 16:27:32
 * @Description: 
 * @FilePath: /dynamic-programming/121-best-time-to-buy-and-sell-stock.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, best_buy = INT_MAX;
        for (auto price : prices) {
            max_profit = max(max_profit, price-best_buy);
            best_buy = min(best_buy, price);
        }
        return max_profit;
    }
};