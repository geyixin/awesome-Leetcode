/*
 * @Author: Eashin
 * @Date: 2020-04-12 21:24:18
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-12 22:17:52
 * @Description: 
 * @FilePath: /tree/145-binary-tree-postorder-traversal.cpp
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
    // 递归：postorderTraversal
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
    }

    // 递归：postorderTraversal_2 【源自：https://blog.csdn.net/qq_27962497/article/details/82191807】
    /*
    思想：先在res中放 root->val，然后将 left 和 right 压栈，最后出栈则是 right ，left。
    这样合起来放入res中的顺序就是：root->val, root->right->val, root->left->val。
    即，根右左，reverse一下，即：左右根
    */
    vector<int> postorderTraversal_2(TreeNode* root) {
        vector<int> res; 
        if (!root) return res;
        stack<TreeNode*> s; TreeNode* node = root;
        s.push(node);
        while (!s.empty()) {
            node = s.top(); s.pop();
            res.push_back(node->val);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};