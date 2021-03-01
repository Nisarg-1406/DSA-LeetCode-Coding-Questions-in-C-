    // 3 Methods - 
    int distributeCandies(vector<int>& candies) {
        // Method 1
        unordered_set<int> set;
        for(auto num : candies){
            set.insert(num);
        }
        return min(set.size(), candies.size()/2);
        
        //Method 2 - Using C++ STL - 
        return min(unordered_set<int>(candies.begin(), candies.end()).size(), candies.size() / 2);
        
        // Method 3 - 
        unordered_map<int, int> m;
        for(int x: candies) m[x]++;
        if(candies.size() == m.size()) return candies.size()/2;
        if(candies.size() % m.size() == 0) return m.size();
        else return min(m.size(), candies.size()/2);
    }
