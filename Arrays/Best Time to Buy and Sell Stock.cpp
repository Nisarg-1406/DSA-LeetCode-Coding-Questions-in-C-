    * 2 Approaches - 
    
    int maxProfit(vector<int>& prices) {
        //Selling at each anf every point and finding the maximum
        int maxPro = 0;
        int mini = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxPro = max(maxPro, (prices[i] - mini));
        }
        return maxPro;
        
        //Using kadane's algorithm - 
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
