class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() : A(), B() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> *inQ, *outQ;
        getQ(&inQ, &outQ);

        inQ->push(x);
        while (outQ->size()) {
            int x = outQ->front();
            outQ->pop();
            inQ->push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result;
        queue<int> *inQ, *outQ;
        getQ(&inQ, &outQ);
        result = outQ->front();
        outQ->pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        int result;
        queue<int> *inQ, *outQ;
        getQ(&inQ, &outQ);
        result = outQ->front();
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (!A.size() && !B.size());
    }
private:
    queue<int> A;
    queue<int> B;
    void getQ(queue<int> **inQ, queue<int> **outQ) {
        if (!A.size()) {
            *inQ = &A;
            *outQ = &B;
        } else if (!B.size()) {
            *inQ = &B;
            *outQ = &A;
        }
    }
};