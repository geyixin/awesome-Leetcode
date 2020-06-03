/*
 * @Author: Eashin
 * @Date: 2020-05-27 15:37:59
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-27 16:35:49
 * @Description: 
 * @FilePath: /recursion/938-range-sum-of-bst.cpp
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

// 递归
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        if (root->val >= L && root->val <= R) res += root->val;
        if (root->val <= R) rangeSumBST(root->right, L, R);
        if (root->val >= L) rangeSumBST(root->left, L, R);
        return res;
    }
private:
    int res;

// 迭代
    int rangeSumBST2(TreeNode* root, int L, int R) {
        if (!root) return 0;
        stack<TreeNode*> s;
        int res = 0;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            if (node) {
                if (node->val >= L && node->val <= R) res += node->val;
                if (node->val <= R) s.push(node->right);
                if (node->val >= L) s.push(node->left);
            }
        }
        return res;
    }
};