/*
 * @Author: Eashin
 * @Date: 2020-04-14 12:11:29
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-14 13:18:19
 * @Description: 
 * @FilePath: /tree/606-construct-string-from-binary-tree.cpp
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
/*
思路：分5种情况。
    1，root为空，返回 “”
    2，没有孩子，返回root；
    3，无右孩子，有左孩子，那加 (左孩子)。
    4，有右孩子，无左孩子，那加 ()(右孩子)；
    5，有右孩子，也有左孩子，那加 (左孩子)(右孩子)；
    其实可以发现，只要右孩子存在，不管左孩子存在与否，左边都要加 ()。所以情况4、5其实就可以合成一个情况
*/
    // 递归：tree2str
    string tree2str(TreeNode* t) {
        if (!t) return "";
        if (!t->left && !t->right) return to_string(t->val);
        if (!t->right) return to_string(t->val) + "(" + tree2str(t->left) + ")";
        return to_string(t->val) + "(" + tree2str(t->left) + ")"+"(" + tree2str(t->right) + ")";
    }

    // 迭代：tree2str_2 【参考官方题解Java版：https://leetcode-cn.com/problems/construct-string-from-binary-tree/solution/gen-ju-er-cha-shu-chuang-jian-zi-fu-chuan-by-leetc/】
    string tree2str_2(TreeNode* t) {
        if (!t) return "";
        string res = "";
        stack<TreeNode*> stack; vector<TreeNode*> visited;
        stack.push(t);
        while (!stack.empty()) {
            t = stack.top();
            if (find(visited.begin(),visited.end(),t)!=visited.end()) {
                stack.pop();
                res += ")";
            } 
            else {
                visited.push_back(t);
                res = res + "(" + to_string(t->val);
                if (!t->left && t->right) res += "()";
                if (t->right) stack.push(t->right); // right先进，后出
                if (t->left) stack.push(t->left);   // left后进，先出
            }
        }
        return res.substr(1,res.size()-2);  // substr(a,b) 截取：从 第 a 位开始（包括第a位），连续 b个元素。
    }
};