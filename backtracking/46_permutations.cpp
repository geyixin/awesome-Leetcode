/*
 * @Author: Eashin
 * @Date: 2020-06-27 23:33:52
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-28 00:08:27
 * @Description: 
 * @FilePath: /backtracking/46_permutations.cpp
 */ 


#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/

回溯法模板

res = []
fun backtrack(路径, 选择列表):
    if 满足结束条件:
        res.add(路径)
        return
    for 选择 in 选择列表:
        判断
        做选择
        backtrack(路径, 选择列表)
        撤销选择

*/

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > res;
        vector<int> path;
        bt(nums, path ,res);
        return res;
    }

    void bt(vector<int>& nums, vector<int> path, vector< vector<int> >& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            vector<int>::iterator it = find(path.begin(), path.end(), nums[i]);
            if (it != path.end()) {
                continue; // 加入 nums = [1,2,3] 防止出现 [1,1,2] 或者 [1,1,1]之类的问题
            }
            path.push_back(nums[i]);
            bt(nums, path, res);
            path.pop_back();
        }
    }
};