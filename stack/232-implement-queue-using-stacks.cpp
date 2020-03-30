/*
 * @Author: Eashin
 * @Date: 2020-03-30 21:35:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/232-implement-queue-using-stacks.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1_in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2_out.empty()) {
            while (!s1_in.empty()) {
                s2_out.push(s1_in.top());
                s1_in.pop();
            }
        }
        int tmp = s2_out.top();
        s2_out.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2_out.empty()) {
            while (!s1_in.empty()) {
                s2_out.push(s1_in.top());
                s1_in.pop();
            }
        }
        return s2_out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1_in.empty() && s2_out.empty());
    }
private:
    stack<int> s1_in, s2_out;
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);  
    cout << queue.peek() << endl;  // 返回 1
    cout << queue.pop() << endl;   // 返回 1
    cout << queue.empty() << endl; // 返回 false
}