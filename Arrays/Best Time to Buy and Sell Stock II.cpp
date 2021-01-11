    4 Different Approaches --->
    
    * Approach 1 - 
    int maxProfit(vector<int>& prices) {
        int bd = 0, sd = 0, profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i-1]) sd++;
            else {
                profit += prices[sd] - prices[bd];
                sd = bd = i;
            }
        }
        profit += prices[sd] - prices[bd];
        return profit;
    }
    
    * Approach 2 - 
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
    
    * Approach 3 - 
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),res=0;
        for(int i=0;i<n-1;i++){
            if(prices[i]<prices[i+1])
            res+=prices[i+1]-prices[i];
        }
        return res;
    }
    
    * Approach 4 - 
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (size_t p = 1; p < prices.size(); ++p) 
            ret += max(prices[p] - prices[p - 1], 0);    
        return ret;
    }
