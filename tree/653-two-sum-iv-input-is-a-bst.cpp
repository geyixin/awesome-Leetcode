/*
 * @Author: Eashin
 * @Date: 2020-04-13 16:17:50
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/653-two-sum-iv-input-is-a-bst.cpp
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);   // 二叉搜索树的中序遍历是递增序列
        int i = 0; int j = v.size()-1;
        for (; i < j; ) {
            if (v[i]+v[j] == k) return true;
            if (v[i]+v[j] > k) {j--; continue;}
            if (v[i]+v[j] < k) {i++; continue;}
        }
        return false;
    }

    // 递归：inOrder
    void inOrder(TreeNode* root, vector<int>& v) {
        if (root) {
            inOrder(root->left,v);
            v.push_back(root->val);
            inOrder(root->right,v);
        }
    }

    // 迭代：inOrder_2
    void inOrder_2(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (!s.empty()) {
                root = s.top(); s.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
    }
};