/*
 * @Author: Eashin
 * @Date: 2020-04-17 16:04:36
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-17 16:05:55
 * @Description: 
 * @FilePath: /tree/501-find-mode-in-binary-search-tree.cpp
 */

#include <iostream>
#include <vector>

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
    // 中序遍历获得递增vector
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        inOrder(root,v);
        int cnt = 1; int cnt_max = 1;
        vector<int> res; res.push_back(v[0]);
        for(int i = 1; i<v.size(); i++) {
            if (v[i] == v[i-1]) cnt++;
            else cnt = 1;
            if (cnt > cnt_max) {
                cnt_max = cnt;
                res.clear();
                res.push_back(v[i]);
            }
            else if (cnt == cnt_max) {
                res.push_back(v[i]);
            }
        }
        return res;
    }

    void inOrder(TreeNode* root, vector<int>& v) {
        if (root) {
            inOrder(root->left,v);
            v.push_back(root->val);
            inOrder(root->right,v);
        }
        return;
    }
};