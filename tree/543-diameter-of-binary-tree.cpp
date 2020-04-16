/*
 * @Author: Eashin
 * @Date: 2020-04-16 16:30:58
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /tree/543-diameter-of-binary-tree.cpp
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

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
    // 递归：diameterOfBinaryTree + helper_1 + helper
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        vector<int> v;
        helper_1(root,v);
        return *max_element(v.begin(),v.end());
    }

    void helper_1(TreeNode* p, vector<int>& v) {
        if (p) {
            v.push_back(helper(p->left) + helper(p->right));
            helper_1(p->left,v);
            helper_1(p->right,v);
        }
        return ;
    }

    int helper(TreeNode* p) {
        if (p) {
            return max(helper(p->left), helper(p->right)) + 1;
        }
        return 0;
    }

    // 官方递归：diameterOfBinaryTree_2 + helper_2
    int diameterOfBinaryTree_2(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper_2(root,res);
        return res;
    }

    int helper_2(TreeNode* p, int& res) {
        if (!p) return 0;
        int L = helper_2(p->left,res);
        int R = helper_2(p->right,res);
        res = max(res,L+R);
        return max(L,R) + 1;
    }

    // 迭代：这，，，，
};

// 笔记1
/*
    求 vector 中最大值：
         *max_element(v.begin(),v.end());
    求 vector 中最小值：
         *min_element(v.begin(),v.end());
    求 最大值的索引：
        vector<int>:: iterator big_it = max_element(v.begin(),v.end());
        distance(v.begin(), big_it);
*/

// 笔记 2
/*
    我们知道，map 默认是按 key 递增排序的。如果想对 map 按value排序，我们可以将其放到 vector 中进行。例如：
    现有 map<int,int> m。

    class Solution {
    public:
        void paixu {
            map<int,int> m;
            vector< pair<int,int> > v;
            for (map<int,int>::iterator it = m.begin(); it!=m.end(); it++) {
                v.push_back( pair<int,int>(it->first,it->second));
            }
            sort(v.begin(),v.end(),cmp);
        }

        // static 需要。不然会提示 “reference to non-static member function must be called”。
        static bool cmp(pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        }
    }





*/