/*
 * @Author: Eashin
 * @Date: 2020-06-27 22:43:08
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-28 00:07:51
 * @Description: 
 * @FilePath: /backtracking/78-subsets.cpp
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
    vector< vector<int> > subsets(vector<int>& nums) {
        vector<int> path;
        vector< vector<int> > res;
        bt(nums, 0, path, res);
        return res;
    }

    void bt(vector<int>& nums, int start, vector<int>& path, vector< vector<int> >& res) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            bt(nums, i+1, path, res);
            path.pop_back();
        }
    }
};