/*
 * @Author: Eashin
 * @Date: 2020-04-18 15:10:02
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/687-longest-univalue-path.cpp
 */

#include <iostream>

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
    // 递归：longestUnivaluePath【参考官方的Java解释】
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root,res);
        return res;
    }

    int helper(TreeNode* p, int& res) {
        if (!p) return 0;
        int L = helper(p->left, res);
        int R = helper(p->right, res);
        int tmp_L = 0, tmp_R = 0;
        if (p->left && p->left->val == p->val) tmp_L = L + 1;
        if (p->right && p->right->val == p->val) tmp_R = R + 1;
        res = max(res, tmp_L + tmp_R);
        return max(tmp_L,tmp_R);
    }
};