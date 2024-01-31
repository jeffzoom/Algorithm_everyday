class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop(); // 弹出 不返回
        }
        int out = stk2.top(); // 返回
        stk2.pop(); // 弹出
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop(); // 弹出
        }
        return out;
    }
    
    int peek() {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop(); // 弹出 不返回
        }
        int out = stk2.top(); // 返回
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop(); // 弹出
        }
        return out;
    }
    
    bool empty() {
        if (stk1.empty()) return true;
        else return false;
    }
private:
    stack<int> stk1;
    stack<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */