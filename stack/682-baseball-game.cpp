/*
 * @Author: Eashin
 * @Date: 2020-03-31 10:15:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/682-baseball-game.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        for (auto i : ops) {
            if (i == "C") s.pop();
            else if (i == "D") s.push(2*s.top());
            else if (i == "+") {
                int tmp = s.top();
                s.pop();
                int k = tmp + s.top();
                s.push(tmp);
                s.push(k);
            }
            else s.push(atoi(i.c_str()));
        }
        return mySum(s);
    }

    int mySum(stack<int> s) {
        int res = 0;
        while(!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
private:
    int t;
    stack<int> s;
};


int main() {
    vector<string> s;
    s.push_back("5");
    s.push_back("2");
    s.push_back("C");
    s.push_back("D");
    s.push_back("+");

    Solution solutin;

    cout << solutin.calPoints(s);   // 30
}