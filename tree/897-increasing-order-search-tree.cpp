/*
 * @Author: Eashin
 * @Date: 2020-04-06 20:48:02
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-07 23:22:42
 * @Description: 
 * @FilePath: /tree/897-increasing-order-search-tree.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 中序遍历+构造新树
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        vector<int> v;
        inorder(root,v);
        TreeNode * res = new TreeNode(0); TreeNode * cur = res; // cur用于往下走，res用于记住原始位置
        for (auto ele : v) {
            cur->left = NULL;
            cur->right = new TreeNode(ele);
            cur = cur->right;
        }
        return res->right;
    }

    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    // 中序遍历+更改树的连接方式
    TreeNode * cur = NULL;
    TreeNode* increasingBST_2(TreeNode* root) {
        TreeNode * res = new TreeNode(0);  cur = res;
        inorder_2(root);
        return res->right;
    }

    void inorder_2(TreeNode* root) {
        if (!root) return ;
        inorder_2(root->left);
        root->left = NULL;
        cur->right = root;
        cur = root;
        inorder_2(root->right);
    }
};
