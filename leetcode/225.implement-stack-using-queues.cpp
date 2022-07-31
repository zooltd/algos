#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
public:
    MyStack() {
        in = new queue<int>();
        tmp = new queue<int>();
    }

    ~MyStack() {
        delete in;
        delete tmp;
    }
    
    void push(int x) {
        in->push(x);
    }
    
    int pop() {
        while (in->size() >= 2) {
            tmp->push(in->front());
            in->pop();
        }
        int x = in->front();
        in->pop();
        swap(in, tmp);
        return x;
    }
    
    int top() {
        int x = pop();
        in->push(x);
        return x;
    }
    
    bool empty() {
        return in->empty() && tmp->empty();
    }
private:
    queue<int>* in;
    queue<int>* tmp;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

