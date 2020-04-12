/*
 * @Author: Eashin
 * @Date: 2020-04-11 21:29:25
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/530-minimum-absolute-difference-in-bst.cpp
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        inOrder(root,res); // inOrder_2(root,res);
        int m_min = INT_MAX;
        for (int i=0; i<res.size()-1; ++i) {
            m_min = min(m_min,res[i+1] - res[i]);
        }
        return m_min;
    }

    // 递归：inOrder
    void inOrder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inOrder(root->left,res);
        res.push_back(root->val);
        inOrder(root->right,res);
    }

    // 迭代：inOrder_2
    void inOrder_2(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> s; TreeNode* node = root;
        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                node = node->left;
            }
            if (!s.empty()) {
                node = s.top(); s.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
    }
};
