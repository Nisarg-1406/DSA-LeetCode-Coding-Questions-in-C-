    // 2 Approaches
    int findLHS(vector<int>& nums) {
        // Using 2 Pass
        unordered_map<int,int> m;
        for (auto i : nums) m[i]++;
        int res = 0;
        for (auto it : m) {
            if(m.count(it.first+1) != 0) res = max(res, it.second + m[it.first+1]);
        }
        return res;
        
        // Using 1 Pass
        unordered_map<int,int>m;
        int res = 0;
        for(auto i: nums){
            m[i]++;
            if(m.count(i+1))
                res = max(res, m[i] + m[i+1]);
            if(m.count(i-1))
                res = max(res, m[i] + m[i-1]);
        }
        return res;        
    }
