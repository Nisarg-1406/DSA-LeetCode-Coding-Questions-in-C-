    * Approach 1 - 
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i = 0,j = 0,n = s.size(),ans = 0;
        while(j<n && i<n){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j++]);
                ans = max(ans,j-i);
            }
            else set.erase(s[i++]);
        }
        return ans;
    }
    
    * Approach 2 - 
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start){
                start = dict[s[i]];
                cout<<start<<"\n";
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
