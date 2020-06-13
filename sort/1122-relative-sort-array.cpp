/*
 * @Author: Eashin
 * @Date: 2020-06-13 23:46:54
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-13 23:57:20
 * @Description: 
 * @FilePath: /sort/1122-relative-sort-array.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        for(int num : arr2) {
            int cnt = count(arr1.begin(),arr1.end(),num);
            while(cnt--){
                res.push_back(num);
            }
        }
        vector<int> tmp;
        for(int num : arr1) {
            int cnt = count(arr2.begin(),arr2.end(),num);
            if(!cnt) {
                tmp.push_back(num);
            }
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0; i<tmp.size(); i++){
            res.push_back(tmp[i]);
        }
        return res;
    }
};