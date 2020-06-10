/*
 * @Author: Eashin
 * @Date: 2020-06-10 23:24:54
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-11 00:02:29
 * @Description: 
 * @FilePath: /sort/349-intersection-of-two-arrays.cpp
 */ 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        vector<int> res;
        for(auto num : nums1) {
            s1.insert(num);
        }
        for(auto num : nums2) {
            s2.insert(num);
        }
        for(set<int>::iterator it=s1.begin();it!=s1.end();++it){
            if(s2.count(*it)) res.push_back(*it);
        }
        return res;
    }
};