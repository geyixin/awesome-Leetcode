/*
 * @Author: Eashin
 * @Date: 2020-03-31 14:54:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/1021-remove-outermost-parentheses.cpp
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int left = 1;   // 每阶段 （ 的个数
        int right = 0;  // 每阶段 ） 的个数
        string res = "";
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == '(') left ++;
            else right++;
            if (left == right) {
                left = 1;
                right = 0;
                ++i;
            }
            else res += S[i];
        }
    return res;
    }
};

int main() {
    string S = "(()())(())";
    Solution solution;
    cout << solution.removeOuterParentheses(S); // ()()()
}