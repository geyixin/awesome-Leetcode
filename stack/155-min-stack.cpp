/*
 * @Author: Eashin
 * @Date: 2020-03-30 20:43:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /stack/155-min-stack.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        real_s.push(x);
        if (min_s.empty() || x < min_s.top()) min_s.push(x);
        else min_s.push(min_s.top());
    }
    
    void pop() {
        real_s.pop();
        min_s.pop();
    }
    
    int top() {
        return real_s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
private:
    stack<int> real_s,min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl; // 0
    cout << minStack.getMin() << endl;  // -2
}