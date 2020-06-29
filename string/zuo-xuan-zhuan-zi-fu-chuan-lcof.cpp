/*
 * @Author: Eashin
 * @Date: 2020-06-29 22:23:46
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-29 22:30:26
 * @Description: 剑指 Offer 58 - II. 左旋转字符串【https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/】
 * @FilePath: /string/zuo-xuan-zhuan-zi-fu-chuan-lcof.cpp
 */ 

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n,s.length()).append(s.substr(0,n));
    }
};