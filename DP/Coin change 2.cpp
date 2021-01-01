    *Using 2 approches - 
    
    //Making 2D table
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        int t[len + 1][amount + 1];
        for (int j = 0; j < amount+1; j++) {
            t[0][j] = 0;
        }
        for (int i = 0; i < len+1; i++) {
            t[i][0] = 1;
        }
        for(int i = 1;i < len + 1; i++){
            for(int j = 1;j < amount + 1; j++){
                if(coins[i - 1] <= j){
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j]; 
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[len][amount];
        
        
        //Making 1D Table 
        int n = coins.size();
        if(n == 0){
            if(amount == 0) return 1;
            else return 0;
        }
        int dp[amount + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 0;i < n; i++){
            for(int j = coins[i]; j <= amount; j++)
                dp[j] += dp[j - coins[i]];
        }
        return dp[amount];
    }
