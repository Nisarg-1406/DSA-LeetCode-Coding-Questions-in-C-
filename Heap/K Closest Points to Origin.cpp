    Approach - 1 - Using Priority Queue and Pair
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

    Approach - 2 - Using Max Heap -> Using Priority Queue and Vector
    CODE - 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>,compare> pq;
        for (vector<int>& point : points) {
            pq.push(point);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };


    Approach - 3 - Using Min Heap - Using Priority Queue and Vector
    CODE - 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>,vector<vector<int>>,compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for(int i =0;i<K;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
    struct compare{
        bool operator()(vector<int>& p,vector<int>& q){
            return p[0]*p[0] + p[1]*p[1] > q[0]*q[0] + q[1]*q[1];
        }
    };

    
    Approach - 4 - Using MultiSet of Max Heap -
    CODE -
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multiset<vector<int>, compare> mset;
        for(vector<int> &point : points){
            mset.insert(point);
            if (mset.size() > K) {
                mset.erase(mset.begin()); //mp.end creates out the runtime error in this case
            }
        }
        vector<vector<int>> ans;
        copy_n(mset.begin(), K, back_inserter(ans));
        return ans;
    }
    struct compare {
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };

    
    Approach - 5 - Using MultiSet of Min Heap -
    CODE -
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multiset<vector<int>,compare> mset(points.begin(),points.end());
        vector<vector<int>> ans;
        copy_n(mset.begin(), K, back_inserter(ans));
        return ans;
    }
    struct compare {
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
