class MyStack {
public:
    MyStack() { 
        // 为什么不能在构造函数里面定义队列啊，我觉得吧，是这里面只能初始化，不能定义
    }
    
    void push(int x) {
        que_1.push(x);
    }
    
    int pop() {
        int out1 = this->top();
        
        for (int n = que_1.size(); n > 1; n--) {
            que_2.push(que_1.front());
            que_1.pop(); 
        }
        que_1.pop();

        while (!que_2.empty()) {
            que_1.push(que_2.front());
            que_2.pop(); 
        }
        return out1;
    }
    
    int top() {
        return que_1.back();
    }
    
    bool empty() {
        if (que_1.empty()) return true;
        else return false;
    }
private:
    queue<int> que_1, que_2;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */