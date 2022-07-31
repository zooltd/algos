#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (out.size()) {
            int x = out.top();
            out.pop();
            return x;
        }
        while (in.size()) {
            out.push(in.top());
            in.pop();
        }
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        int x = pop();
        out.push(x);
        return x;
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
private:
    stack<int> in;
    stack<int> out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

