    
    Formula - IMP
    dp[n]= dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
         = dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])
         = dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0]))
         = dp[n-1]+dp[n-3]+dp[n-1]
         = 2*dp[n-1]+dp[n-3]
    
    int numTilings(int N) {
        int mod = 1e9 + 7;
        vector<long long> v(1001, 0); //Constraint of N = [0,1000]
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        if(N <= 3) return v[N];
        for(int i = 4; i <= N; i++){
            v[i] = 2 * v[i-1] + v[i-3]; // Formula Derived. 
            v[i] %= mod;
        }
        return v[N];
    }
