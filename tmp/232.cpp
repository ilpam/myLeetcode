#include <stack>
#include <cstdio>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue():in(), out(){

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top_var;
        if (!out.size()) {
            while (in.size()) {
                top_var = in.top();
                in.pop();
                out.push(top_var);
            }
        }
        top_var = out.top();
        out.pop();
        return top_var;
    }
    
    /** Get the front element. */
    int peek() {
        int top_var;
        if (!out.size()) {
            while (in.size()) {
                top_var = in.top();
                in.pop();
                out.push(top_var);
            }
        }
        top_var = out.top();
        return top_var;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (!in.size() && !out.size()) ? true : false;
    }

private:
    stack<int> in;
    stack<int> out;


};