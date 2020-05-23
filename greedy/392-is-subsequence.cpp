/*
 * @Author: Eashin
 * @Date: 2020-05-23 22:14:30
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-23 22:17:44
 * @Description: 
 * @FilePath: /greedy/392-is-subsequence.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_index = 0, t_index = 0;
        while (s_index < s.size() && t_index < t.size())
        {
            if (s[s_index] == t[t_index]) { s_index ++; t_index ++;}
            else t_index ++;
        }
        return s_index == s.size();
    }
};