/*
 * @Author: Eashin
 * @Date: 2020-03-30 10:14:08
 * @LastEditors: Please set LastEditors
 * @Description: Leetcode 20 题。属于 stack 的 简单题。
 * @FilePath: /stack/20-valid-parentthess.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] =='[' || s[i] == '{'){
                st.push(s[i]);
            }
            else {
                if (st.empty()) return false;
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == ']' && st.top() != '[') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
        }
};

int main() {
    string s = "()";
    Solution solution;
    if (solution.isValid(s)) cout << "Yes";
    else cout << "No";
}