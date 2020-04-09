/*
 * @Author: Eashin
 * @Date: 2020-04-09 08:36:50
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/257-binary-tree-paths.cpp
 */

#include <iostream>
#include <vector>
#include <string>
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
    // 递归：binaryTreePaths  +  helper
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, "", res);
        return res;
    }

    void helper(TreeNode* root, string path, vector<string>& res) {
        if (root) {
            path += to_string(root->val);
            if (!root->left && !root->right) res.push_back(path);
            else {
                path += "->";
                helper(root->left, path, res);
                helper(root->right, path, res);
            }
        }
    }

    // 迭代：binaryTreePaths_2
    vector<string> binaryTreePaths_2(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        stack< pair<TreeNode*,string> > s;  // pair初始化
        TreeNode* node; string str;
        s.push(pair<TreeNode*,string>(root,str));   // pair添加
        while (!s.empty()) {
            node = s.top().first;   // pair使用
            str = s.top().second + to_string(node->val);    // pair使用
            s.pop();
            if (!node->left && !node->right) res.push_back(str);
            if (node->left) s.push(pair<TreeNode*,string>(node->left,str+"->"));
            if (node->right) s.push(pair<TreeNode*,string>(node->right,str+"->"));
        }
        return res;
    }
};