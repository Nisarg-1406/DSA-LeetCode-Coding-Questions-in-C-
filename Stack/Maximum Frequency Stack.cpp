    // Method - 1 - Using priority Queue
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> freq;
    int pos = 0;
    FreqStack() { }
    
    void push(int x) {
        int val = freq[x]++;
        pq.emplace(val, make_pair(pos, x));
        pos = pos + 1;
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
    
    // Method - 2 - Using multimap
    //If used greater<int> then giving priority to more frequent elements even though key is same and hence its not maintaining the order of the i/p, If push is [5],[7],[5],[7],[4],[5], then o/p during pop is - 5,5,7,5; but o/p should be 5,7,4,5 ....therefore for the correct o/p - need to use greater_equal.
    
    multimap<int, int, greater_equal<int>> stack;
    unordered_map<int, int> freq;

    FreqStack() { }

    void push(int x){
        stack.insert({freq[x]++, x});
    }

    int pop() {
        int res = stack.begin()->second;
        stack.erase(stack.begin());
        freq[res]--;
        return res;
    }
