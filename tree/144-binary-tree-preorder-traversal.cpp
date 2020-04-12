/*
 * @Author: Eashin
 * @Date: 2020-04-12 20:28:53
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/144-binary-tree-preorder-traversal.cpp
 */

#include <iostream>
#include <vector>
#include <stack>

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
    // 递归：preorderTraversal
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root) {
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }

    // 迭代：preorderTraversal_2
    vector<int> preorderTraversal_2(TreeNode* root) {
        vector<int> res; TreeNode* node = root; stack<TreeNode*> s;
        while (node || !s.empty()) {
            while(node) {
                res.push_back(node->val);
                s.push(node);
                node = node->left;
            }
            if(!s.empty()) {
                node = s.top(); s.pop();
                node = node->right;
            }
        }
        return res;
    }
};