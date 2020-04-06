/*
 * @Author: Eashin
 * @Date: 2020-04-06 16:46:10
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-06 20:08:46
 * @Description: 
 * @FilePath: /tree/559-maximum-depth-of-n-ary-tree.cpp
 */

#include <iostream>
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
    // 递归：maxDepth
    int maxDepth(Node* root) {
        if (!root) return 0;
        else if (root->children.empty()) return = 1;
        else {
            vector<int> v;
            for (auto item : root->children) {
                v.push_back(maxDepth(item));
            }
            return *max_element(v.begin(),v.end())+1;   // 求vector中最大值：*max_element
        }
    }

    // 迭代：maxDepth_2
    int maxDepth_2(Node* root) {
        
    }
};