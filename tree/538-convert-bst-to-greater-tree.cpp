/*
 * @Author: Eashin
 * @Date: 2020-04-10 09:03:20
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-10 09:22:15
 * @Description: 
 * @FilePath: /tree/538-convert-bst-to-greater-tree.cpp
 */

#include <iostream>
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
    // 递归：convertBST 【反中序遍历：右根左】
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }

    // 递归：convertBST_2
    int sum_2 = 0;
    TreeNode* convertBST_2(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (!s.empty() || cur) {
            while (cur) {
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top(); s.pop();
            sum_2 += cur->val;
            cur->val = sum_2;
            cur = cur->left;
        }
        return root;
    }
};