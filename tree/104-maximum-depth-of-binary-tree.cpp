/*
 * @Author: Eashin
 * @Date: 2020-04-05 19:53:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /tree/104-maximum-depth-of-binary-tree.cpp
 */

#include <iostream>
#include <queue>

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
    // 递归：maxDepth
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
    // 迭代：maxDepth_2 (其实就是计算有多少层，依次遍历每一层，有一层就 +1)
    int maxDepth_2(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q; q.push(root);
        int num = 0; int res = 0;
        while (!q.empty()) {
            num = q.size();
            res += 1;
            while (num --) {
                TreeNode* tmp = q.front(); q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
};