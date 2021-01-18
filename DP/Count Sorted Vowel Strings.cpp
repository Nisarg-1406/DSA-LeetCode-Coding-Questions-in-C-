    2 Approaches 
    
    1st Approach - Using 2D DP - Bottom Up DP
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n + 1, vector<int>(6));
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= 5; ++k)
                dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
        return dp[n][5];
    }
    2nd Approach - Using 1D DP - Bottom Up DP
    int countVowelStrings(int n) {    
        vector<int> dp = {0, 1, 1, 1, 1, 1};
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= 5; k++) 
                dp[k] = dp[k] + dp[k-1];
        return dp[5];
     }
