    stack<pair<int,int>> s;
    int index;

    StockSpanner() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        index = -1;
    }
    
    int next(int price) {
        index = index + 1;
        while (!s.empty() && s.top().second <= price) s.pop();
        if (s.empty()) {
            s.push ({index,price});
            return index + 1;
        }
        int result = s.top().first;
        s.push({index,price});
        return index - result; 
    }
