/*
 * @Author: Eashin
 * @Date: 2020-04-08 08:33:04
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-08 09:10:12
 * @Description: 
 * @FilePath: /tree/669-trim-a-binary-search-tree.cpp
 */

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归：trimBST
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return root;
        if (root->val > R) return trimBST(root->left, L, R);
        if (root->val < L) return trimBST(root->right, L ,R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }

    // 迭代：trimBST_2  【参考：https://leetcode-cn.com/problems/trim-a-binary-search-tree/comments/ 】
    TreeNode* trimBST_2(TreeNode* root, int L, int R) {
        if (root) {
            // 找到根结点
            while (root->val < L || root->val > R) {
                root = root->val < L ? root->right : root->left;
            }
            // 记住根结点位置
            TreeNode* cur = root;
            // 处理左枝
            while (cur) {
                while (cur->left && cur->left->val < L) {
                    cur->left = cur->left->right;
                }
                cur = cur->left;
            }
            // 回到根结点
            cur = root;
            // 处理右枝
            while (cur) {
                while (cur->right && cur->left->val > R) {
                    cur->right = cur->right->left;
                }
                cur = cur->right;
            }
        }
        return root;
    }
};