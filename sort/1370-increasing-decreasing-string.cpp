/*
 * @Author: Eashin
 * @Date: 2020-06-10 22:52:21
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-10 23:07:06
 * @Description: 
 * @FilePath: /sort/1370-increasing-decreasing-string.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        vector<int> v(26,0);
        for(int i=0; i<s.size(); ++i) {
            v[s[i]-'a'] ++;
        }
        string res;
        while (res.size() < s.size()) {
            for(int j=0; j<26; j++) {
                if(v[j] > 0) {
                    res.push_back(j+'a');
                    v[j] --;
                }
            }
            for(int k=25; k>=0; k--) {
                if(v[k] > 0) {
                    res.push_back(k+'a');
                    v[k] --;
                }
            }
        }
        return res;
    }
};