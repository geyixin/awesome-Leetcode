/*
 * @Author: Eashin
 * @Date: 2020-04-13 17:03:03
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-13 21:13:44
 * @Description: 
 * @FilePath: /tree/472-path-sum-iii.cpp
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 层序遍历+递归 【思想：按层检索每个节点，然后检索以该节点为根的所有路线中的值和等于sum的路线数量】
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = 0; int tmp_sum; queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            root = q.front(); q.pop();
            tmp_sum = 0;
            res += helper(root, tmp_sum, sum);
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }
        return res;
    }

    int helper(TreeNode* root, int tmp_sum, int sum) {
        int r = 0;
        tmp_sum += root->val;
        if (tmp_sum == sum) r++;
        if (root->left) r += helper(root->left, tmp_sum, sum);
        if (root->right) r += helper(root->right, tmp_sum, sum);
        return r;
    }

    // 两次递归【源自：https://leetcode-cn.com/problems/path-sum-iii/solution/shu-de-bian-li-lu-jing-zong-he-ii-shao-zuo-gai-don/】
    int pathSum_2(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == sum) res++;
        res += helper_2(root->left,sum-root->val);
        res += helper_2(root->right,sum-root->val);

        res += pathSum_2(root->left,sum);
        res += pathSum_2(root->right,sum);
        return res;
    }

    int helper_2(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == sum) res++;
        res += helper_2(root->left,sum-root->val);
        res += helper_2(root->right,sum-root->val);
        return res;
    }
};