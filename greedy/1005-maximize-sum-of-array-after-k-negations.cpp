/*
 * @Author: Eashin
 * @Date: 2020-05-23 22:08:37
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-23 22:11:28
 * @Description: 
 * @FilePath: /greedy/1005-maximize-sum-of-array-after-k-negations.cpp
 */ 

#include<iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int i = 0;
        while (i++ < K)
        {
            sort(A.begin(),A.end());
            A[0] = 0 - A[0];
        }
        return accumulate(A.begin(),A.end(),0);
    }
};