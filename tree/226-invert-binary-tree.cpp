/*
 * @Author: Eashin
 * @Date: 2020-04-04 15:27:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /tree/226-invert-binary-tree.cpp
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    // 递归：invertTree
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // 迭代：invertTree_2.  
    // 层序遍历 实现。
    TreeNode* invertTree_2(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        int len = 0;
        while (!q.empty())
        {
            len = q.size();
            while (len)
            {
                TreeNode* tmp = q.front(); q.pop();
                if (tmp) {
                    q.push(tmp->left); q.push(tmp->right);
                    swap(tmp->left, tmp->right);
                }
                len--;
            }
        }
        return root;
    }
};