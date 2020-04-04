/*
 * @Author: Eashin
 * @Date: 2020-04-04 21:33:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /tree/700-search-in-a-binary-search-tree.cpp
 */


#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    // 递归：searchBST
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }

    // 迭代：searchBST_2
    TreeNode* searchBST_2(TreeNode* root, int val) {
        while (root && (root->val != val))
        {
            root  = root->val > val ? root->left : root->right;
        }
        return root;  // 如果因为root为空跳出while的，那返回为空的root没问题。如果因为找到了，那返回也没问题。        
    }
};