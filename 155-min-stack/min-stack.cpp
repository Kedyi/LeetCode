class MinStack {
public:
    vector<pair<int,int>> stack;
    MinStack() {
        
    }
    
    void push(int value) {
        if(!stack.size()){
            stack.push_back({value,value});
        }
        else{
            int mini = min(value,stack.back().second);
            stack.push_back({value,mini});
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */