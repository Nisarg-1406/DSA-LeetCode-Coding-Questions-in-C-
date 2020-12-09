  //Using map - 
  
  /*int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1;
        unordered_map<int,int> mp;
        for (int i = 0; i < arr.size(); i++){
            mp[arr[i]] = mp[arr[i] - difference] + 1;
            res = max (res, mp[arr[i]]);
        }
        return res;
    }*/
    
    int longestSubsequence(vector<int>& arr, int diff) {
        int res = 1;
        unordered_map<int,int> maxmap;
        for(int i = 0 ; i < arr.size() ; i++)
            maxmap[arr[i]] = maxmap[arr[i]-diff] + 1;
        for(auto it : maxmap)
            res = max(res,it.second);
        return res;
    }
