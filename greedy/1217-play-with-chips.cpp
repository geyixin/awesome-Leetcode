/*
 * @Author: Eashin
 * @Date: 2020-05-20 21:28:31
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-20 21:59:57
 * @Description: 
 * @FilePath: /greedy/1217-play-with-chips.cpp
 */ 

#include<iostream>
#include <vector>

#define max_value 10^9

using namespace std;

/*
    其实就是分别计算奇数数字个数和所有偶数数字个数，返回个数最小的。比如：
    2 2 2 3 3 3 4  ->   3个2 和 1个4 一组，总共4个数字；3个3一组，共3个数字。
    由于2和4的位置互移所需花费皆为0，那3个3移到2或者4位置都是3次。所以结果就是3
*/

class Solution {
public:

    int minCostToMoveChips(vector<int>& chips) {
        long a[max_value] = {0};
        int cnt_ji = 0, cnt_ou = 0;
        for (auto i : chips) {
            if (i%2 == 0) cnt_ou ++;
            else cnt_ji ++;
        }
        return cnt_ou < cnt_ji ? cnt_ou : cnt_ji;
    }
};