/*
 * @Author: Eashin
 * @Date: 2020-04-17 15:30:49
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/572-subtree-of-another-tree.cpp
 */

#include <iostream>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// 注意一种特殊情况：
/*
    1        1
  /
1

*/

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return helper(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }

    bool helper(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val == t->val) return helper(s->left,t->left) && helper(s->right,t->right);
        return false;
    }
};