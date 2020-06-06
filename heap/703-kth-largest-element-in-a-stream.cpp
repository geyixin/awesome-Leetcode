/*
 * @Author: Eashin
 * @Date: 2020-06-06 10:49:13
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-06 11:35:55
 * @Description: 
 * @FilePath: /heap/703-kth-largest-element-in-a-stream.cpp
 */ 

#include <iostream>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (const int num : nums) {
            que.push(num);
            if (que.size() > k) que.pop();
        }
        a = k;
    }
    
    int add(int val) {
        que.push(val);
        if (que.size() > a) que.pop();
        return que.top();
    }
private:
    int a;
    priority_queue< int, vector<int>, greater<int> > que;   // 小顶堆。相比于queue，priority_queue可以自行定义优先级
};