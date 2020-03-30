/*
 * @Author: Eashin
 * @Date: 2020-03-30 20:56:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/496-next-greater-element.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            int j = 0,k;
            for (; i < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) break;
            }
            for (k = j+1; k < nums2.size(); ++k) {
                if (nums2[k] > nums1[i]) {
                    res[i] = nums2[k];
                    break;
                }
            }
            if (k == nums2.size()) res[i] = -1;
        }
        return res;
    }
};

int main() {
    vector<int> nums1, nums2;
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(2);

    nums1.push_back(4);
    nums1.push_back(1);
    nums1.push_back(2);

    Solution solution;
    vector<int> r;
    r = solution.nextGreaterElement(nums1,nums2);
    for (auto i : r) {
        cout << i << " ";
    }

    // 1 3 -1
}