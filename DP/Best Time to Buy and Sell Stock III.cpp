    //Approach 1 - Divide and Conquer - Traversing left to right and right to left both
    
    // mpist => max profit if sold today;
    // mpibt => max profit if bought today;
    // leastsf => least so far;
    // maxsf => max so far;
    // dpl => max profit if sold upto today from left to right;
    // dpr => max profit if bought upto today from right to left;
    // op => output
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //left to right transaction
        int mpist = 0, leastsf = prices[0];
        int dpl[n];
        memset(dpl, 0, sizeof(dpl));
        for (int i = 1; i < n; i++) {
            if (prices[i] < leastsf) leastsf = prices[i];
            mpist = prices[i] - leastsf;
            
            if (mpist > dpl[i-1]) dpl[i] = mpist;
            else dpl[i] = dpl[i-1];
        }
        
        //right to left transaction
        int mpibt = 0, maxsf = prices[n-1];
        int dpr[n];
        memset(dpr, 0, sizeof(dpr));
        for (int i = n - 2 ; i >= 0 ; i--) {
            if (prices[i] > maxsf) maxsf = prices[i];
            mpibt = maxsf - prices[i];
            
            if (mpibt > dpr[i+1]) dpr[i] = mpibt;
            else dpr[i] = dpr[i+1];
        }
        
        //Final output - taking max (dpl[i] + dpr[i])
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (dpl[i] + dpr[i] > op) op = dpl[i] + dpr[i];
        }
        return op;
    }
    
    //Approach - 2 - Same as Above one - Divide and Conquer
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> left(n),right(n);
        int leftmin = prices[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],prices[i] - leftmin);
            leftmin = min(leftmin,prices[i]);
        }
        int rightmax = prices[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],rightmax - prices[i]);
            rightmax = max(rightmax,prices[i]);
        }
        int profit = right[0];
        for(int i= 1;i<n;i++){
            profit = max(profit,left[i-1] + right[i]);
        }
        return profit;
    }
    
    //Approach - 3
    int maxProfit(vector<int>& prices) {
        int oneBuy = INT_MIN;
        int oneBuyOneSell = 0;
        int twoBuy = INT_MIN;
        int twoBuyTwoSell = 0;
        for(int i = 0; i < prices.size(); i++){
            oneBuy = max(oneBuy, -prices[i]);//we set prices to negative, so the calculation of profit will be convenient
            oneBuyOneSell = max(oneBuyOneSell, prices[i] + oneBuy);
            twoBuy = max(twoBuy, oneBuyOneSell - prices[i]);//we can buy the second only after first is sold
            twoBuyTwoSell = max(twoBuyTwoSell, twoBuy + prices[i]);
        }
        return max(oneBuyOneSell, twoBuyTwoSell);
    }
    
    //Approach 4 - Using Memoization - 
    
    vector<vector<vector<int>>> mem;
    int recursion(vector<int>& prices,int pos,int t,bool bought){
        if(pos>=prices.size() || t==0) return 0;
        if(mem[bought][t][pos]!=-1) return mem[bought][t][pos];
        int result = recursion(prices,pos+1,t,bought); //skip
        if(bought) result = max(result,recursion(prices,pos+1,t-1,false) + prices[pos]); //sell
        else result = max(result,recursion(prices,pos+1,t,true) - prices[pos]); //buy
        mem[bought][t][pos] = result;
        return result;
    }
    int maxProfit(vector<int>& prices) {
        mem.resize(2,vector<vector<int>>(3,vector<int>(prices.size(),-1)));
        int res = recursion(prices,0,2,false);
        return res;
    }
