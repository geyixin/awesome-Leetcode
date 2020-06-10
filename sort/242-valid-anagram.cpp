/*
 * @Author: Eashin
 * @Date: 2020-06-10 23:10:46
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-10 23:19:36
 * @Description: 
 * @FilePath: /sort/242-valid-anagram.cpp
 */ 

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();++i){
            v[s[i]-'a']++;
        }
        for(int j=0;j<t.size();++j){
            v[t[j]-'a']--;
            if (v[t[j]-'a'] < 0) return false;
        }
        return accumulate(v.begin(),v.end(),0)==0;
    }
};