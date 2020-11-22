#include <iostream>
#include <stack>
using std::stack;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(): normal(), min() {
        
    }
    
    void push(int x) {
        normal.push(x);
        if (min.size()) {
            if (x <= min.top()) {
                min.push(x);
            } else {
                min.push(min.top());
            }
        } else {
            min.push(x);
        }
        
    }
    
    void pop() {
        normal.pop();
        min.pop();
    }
    
    int top() {
        return normal.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> normal;
    stack<int> min;
};


int main()
{
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-1);
    std::cout << s.getMin() << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.getMin() << std::endl;
}