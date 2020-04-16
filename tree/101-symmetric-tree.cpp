/*
 * @Author: Eashin
 * @Date: 2020-04-16 14:29:27
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/101-symmetric-tree.cpp
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
    // 迭代：isSymmetric 【层序遍历】
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q; q.push(root);
        vector<int> v; v.push_back(root->val);
        int size = 0;
        while (!q.empty()) {
            if (!helper(v)) return false;
            v.clear();
            size = q.size();
            while (size --) {
                root = q.front(); q.pop();
                if (root->left) { 
                    q.push(root->left);
                    v.push_back(root->left->val);
                }
                else {v.push_back(INT_MIN);}
                if (root->right) { 
                    q.push(root->right);
                    v.push_back(root->right->val);
                }
                else {v.push_back(INT_MIN);}
            }
        }
        return true;
    }

    bool helper(vector<int> v) {
        int i=0, j=v.size()-1;
        for(;i<j;i++,j--){
            if (v[i] == v[j]) continue;
            else return false;
        }
        return true;
    }

    // 官方迭代思路【改成C++版】
    bool isSymmetric_1(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* node1; TreeNode* node2;
        q.push(root); q.push(root);
        while (!q.empty()) {
            node1 = q.front(); q.pop();
            node2 = q.front(); q.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;
            q.push(node1->left); q.push(node2->right);
            q.push(node2->left); q.push(node1->right);
        }
        return true;
    }


    // 递归：isSymmetric_2
    bool isSymmetric_2(TreeNode* root) {
        if (!root) return true;
        return helper_2(root->left,root->right);
    }

    bool helper_2(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val == q->val) return helper_2(p->left,q->right) && helper_2(p->right, q->left);
        return false;
    }
};