    // Using Stack 
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> s;
        vector<int> result(T.size());
        for(int i=0;i<T.size();i++) {
            while(!s.empty() && (s.top().first < T[i])) {
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({T[i],i});
        }
        return result;
    }
