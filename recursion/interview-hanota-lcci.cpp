/*
 * @Author: Eashin
 * @Date: 2020-05-27 16:59:56
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-27 17:26:02
 * @Description: 
 * @FilePath: /recursion/interview-hanota-lcci.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        helper(n,A,B,C);
        return;
    }

    void helper(int n, vector<int>& a, vector<int>& b, vector<int>& c) {
        if (n == 1) {
            c.push_back(a.back());
            a.pop_back();
            return;
        }
        helper(n-1,a,c,b);
        c.push_back(a.back());
        a.pop_back();
        helper(n-1,b,a,c);
    }
};