/*
 * @Author: Eashin
 * @Date: 2020-04-06 20:23:54
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-06 20:42:59
 * @Description: 
 * @FilePath: /tree/965-univalued-binary-tree.cpp
 */

#include <iostream>
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
    // 递归：isUnivalTree，helper
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int val = root->val;
        return helper(val,root->left) && helper(val,root->right);
    }

    bool helper(int val, TreeNode* root) {
        if (!root) return true;
        else if (root->val == val) return helper(root->val,root->left) && helper(root->val,root->right);
        else return false;
    }

    // 迭代：isUnivalTree_2
    bool isUnivalTree_2(TreeNode* root) {
        if (!root) return true;
        int val = root->val;
        stack<TreeNode*> st;
        st.push(root);
        int i = 0;
        while (!st.empty())
        {
            i = st.size();
            while (i --)
            {
                TreeNode* node = st.top(); st.pop();
                if (val != node->val) return false;
                if (node->left) st.push(node->left);
                if (node->right) st.push(node->right);
            }
        }
        return true;
    }
    
};