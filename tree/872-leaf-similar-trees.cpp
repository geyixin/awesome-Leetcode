/*
 * @Author: Eashin
 * @Date: 2020-04-09 10:23:40
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-09 15:20:28
 * @Description: 
 * @FilePath: /tree/872-leaf-similar-trees.cpp
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if ((!root1 && root2) || (!root2 && root1)) return false;
        vector<int> v1; vector<int> v2;
        helper(root1,v1);   // helper_2(root1,v1); 
        helper(root2,v2);   // helper_2(root1,v1); 
        return v1==v2;  // 判断两个 vecotr 是否相等
    }

    // 递归
    void helper(TreeNode* root, vector<int>& v) {
        if (!root->left && !root->right) v.push_back(root->val);
        if (root->left) helper(root->left,v);
        if (root->right) helper(root->right,v);
    }

    // 迭代【一直提示超时，没搞清问题出在哪儿。有缘人看见帮忙解释下，不甚感激！】
    void helper_2(TreeNode* root, vector<int>& v) {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            if (!node->left && !node->right) v.push_back(node->val);
            if (node->left) s.push(root->left);
            if (node->right) s.push(root->right);
        }
    }
};
