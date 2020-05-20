/*
 * @Author: Eashin
 * @Date: 2020-05-20 22:19:00
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-20 23:50:10
 * @Description: 
 * @FilePath: /greedy/1029-two-city-scheduling.cpp
 */ 

#include<iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // 自己错误版本。错在在dif最小的时候，不一定需要调整飞行地。
    int twoCitySchedCost_fail(vector< vector<int> >& costs) {
        vector<int> cost;
        vector<int> dif; int tmp = 0;
        int cnt_A = 0, cnt_B = 0; int size_costs = costs.size();
        for (int i=0; i<size_costs; ++i) {
            if (costs[i][0] > costs[i][1]) {
                cost.push_back(costs[i][1]);
                dif.push_back(costs[i][0] - costs[i][1]);
                cnt_B ++;
            }
            else {
                cost.push_back(costs[i][0]);
                dif.push_back(costs[i][1] - costs[i][0]);
                cnt_A ++;
            }   
        }
        if (2*cnt_A != size_costs) {
            sort(dif.begin(),dif.end());
            return accumulate(cost.begin(),cost.end(),0) + accumulate(dif.begin(),dif.begin()+(size_costs/2-min(cnt_B,cnt_A)),0);
        }
        return accumulate(cost.begin(),cost.end(),0);
    }

    // 官方版本
    bool static cmp(vector<int> a, vector<int> b) {
        return a[0] - a[1] < b[0] - b[1];
    }

    int twoCitySchedCost(vector< vector<int> >& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int total = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
        return total;
    }
};