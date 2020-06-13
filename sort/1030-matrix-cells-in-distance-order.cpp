/*
 * @Author: Eashin
 * @Date: 2020-06-13 23:13:23
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-14 00:26:12
 * @Description: 
 * @FilePath: /sort/1030-matrix-cells-in-distance-order.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }
    vector< vector<int> > allCellsDistOrder(int R, int C, int r0, int c0) {
        vector< vector<int> > res(R*C, vector<int>(3)); // 后面这个 () 必须要
        int n = 0;
        for(int i = 0; i<R; ++i) {
            for(int j = 0; j<C; ++j) {
                res[n][0] = i; res[n][1] = j;
                res[n++][2] = abs(r0-i) + abs(c0-j);
            }
        }
        sort(res.begin(),res.end(),cmp);
        for(int k = 0; k<res.size(); k++) {
            res[k].pop_back();
        }
        return res;
    }
};