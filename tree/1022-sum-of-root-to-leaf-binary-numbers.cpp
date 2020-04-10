/*
 * @Author: Eashin
 * @Date: 2020-04-10 09:49:52
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-10 10:04:42
 * @Description: 
 * @FilePath: /tree/1022-sum-of-root-to-leaf-binary-numbers.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归：sumRootToLeaf + helper 【与 257 递归解法一样】
    int sumRootToLeaf(TreeNode* root) {
        int tmp_sum = 0; int res_sum = 0;
        helper(root,tmp_sum,res_sum);
        return res_sum;
    }

    void helper(TreeNode* root, int tmp_sum, int& res_sum) {
        if (root) {
            tmp_sum = (tmp_sum<<1) + root->val;
            if (!root->left && !root->right) res_sum += tmp_sum;
            else {
                helper(root->left,tmp_sum,res_sum);
                helper(root->right,tmp_sum,res_sum);
            }
        }
    }

    // 迭代：sumRootToLeaf_2    【与 257 迭代解法一样】
    int sumRootToLeaf_2(TreeNode* root) {
        stack< pair<TreeNode*,int> > s;
        if (!root) return 0;
        int t_sum = 0; int r_sum = 0; TreeNode* node;
        s.push(pair<TreeNode*,int>(root,t_sum));
        while (!s.empty()) {
            node = s.top().first; t_sum = s.top().second; s.pop();
            t_sum = (t_sum<<1) + node->val;
            if (!node->left && !node->right) r_sum += t_sum;
            if(node->left) s.push(pair<TreeNode*,int>(node->left, t_sum));
            if(node->right) s.push(pair<TreeNode*,int>(node->right, t_sum));
        }
        return r_sum;
    }
};