    int maxEnvelopes(vector<vector<int>>& envelopes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = envelopes.size();
        if (n == 0) return 0;
        sort (envelopes.begin(), envelopes.end());
        vector<int> dp(n+1, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
                if (ans < dp[i]) ans = dp[i];
            }
        }
        return ans;
    }
