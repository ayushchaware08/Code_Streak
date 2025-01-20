class MyQueue {
public:
stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(input.size()) output.push(input.top()), input.pop();
        }
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if(output.empty()){
            while(input.size())
                output.push(input.top()), input.pop();

        } 
        return output.top();
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};
