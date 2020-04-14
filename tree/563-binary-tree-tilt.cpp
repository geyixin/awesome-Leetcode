/*
 * @Author: Eashin
 * @Date: 2020-04-14 09:27:34
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-14 09:47:54
 * @Description: 
 * @FilePath: /tree/563-binary-tree-tilt.cpp
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    // 两次递归【不好，每个节点被计算了多次。】
    int res = 0;
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int s = 0;
        int L = helper(root->left,s);
        s = 0;
        int R = helper(root->right,s);
        res += abs(L-R);
        findTilt(root->left);
        findTilt(root->right);
        return res;
    }

    int helper(TreeNode* root, int& s) {
        if (!root) return 0;
        s += root->val;
        helper(root->left,s);
        helper(root->right,s);
        return s;
    }

    // 升级版的递归
    int findTilt_2(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper_2(root,res);
        return res;
    }

    int helper_2(TreeNode* root, int& res) {
        if (!root) return 0;
        int L = helper_2(root->left, res);
        int R = helper_2(root->right, res);
        res += abs(L-R);
        return root->val+L+R;
    }
};