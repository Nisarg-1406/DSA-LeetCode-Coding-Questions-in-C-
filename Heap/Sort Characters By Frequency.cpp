    string frequencySort(string s) {
        unordered_map<char,int> mp;
        typedef pair<int,char> pi;
        priority_queue<pi> pq; //using max heap
        for(auto x : s) mp[x]++;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        string st;
        while(pq.size()>0){
            //st.push_back(pq.top().second);
            /*st+=string(pq.top().first,pq.top().second);
            pq.pop();*/
            //OR this ->
            pair<int,char> p = pq.top();
            pq.pop();
            while(p.first--) {
                st.push_back(p.second);
            }
        }
        return st;
    }
