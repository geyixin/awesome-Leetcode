/*
 * @Author: your name
 * @Date: 2020-03-30 22:13:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/225-implement-stack-using-queues.cpp
 */

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        int r = q1.back();
        int len = q1.size();
        for (int i = 0; i < len-1; ++i) {
            tmp.push(q1.front());
            q1.pop();
        }
        q1.swap(tmp);
        return r;
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
};

int main() {
    MyStack s;
    s.push(3);
    cout << s.top() << " "; // 3
    cout << s.pop() << " "; // 3
    cout << s.empty();  // 1
}