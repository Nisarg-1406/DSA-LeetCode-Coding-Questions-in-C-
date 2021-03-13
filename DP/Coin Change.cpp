
    // 2 Methods - 
    // Method 1 - 
    int coinChange(vector<int>& coins, int amount) {
		if(amount==0) return 0;
		int dp[coins.size()+1][amount+1];
        for (int j = 0; j < amount+1; j++) {
           dp[0][j] = INT_MAX - 1;
        }
        for (int i = 1; i < coins.size()+1; i++) {
            dp[i][0] = 0;
        }

		// with this part only 108/182 test case gets passed -
		// int j;
		// for(int i=1;j<=amount;j++){
		// if(j%coins[0]==0) dp[i][j] = coins[0];
		// else dp[i][j] = INT_MAX - 1;
		// }	 
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                //else if(coins[i-1]==j)
                  //  dp[i][j]=1;
                else
                    dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            }
        }
		
        if(dp[coins.size()][amount]==INT_MAX-1)
            return -1;
			
        return dp[coins.size()][amount];
    }
    
    // Method - 2 - 
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
