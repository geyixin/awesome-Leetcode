/*
 * @Author: Eashin
 * @Date: 2020-04-03 23:26:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /Finite-Automaton/8-string-to-integer-atoi.cpp
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// ----------状态机解法-----------

/*
    状态机：给定状态s，新来一个字符c，使得状态转变成s‘
    (横坐标是c，纵坐标是s，中间是s')
    (sign 为 + ，或者 -  最后要乘到数字上)
                ''      +/-     number      other
    ----------|--------------------------------------
    start     | start   signed  in_number   end
    signed    | end     end     in_number   end
    in_number | end     end     in_number   end
    end       | end     end     end         end
*/

class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start",{"start","signed","in_number","end"}},
        {"signed",{"end","end","in_number","end"}},
        {"in_number",{"end","end","in_number","end"}},
        {"end",{"end","end","end","end"}}
    };

    int get_column(char c) {
        if (isspace(c)) return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long res = 0;

    void get(char c) {
        state = table[state][get_column(c)];
        if (state == "in_number") {
            res = res * 10 + c - '0';
            res = sign == 1 ? min(res,(long long)INT_MAX) : min(res,-(long long)INT_MIN);
        }
        else if (state == "signed") {
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton aut;
        for (char c : str) {
            aut.get(c);
        }
        return aut.res * aut.sign;
    }
};

int main() {
    string str = "  word svdf s234fd   ";
    Solution so;
    cout << so.myAtoi(str);
}

// ----------------！！！以下解法较为正常，但有边界出错！！！-----------------------

class Solution2 {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int sign = 1; long res = 0; int i = 0; int len = str.size();
        while (i < len && str[i] == ' ') ++i;   // 剔除左边空格
        if (i < len && (str[i] == '+' || str[i] == '-')) sign = (str[i++] == '+') ? 1 : -1; // 确定正负号
        while (i < len && str[i] <= '9' && str[i] >= '0') {
            if (res > INT_MAX / 10) return (sign == 1) ? INT_MAX : INT_MIN;
            res = res * 10 + str[i++] - '0';
        }
        return res * sign;
    }
};