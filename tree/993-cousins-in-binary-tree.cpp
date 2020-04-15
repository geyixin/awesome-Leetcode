/*
 * @Author: Eashin
 * @Date: 2020-04-15 09:34:38
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-15 18:47:03
 * @Description: 
 * @FilePath: /tree/993-cousins-in-binary-tree.cpp
 */

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 迭代：isCousins
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        queue<TreeNode*> q; q.push(root);
        int size = 0;
        while (!q.empty()) {
            size = q.size(); vector<int> v;
            for (int i=0; i<size; i++) {
                root = q.front(); q.pop();
                if (root) {
                    v.push_back(root->val);
                    q.push(root->left);
                    q.push(root->right);
                }
                else {
                    v.push_back(101); // 树上节点为2-100之间
                }
            }
            int pos_x = pos(v,x);
            int pos_y = pos(v,y);
            if (pos_x == -1 && pos_y == -1) continue;
            else if (pos_x == -1 || pos_y == -1) return false;
            else {
                if (abs(pos_x-pos_y)>1) {
                    return true;
                }
                else if ((max(pos_x,pos_y) & 1) ==0) return true;   // 很巧妙【https://leetcode-cn.com/problems/cousins-in-binary-tree/solution/c-ceng-xu-bian-li-jia-pan-duan-so-easy-by-zuo-10/】
                else return false;
            }
        }
        return false;
    }

    int pos(vector<int> v, int x) {
        vector<int>::iterator it_x = find(v.begin(),v.end(),x);
        if (it_x!=v.end()) {
            return distance(v.begin(),it_x);
        }
        return -1;
    }

    // 递归：isCousins_2 【源自：https://leetcode-cn.com/problems/cousins-in-binary-tree/solution/cli-yong-dfshe-maprong-qi-jian-ji-yi-dong-by-weiwe/】
    map<int,int> dep;
    map<int,int> par;
    bool isCousins_2(TreeNode* root, int x, int y) {
        helper(root,NULL);
        return dep[x] == dep[y] && par[x] != par[y];
    }

    void helper(TreeNode* node, TreeNode* parent) {
        if (node) {
            if (parent) {
                dep[node->val] = dep[parent->val] + 1;
                par[node->val] = parent->val;
            }
            else {
                dep[node->val] = 0;
                par[node->val] = 101; // 树上节点为2-100之间
            }
            helper(node->left, node);
            helper(node->right,node);
        }
    }
};