/*
 * @Author: your name
 * @Date: 2020-03-31 15:30:43
 * @LastEditTime: 2020-03-31 15:46:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/912-sort-an-array.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @description: 快排
 * @param: vector
 * @return: vector
 */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return;
        int pivot = nums[begin];
        int i = begin + 1; int j = end;
        while (i <= j)
        {
            if (nums[i] > pivot && nums[j] < pivot) swap(nums[i++],nums[j--]);
            else if (nums[i] <= pivot) i++;
            else if (nums[j] >= pivot) j--;
        }
        swap(nums[j],nums[begin]);
        quickSort(nums, begin, j-1);
        quickSort(nums, j+1, end);
    }
};

void printVector(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
}

int main() {
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    Solution solution;
    solution.sortArray(nums);

    printVector(nums);
}