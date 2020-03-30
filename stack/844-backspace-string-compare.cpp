/*
 * @Author: your name
 * @Date: 2020-03-30 17:00:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/844-backspace-string-compare.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    stack<char> s,t;
    bool backspaceCompare(string S, string T) {
        for (auto i : S){
            if (i == '#' && !s.empty()) s.pop();
            if (i != '#') s.push(i);
        }
        for (auto i : T){
            if (i == '#' && !t.empty()) t.pop();
            if (i != '#') t.push(i);
        }
        return s == t;
    }
};

int main() {
    Solution solution;
    string S = "#a#bcc";
    string T = "bccc#";
    if (solution.backspaceCompare(S,T)) cout << "yes";
    else cout << "no";
}