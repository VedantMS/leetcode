class MinStack {
public:
    vector<int> st, minSt;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);

        if (minSt.empty()) {
            minSt.push_back(value);
        }

        else {
            minSt.push_back(min(value, minSt.back()));
        }
    }
    
    void pop() {
        st.pop_back();
        minSt.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
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