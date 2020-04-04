/*
 * @Author: Eashin
 * @Date: 2020-04-04 14:41:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /Finite-Automaton/617-merge-two-binary-trees.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归：mergeTrees
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }

    // 迭代：mergeTrees_2
    TreeNode* mergeTrees_2(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        stack<TreeNode *> st;
        st.push(t1); st.push(t2);
        while (!st.empty())
        {
            TreeNode * node2 = st.top(); st.pop();
            TreeNode * node1 = st.top(); st.pop();
            node1->val += node2->val;
            if (!node1->left) node1->left = node2->left;
            else if (node2->left) { st.push(node1->left); st.push(node2->left); }

            if (!node1->right) node1->right = node2->right;
            else if (node2->right) { st.push(node1->right); st.push(node2->right); }
        }
        return t1;
    }

};