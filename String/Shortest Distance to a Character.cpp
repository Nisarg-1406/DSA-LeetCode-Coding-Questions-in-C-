    // 2 Approach - Both 2 Pass Solution with different time Complexity. 
    vector<int> shortestToChar(string s, char c) {
        // Method 1 - 2 Pass solution - T.C - O(N^2)
        vector<int> pos, dist;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) pos.push_back(i);
        }
        for(int i = 0; i < s.size(); i++){
            int mn = INT_MAX;
            for(int j = 0; j < pos.size(); j++){
                mn = min(mn, abs(pos[j] - i));
            }
            dist.push_back(mn);
        }
        return dist;
        
        // Method 2 - 2 Pass Solution - T.C - O(N)
        int n = s.size(), pos = -n;
        vector<int> res(n, n);
        for (int i = 0; i < n; i++) {
            if (s[i] == c) pos = i;
            res[i] = i - pos;
        }
        for (int i = pos - 1; i >= 0; i--) {
            if (s[i] == c)  pos = i;
            res[i] = min(res[i], pos - i);
        }
        return res;
    }
