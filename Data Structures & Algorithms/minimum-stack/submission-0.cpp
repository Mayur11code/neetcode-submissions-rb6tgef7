class MinStack {
public:
    int min;
    vector<int> stk;
    vector<int> prefix;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        if(prefix.empty()){
            prefix.push_back(val);
        }
        else if(prefix.back() > val){
            prefix.push_back(val);
        }
        else{
            prefix.push_back(prefix.back());
        }
    }
    
    void pop() {
        stk.pop_back();
        prefix.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return prefix.back();
        
    }
};
