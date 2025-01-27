class StockSpanner {
    stack<pair<int, int>> stack; // price and its value
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        // curr day 
        int span = 1;
        // 
        while (!stack.empty() && stack.top().first <= price) {
            span += stack.top().second; // adding prize span to current span
            stack.pop();
        }
        stack.push({price, span}); // curr prize, calculated span
        return span;
    }
};
