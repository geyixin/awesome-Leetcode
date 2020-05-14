/*
 * @Author: Eashin
 * @Date: 2020-05-14 19:41:12
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-14 20:11:46
 * @Description: 
 * @FilePath: /greedy/1043-minimum-subsequence-in-non-increasing-order.cpp
 */

#include<iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) { // sort原cmp是函数指针。如果将其加上static变成静态成员函数指针，这样就可和函数指针匹配。
        return a>b;
    }
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);    // vector 求和【需要 #include <numeric>】
        sort(nums.begin(),nums.end(),cmp);  // vector 排序。sort默认递增
        int tmp = 0; int i = 0; vector<int> s;
        while(2*tmp <= sum) {
            tmp += nums[i];
            s.push_back(nums[i++]);
        }
        return s;
    }
};