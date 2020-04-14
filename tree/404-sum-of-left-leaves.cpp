/*
 * @Author: Eashin
 * @Date: 2020-04-14 08:30:38
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/404-sum-of-left-leaves.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归：sumOfLeftLeaves
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0; 
        if (root->left && !root->left->left && !root->left->right) res += root->left->val; 
        if (root->left) sumOfLeftLeaves(root->left);
        if (root->right) sumOfLeftLeaves(root->right);
        return res;
    }

    // 迭代：sumOfLeftLeaves_2
    int sumOfLeftLeaves_2(TreeNode* root) {
        if (!root) return 0;
        int res = 0; TreeNode* node = NULL;
        stack<TreeNode*> s; s.push(root);
        while (!s.empty()) {
            node =  s.top(); s.pop();
            if (node->left && !node->left->left && !node->left->right) res += node->left->val;
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        return res;
    }
};