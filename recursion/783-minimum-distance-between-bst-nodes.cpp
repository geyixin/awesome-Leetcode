/*
 * @Author: Eashin
 * @Date: 2020-06-03 10:04:30
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-03 22:24:20
 * @Description: 
 * @FilePath: /recursion/783-minimum-distance-between-bst-nodes.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        InOrder(root,v);
        int res = INT_MAX;
        for(int i = 1; i<v.size(); ++i) {
            res = min(res, v[i]-v[i-1]);
        }
        return res;
    }

    void InOrder(TreeNode* root, vector<int>& v) {
        if(root) {
            InOrder(root->left, v);
            v.push_back(root->val);
            InOrder(root->right, v); 
        }
        return;
    }
};
