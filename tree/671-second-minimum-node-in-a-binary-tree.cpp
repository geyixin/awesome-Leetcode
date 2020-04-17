/*
 * @Author: Eashin
 * @Date: 2020-04-17 11:34:29
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-17 12:50:48
 * @Description: 
 * @FilePath: /tree/671-second-minimum-node-in-a-binary-tree.cpp
 */


#include <iostream>
#include <set>
#include <queue>

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
    // 迭代层序遍历
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        set<int> s; s.insert(root->val);
        helper(root,root->val,s);
        if (s.size() == 1) return -1;
        set<int>::iterator it = s.upper_bound(root->val);
        return *it;
    }

    void helper(TreeNode* node, int val, set<int>& s) {
        if (!node) return;
        queue<TreeNode*> q; q.push(node);
        while (!q.empty() && s.size( ) < 3) {
            int size = q.size();
            while (size -- && s.size( ) < 3) {
                node = q.front(); q.pop();
                if (node->val > val) s.insert(node->val);
                if (node->left) {
                    // 此时无需再访问该左支及其以下节点。因为题目规定：子节点值都不比父节点值小
                    if (node->left->val > val) s.insert(node->left->val); 
                    else q.push(node->left);
                }
                if (node->right) {
                    // 同理
                    if (node->right->val > val) s.insert(node->right->val);
                    else q.push(node->right);
                }
            }
        }
    }
};

// 笔记1
/*
    set 默认递增排序。
    set 只能保存独一的元素。这个“独一”就是根据默认 cmp 函数去判断的。
        cmp 认为的独一可以是元素是否相等，也可以是元素的长度。
    
    set添加元素：
        1.  int a[] = {2,3,4,1,5};
            set<int> s(a,a+5);
            for (auto it = s.begin(); it!=s.end(); it++) {
                cout << *it << " "; // 1 2 3 4 5
            }
        2.  set<int> s;
            s.insert(3);
            s.insert(2);
    
    set 排序：
        1.  // 重载 cmp 
            struct cmp {
                bool operator() (const string& str1, const string& str2) const {
                    return str1.length() < str2.length();   // 比较的是长度，即认为长度不一样才是真的不一样。
                }
            };

            int main() {
                string str[] = {"abc", "abcd", "bdd", "r", "puyt"};
                set<string,cmp> s(str,str+6); 
                for (auto it = s.cbegin(); it!=s.cend(); it++) {    // 加了自定义的 cmp 则需写成 cbeging cend。c需要加上。
                    cout << *it << " "; // r abc abcd 【bdd、puyt不存在了。所以这儿的“独一”就是长度】
                }
                return 0;
            }
        2.
            struct cmp {
                bool operator() (const string& str1, const string& str2) const {
                    return str1[0] > str2[0]; // 比较的首元素
                }
            };

            int main() {
                string str[] = {"abc", "abcd", "bdd", "r", "puyt"};
                set<string,cmp> s2(str,str+6); 
                for (auto it = s2.cbegin(); it!=s2.cend(); it++) {
                    cout << *it << " "; // r puyt bdd abc 
                }
                return 0;
            }

*/