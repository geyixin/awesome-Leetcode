/*
 * @Author: Eashin
 * @Date: 2020-05-25 20:58:45
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-25 21:20:26
 * @Description: 
 * @FilePath: /dynamic-programming/303-range-sum-query-immutable.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.size() == 0) return;
        sum.push_back(nums[0]);
        int t = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            t += nums[i];
            sum.push_back(t);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return sum[j];
        return sum[j]-sum[i];
    }
private:
    vector<int> sum;
};