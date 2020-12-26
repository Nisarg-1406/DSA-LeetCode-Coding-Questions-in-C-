    //Using 3 Approaches - 
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // 1. Brute force - Calculating cost for all 365 days
        unordered_set<int> travel (days.begin(), days.end());
        int dp[366] = {0};
        for (int i = 1; i < 366; i++) {
            if (travel.find(i) == travel.end()) dp[i] = dp[i-1]; // considering that if not travelled on particular day then to count the previous day cost. 
            else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]}); //Considering from last 7 days and 30 days and at last taking min from all 3. 
        }
        return dp[365];
        
        //2. Taking %30 because we are only considering the GAP of 30 days everytime. 
          unordered_set<int> travel(begin(days), end(days));
          int dp[30] = {};
          for (int i = days.front(); i <= days.back(); ++i) {
            if (travel.find(i) == travel.end()) dp[i % 30] = dp[(i - 1) % 30]; // considering that if not travelled on particular day then to count the previous day cost and doing %30
            else dp[i % 30] = min({ dp[(i - 1) % 30] + costs[0], dp[max(0, i - 7) % 30] + costs[1], dp[max(0, i - 30) % 30] + costs[2] }); //Considering from last 7 days and 30 days and at last taking min from all 3 and doing %30.  
          }
          return dp[days.back() % 30];
        
        //3. Using Queue and considering the only days when we would be travelling 
        queue<pair<int, int>> last7, last30;
        int cost = 0;
        for (auto d : days) {
            while (!last7.empty() && last7.front().first + 7 <= d) last7.pop(); //if day number is <= d then to pop from the queue
            while (!last30.empty() && last30.front().first + 30 <= d) last30.pop(); //if day number is <= d then to pop from the queue
            last7.push({ d, cost + costs[1] });
            last30.push({ d, cost + costs[2] });
            cost = min({ cost + costs[0], last7.front().second, last30.front().second }); //min from the front of the queue. 
        }
        return cost;
    }
