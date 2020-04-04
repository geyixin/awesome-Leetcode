/*
 * @Author: Eashin
 * @Date: 2020-04-04 16:52:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /tree/590-n-ary-tree-postorder-traversal.cpp
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> store; vector<int> res;
        if (!root) return res;
        store.push(root);
        while (!store.empty()) {
            Node* node = store.top(); store.pop();
            if (node) res.push_back(node->val);
            for (auto item : node->children) {
                store.push(item);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};