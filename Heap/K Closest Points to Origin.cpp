    * Using Max-heap as we want closest point  
    * Making pair of pair
    * Taking key as the pair first value which act as the distance from origin. 
    * Distance - points[i][0] * points[i][0] + points[i][1] * points[i][1]
    * For second value in the pair - It is the vector of input - i.e points[i][0] & points[i][1]
    
    CODE - 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        typedef pair<int, pair<int, int>> ppi;
        int n = points.size();
        priority_queue<ppi> pq;
        for (int i = 0; i < n; i++) {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
            if (pq.size() > K) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
