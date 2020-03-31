/*
 * @Author: your name
 * @Date: 2020-03-31 12:46:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/1047-remove-all-adjacent-duplications-in-string.cpp
 */


#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
// 因为Leetcode表明这是stack的题目，我就试着用stack，可结果超时，，，
class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for (int i = 0; i < S.size(); ++i) {
            if (st.empty() || st.top() != S[i]) st.push(S[i]);
            else st.pop();
        }
        while (!st.empty())
        {
            res = st.top() + res;   // 个人觉得是这儿出问题了，，，
            st.pop();
        }
        return res;
    }
private:
    stack<char> st;
};
*/

// 偷学的版本

class Solution {
public:
    string removeDuplicates(string S) {
        int t = 0;
        for (char ch : S) {
            if (t == 0 || S[t - 1] != ch) {
                S[t++] = ch;
            } else {
                t--;
            }
        }
        S.resize(t);
        return S;
    }
};

int main() {
    string s = "abbaca";
    Solution solution;
    cout << solution.removeDuplicates(s);
}