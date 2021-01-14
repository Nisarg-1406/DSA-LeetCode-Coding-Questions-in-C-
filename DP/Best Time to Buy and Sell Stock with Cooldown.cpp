    3 APPROACHES WITH EXPLANATION
    
    APPROACH - 1 - 
    obsp = old bought stock profit
    ossp = old sell stock profit
    ocsp = old cooldown stock profit
    nbsp = new bought stock profit
    nssp = new sell stock profit
    ncsp = new cooldown stock profit
    
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int obsp = -prices[0];
        int ossp = 0, ocsp = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            int nbsp = 0, nssp = 0, ncsp = 0;
            
            //Buying
            if (ocsp - prices[i] > obsp) nbsp = ocsp - prices[i];
            else nbsp = obsp;
            
            //Selling
            if (obsp + prices[i] > ossp) nssp = obsp + prices[i];
            else nssp = ossp;
            
            //Cooldown period
            if (ossp > ocsp) ncsp = ossp;
            else ncsp = ocsp;
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        return ossp;
    }
    
    APPROACH - 2 - 
    Using state machine algorithm - 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0; //would not be having any profit if we buy, therefore 0 
        vector<int> noStock(n,0),inHand(n,0),Sold(n,0);
        
        //Filling up the first elements in all the array
        noStock[0] = 0;
        inHand[0] = -prices[0];    //bcoz we have bought a stock and never sold it
        Sold[0] = 0;
        
        //For rest of the array elements - 
        for(int i=1;i<n;++i){
            noStock[i] = max(noStock[i-1],Sold[i-1]);
            inHand[i] = max(inHand[i-1],noStock[i-1]-prices[i]);
            Sold[i] = inHand[i-1]+prices[i];
        }
        int result = max(noStock[n-1],Sold[n-1]);
        return result;
    }
    
    APPROACH - 3 - 
    Using memoization - 
    int mem[5001];
    vector<int> mem;
    int findMax(vector<int> &prices, int curr, int n){
        if(curr >= n) return 0;
        if(mem[curr]!=-1) return mem[curr];
        int maxVal = 0;
        for(int i=curr+1;i<n;++i){ //Now find all the positions where we can sell the stock
            if(prices[curr] < prices[i]) //We can try to sell on ith day
                //We have 2 choices
                //1.We can sell the stock at ith day and findMax from (i+2)th day
                //2.We don't sell the stock on ith day
                maxVal = max(maxVal, prices[i]-prices[curr]+findMax(prices,i+2,n));
        }
        maxVal = max(maxVal, findMax(prices, curr+1, n)); //we skipped that day for buying 
        mem[curr] = maxVal;
        return maxVal;
    }
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=prices.size();
        //memset(mem, -1, sizeof(mem));
        mem.resize(n+1,-1);
        return findMax(prices,0,n);
    }
