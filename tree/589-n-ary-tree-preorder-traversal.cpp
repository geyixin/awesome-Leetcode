/*
 * @Author: Eashin
 * @Date: 2020-04-04 20:51:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /tree/589-n-ary-tree-preorder-traversal.cpp
 */

#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top(); st.pop();
            if (node) res.push_back(node->val);
            if (!node->children.empty()) {
                for (int i = node->children.size() - 1; i >= 0; --i) {
                    st.push(node->children[i]);
                }
            }
        }
        return res;
    }
};