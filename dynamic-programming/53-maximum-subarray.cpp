/*
 * @Author: Eashin
 * @Date: 2020-05-26 16:40:04
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-26 17:07:30
 * @Description: 
 * @FilePath: /dynamic-programming/53-maximum-subarray.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

/*
    pre表示目前的和，max_sum表示最大和.
    当遇到一个新的num，考虑要不要加到pre上，还是重新开始，取决于num 与 num+pre 的相对大小。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], pre = 0;
        for (auto num : nums) {
            pre = max(num,num+pre);
            max_sum = max(max_sum,pre);
        }
        return max_sum;
    }
};