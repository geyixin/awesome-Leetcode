/*
 * @Author: Eashin
 * @Date: 2020-05-26 17:09:01
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-26 17:32:38
 * @Description: 
 * @FilePath: /dynamic-programming/392-is-subsequence.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_i = 0, t_i = 0;
        while (s_i < s.size() && t_i < t.size()) {
            if (s[s_i] == t[t_i]) { s_i ++; t_i ++;}
            else t_i ++;
        }
        return (s_i == s.size());
    }
};