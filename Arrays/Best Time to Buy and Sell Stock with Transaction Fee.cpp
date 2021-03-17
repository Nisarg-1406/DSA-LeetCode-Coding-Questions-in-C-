    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int obsp = -prices[0];
        int ossp = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            int nbsp = 0;
            int nssp = 0;
            
            if (ossp - prices[i] > obsp) nbsp = ossp - prices[i];
            else nbsp = obsp;
            
            if (obsp + prices[i] - fee > ossp) nssp = obsp + prices[i] - fee;
            else nssp = ossp;
            
            obsp = nbsp;
            ossp = nssp;
        }
        return ossp;
    }    
