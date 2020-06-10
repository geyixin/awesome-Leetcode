/*
 * @Author: Eashin
 * @Date: 2020-06-10 14:40:42
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-10 14:52:23
 * @Description: 
 * @FilePath: /one test a day/8-palindrome-number.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> v;
        convert(x,v);
        for(int i=0, j=v.size()-1; i<j; i++,j--) {
            if (v[i] == v[j]) continue;
            else return false;
        }
        return true;
    }

    void convert(int x, vector<int>& v) {
        while (x>0) {
            v.push_back(x%10);
            x /= 10;
        }
        return;
    }
};

int main() {
    Solution so = Solution();
    if (so.isPalindrome(10)) {
        cout << "10 是回文数";
    }
    else cout << "10不是回文数";
}