/*
 * @Author: Eashin
 * @Date: 2020-06-29 22:34:49
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-29 22:43:00
 * @Description: 1108. IP 地址无效化 【https://leetcode-cn.com/problems/defanging-an-ip-address/】
 * @FilePath: /string/1108-defanging-an-ip-address.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        vector<int> pos;
        for (int i = 0; i < address.length(); ++i) {
            if (address[i] == '.') {
                pos.push_back(i);
            }
        }
        for (int j = 0; j < pos.size(); ++j) {
            address.replace(pos[j]+2*j,1,"[.]");    // 替换开始位置，连续替换的个数，替换上的字符串
        }
        return address;
    }
};