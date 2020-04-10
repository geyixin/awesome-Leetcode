/*
 * @Author: Eashin
 * @Date: 2020-04-10 11:05:05
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/100-same-tree.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 递归：isSameTree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((!p && q) || (p && !q)) return false;
        if (p->val == q->val) return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
        return false;
    }

    // 迭代：isSameTree_2
    bool isSameTree_2(TreeNode* p, TreeNode* q) {
        stack< pair<TreeNode*,TreeNode*> > s;
        s.push(pair<TreeNode*,TreeNode*>(p,q));
        TreeNode* node_p; TreeNode* node_q;
        while (!s.empty()) {
            node_p = s.top().first; node_q = s.top().second;
            s.pop();
            if (!check(node_p,node_q)) return false;
            if (node_p) {
                s.push(pair<TreeNode*,TreeNode*>(node_p->left,node_q->left));
                s.push(pair<TreeNode*,TreeNode*>(node_p->right,node_q->right));
            }
        }
        return true;
    }

    bool check(TreeNode* node_1, TreeNode* node_2) {
        if (!node_1 && !node_2) return true;
        if ((!node_1 && node_2) || (node_1 && !node_2)) return false;
        if (node_1->val != node_2->val) return false;
        return true;
    }
};