/*
 * @Author: Eashin
 * @Date: 2020-06-03 23:29:53
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-03 23:44:54
 * @Description: 
 * @FilePath: /recursion/687-longest-univalue-path.cpp
 */ 

#include <iostream>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root,res);
        return res;
    }

    int helper(TreeNode* root, int &res) {
        if(!root) return 0;
        int Left = helper(root->left, res);
        int Right = helper(root->right, res);
        int L = 0, R = 0;
        if (root->left && root->left->val == root->val) L = Left + 1;
        if (root->right && root->right->val == root->val) R = Right + 1;
        res = max(res, L+R);
        return max(L,R);
    }
};