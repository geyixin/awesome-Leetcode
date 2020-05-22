/*
 * @Author: Eashin
 * @Date: 2020-05-22 22:26:12
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-22 22:59:14
 * @Description: 
 * @FilePath: /greedy/1046-last-stone-weight.cpp
 */ 

#include<iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (1) {
            if (stones.empty()) return 0;
            if (stones.size() == 1) return stones[0];
            if (stones[0] == 0) return 0;
            sort(stones.begin(),stones.end(),greater<int>());
            if (stones[0] == stones[1])  { stones.erase(stones.begin()); stones.erase(stones.begin());}
            else { stones[0] -= stones[1]; stones.erase(stones.begin()+1); }
        }
    }
};

int main() {
    Solution so;
    int a[] = {2,2};
    vector<int> stones(a,a+sizeof(a)/sizeof(int));
    cout << so.lastStoneWeight(stones) << endl;
    return 0;
}