/*
 * @Author: Eashin
 * @Date: 2020-04-05 20:15:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /tree/108-convert-sorted-array-to-binary-search-tree.cpp
 */

#include <iostream>
#include <vector>

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
    // 递归：sortedArrayToBST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        int mid = nums.size()/2;
        TreeNode * root = new TreeNode(nums[mid]);
        vector<int> L(nums.begin(),nums.begin()+mid);
        vector<int> R(nums.begin()+mid+1,nums.end());
        root->left = sortedArrayToBST(L);
        root->right = sortedArrayToBST(R);
        return root;
    }

/*
***--------- 迭代暂时不会 -----------***
    // 迭代：sortedArrayToBST_2
    TreeNode* sortedArrayToBST_2(vector<int>& nums) {

    }
*/
};