/*
 * @Author: Eashin
 * @Date: 2020-04-08 10:41:40
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/637-average-of-levels-in-binary-tree.cpp
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 迭代：averageOfLevels
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int len = q.size();
            int num = 0;
            double sum = 0;
            while (len--) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                num ++;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum/num);
        }
        return res;
    }

    // 递归：averageOfLevels_2 【思路沿用 107：binary-tree-level-order-traversal-ii 题】
    vector<double> averageOfLevels_2(TreeNode* root) {
        vector<double> res;
        vector<int> nums;
        helper(root, 1, res, nums);
        for (int i = 0; i < res.size(); i++) {
            res[i] = res[i] / nums[i];
        }
        return res;
    }
    vector<int> space;
    void helper(TreeNode* root, int levelOrder, vector<double>& res, vector<int>& nums) {
        if (!root) return;
        if (res.size() < levelOrder) { res.push_back(0); nums.push_back(0); };
        res[levelOrder-1] += root->val; nums[levelOrder-1]++;
        if (root->left) helper(root->left, levelOrder+1, res, nums);
        if (root->right) helper(root->right, levelOrder+1, res, nums);
    }
};