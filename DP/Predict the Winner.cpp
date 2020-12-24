    
    //Tabulation method. 
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        int dp[n][n];
        int sum = 0;
        for (int i = 0; i < n; i++) { //To calculate the sum 
            sum = sum + nums[i];
        }
        //Using Gap method to fill up the DP table.
        for (int gap = 0; gap < n; ++gap) { 
            for (int i = 0, j = gap; j < n; ++i, ++j) { 
                if (gap == 0) dp[i][j] = nums[i];
                else if (gap == 1) dp[i][j] = max (nums[i], nums[j]);
                else { // gap of >= 2
                    int val1 = nums[i] + min (dp[i+2][j], dp[i+1][j-1]);
                    int val2 = nums[j] + min (dp[i+1][j-1], dp[i][j-2]);
                    int val = max (val1, val2);
                    dp[i][j] = val;
                }
            }
        }
        return dp[0][n-1] >= (sum + 1) / 2; //IMP Condition to check 
    }
