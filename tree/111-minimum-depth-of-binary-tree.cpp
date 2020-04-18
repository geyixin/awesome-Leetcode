/*
 * @Author: Eashin
 * @Date: 2020-04-18 14:42:19
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/111-minimum-depth-of-binary-tree.cpp
 */

#include <iostream>
#include <queue>

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
    // 递归：minDepth
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && root->right) return minDepth(root->right)+1;
        if (root->left && !root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }

    // 迭代：minDepth_2
    int minDepth_2(TreeNode* root) {
        if (!root) return 0;
        int dep = 1;
        queue< pair<TreeNode*,int> > q; q.push(make_pair(root,dep));
        while (!q.empty()) {
            root = q.front().first; dep = q.front().second; q.pop();
            if (!root->left && !root->right) return dep;
            if (root->left) q.push(make_pair(root->left,dep+1));
            if (root->right) q.push(make_pair(root->right,dep+1));
        }
        return 0;
    }
};

