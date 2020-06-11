/*
 * @Author: Eashin
 * @Date: 2020-06-11 19:09:10
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-11 22:22:13
 * @Description: 
 * @FilePath: /one test a day/350-intersection-of-two-arrays-ii.cpp
 */ 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            return intersect(nums2,nums1);  // 减小 mp 空间
        }
        unordered_map<int,int> mp;
        vector<int> res;
        for(int num : nums1) {
            mp[num]++;
        }
        for(int num : nums2) {
            if(mp.find(num)!=mp.end() && mp.find(num)->second > 0){
                res.push_back(num);
                mp[num]--;
            }
        }
        return res;
    }
};