/*
 * @Author: Eashin
 * @Date: 2020-06-27 23:25:28
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-28 00:08:02
 * @Description: 
 * @FilePath: /backtracking/77-combinations.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

/*
回溯法模板

res = []
fun backtrack(路径, 当前位置, 选择列表):
    if 满足结束条件:
        res.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 当前位置, 选择列表)
        撤销选择

*/

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > res;
        if (k <=0 || n <= 0) return res;
        vector<int> path;
        bt(n, k, 1, path, res);
        return res;
    }

    void bt(int n, int k, int start, vector<int>& path, vector< vector<int> >& res) {
        if ( path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            bt(n, k, i+1, path, res);
            path.pop_back();
        }
    }
};