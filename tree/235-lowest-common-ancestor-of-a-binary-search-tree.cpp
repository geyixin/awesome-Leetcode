/*
 * @Author: Eashin
 * @Date: 2020-04-09 09:41:22
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-09 10:03:17
 * @Description: 
 * @FilePath: /tree/235-lowest-common-ancestor-of-a-binary-search-tree.cpp
 */

#include <iostream>

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
    // 递归：lowestCommonAncestor【注意：题目并未说 p->val q->val 谁大】
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else if (root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        else return root;
    }

    // 迭代：lowestCommonAncestor_2
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode*p, TreeNode*q) {
        while (root) {
            if (root->val < p->val && root->val < q->val) root = root->right;
            else if (root->val > p->val && root->val > q->val) root = root->left;
            else return root;
        }
        return root;
    }
};