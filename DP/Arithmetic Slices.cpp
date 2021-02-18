    // 2 Methods - Math and DP
    int numberOfArithmeticSlices(vector<int>& A) {
        //Using normal Math - 
        int curr = 0, sum = 0;
        for (int i=2; i<A.size(); i++)
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
                curr += 1;
                sum += curr;
            } 
            else curr = 0;
        return sum;
        
        //Using DP - 
        int n = A.size();
        if(n < 3) return 0;
        int dp[n];
        dp[0] = dp[1] = 0;
        int sum = 0;
        for(int i=2;i<A.size();i++){
            if((A[i]-A[i-1])==(A[i-1]-A[i-2])){
                dp[i]=dp[i-1]+1;
                sum+=dp[i];
            }
            else dp[i]=0;
        }
        return sum;
    }
