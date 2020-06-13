/*
 * @Author: Eashin
 * @Date: 2020-06-14 00:10:18
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-14 00:25:33
 * @Description: 
 * @FilePath: /sort/1356-sort-integers-by-the-number-of-1-bits.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // __builtin_popcount(int x)：内置函数，计算x的二进制中有多少个1。
    static bool cmp(int a, int b) {
        return __builtin_popcount(a)==__builtin_popcount(b) ? a < b : __builtin_popcount(a)<__builtin_popcount(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }

    // 自己也可以写个计算整数 x 的二进制中有多少个1
    int cnt(int x){
        int res = 0;
        while (x)
        {
            res += res & 1;
            res >>= 1;
        }
        return res;
    }
};