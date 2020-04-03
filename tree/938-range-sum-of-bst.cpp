/*
 * @Author: Eashin
 * @Date: 2020-04-01 17:33:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /tree/938-range-sum-of-bst.cpp
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        if (root->val > R) return rangeSumBST(root->left, L, R);
        else if (root->val < L) return rangeSumBST(root->right, L, R);
        else return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};


int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) 
          return 0;
        TreeNode* cur = root;
        bool add = false;
        long sum = 0;
        while(cur) {
          if (!cur->left) {
              int val = cur->val;
              if (val == L) add = true;
              if (add) {sum = sum + val;}
              if (val == R) break;
              cur = cur->right;
          } else {
              auto* temp = cur->left;
              while (temp->right) {
                  temp = temp->right;
              }
              temp->right = cur;
              auto left = cur->left;
              cur->left = nullptr;
              cur = left;
          }
        }
      return sum;
    }


