/*
 * @Author: Eashin
 * @Date: 2020-04-08 09:12:28
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/107-binary-tree-level-order-traversal-ii.cpp
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
    // 迭代：levelOrderBottom
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > res;  // 内部vector两边加空格
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> s;
            int len = q.size();
            while (len--) {
                TreeNode* node = q.front(); q.pop();
                s.push_back(node->val); 
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(s);
        }
        // 倒叙
        for (int i = 0; i < res.size()/2; ++i) {
            swap(res[i],res[res.size()-1-i]);
        }
        return res;
    }

    // 递归：levelOrderBottom_2 【参考：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/comments/ 】
    vector<int> space;
    vector< vector<int> > levelOrderBottom_2(TreeNode* root) {
        vector< vector<int> > res;
        helper(root, 1, res);
        return vector< vector<int> > (res.rbegin(),res.rend()); // 倒叙
    }

    void helper(TreeNode* root, int levelOrder, vector< vector<int> > res) {
        if (!root) return;
        // 本地和线上 将 space 换成 vector<int> () 都可以。
        // 本地将 space 换成 {} 提示有问题。线上可以。
        if (res.size() < levelOrder) res.push_back(space);
        res[levelOrder-1].push_back(root->val);
        if (root->left) helper(root->left, levelOrder+1, res);
        if (root->right) helper(root->right, levelOrder+1, res);
    }
};