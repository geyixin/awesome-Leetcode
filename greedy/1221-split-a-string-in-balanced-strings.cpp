/*
 * @Author: Eashin
 * @Date: 2020-05-12 21:21:54
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-12 21:45:24
 * @Description: 
 * @FilePath: /greedy/1221-split-a-string-in-balanced-strings.cpp
 */

#include<iostream>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int L = 0; int R = 0; int res = 0;
        for(int i=0; i<s.size(); ++i) {
            if(L==R && R!=0)  { res++; R = 0; L = 0;}
            if(s[i] == 'L') L++;
            else R++;
        }
        if(L==R && R!=0) res++;
        return res;
    }
};