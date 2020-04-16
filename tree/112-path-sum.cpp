/*
 * @Author: Eashin
 * @Date: 2020-04-16 15:38:40
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/112-path-sum.cpp
 */

#include <iostream>
//#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

/*
 【跟 257 思路相似。只不过257要保存path，本题保存的是sum】
*/

class Solution {
public:
    // 递归：hasPathSum
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        vector<int> all_sum; int tmp_sum = 0;
        helper(root,tmp_sum,all_sum);
        for (auto each_sum : all_sum) {
            if (each_sum == sum) return true;
        }
        return false;
    }

    void helper(TreeNode* p, int tmp_sum, vector<int>& all_sum) {
        if (p) {
            tmp_sum += p->val;
            if (!p->left && !p->right) all_sum.push_back(tmp_sum);
            else {
                helper(p->left,tmp_sum,all_sum);
                helper(p->right,tmp_sum,all_sum);
            }
        }
    }

    // 迭代：hasPathSum_2
    bool hasPathSum_2(TreeNode* root, int sum) {
        if (!root) return false;
        stack< pair<TreeNode*,int > > s;
        int tmp_sum = 0; vector<int> all_sum; TreeNode* node;
        s.push(pair<TreeNode*,int>(root,tmp_sum));
        while (!s.empty()) {
            node = s.top().first; tmp_sum = node->val + s.top().second; s.pop();
            if (!node->left && !node->right) all_sum.push_back(tmp_sum);
            if (node->left) s.push(pair<TreeNode*,int>(node->left,tmp_sum));
            if (node->right) s.push(pair<TreeNode*,int>(node->right,tmp_sum));
        }
        for (auto each_sum : all_sum) {
            if (each_sum == sum) return true;
        }
        return false;
    }
};