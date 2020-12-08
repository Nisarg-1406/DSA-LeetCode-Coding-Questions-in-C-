// It uses the concept of longest increasing subsequence (LIS)
    int findLongestChain(vector<vector<int>>& pairs) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = pairs.size();
        if (n == 0) return 0;
        sort(pairs.begin(), pairs.end());
        int longestChain = 1;
        vector<int> lis(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((pairs[j][1] < pairs[i][0]) && (lis[i] < lis[j] + 1)) {
                    lis[i] = lis[j] + 1;
                    longestChain = max(longestChain, lis[i]);
                }
            }
        }
        return longestChain;   
    }
