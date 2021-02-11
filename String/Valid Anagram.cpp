     // 3 Approaches
     bool isAnagram(string s, string t) {
        // 1st Method
        if(s.length()>t.length() || s.length()<t.length()) return false;
        int i;char res=0;
        for( i=0;i<t.length();i++){
            t[i]^=s[i];
            res^=t[i];
        }
        if(res==0) return true;
        else return false;
        
        // 2nd Method
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(s.length()>t.length() || s.length()<t.length()) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto c1:s) mp1[c1]++;
        for(auto c2:t) mp2[c2]++;
        for(auto c1:t){
            if(mp1.find(c1)==mp1.end()) return false;
            if(mp2[c1]!=mp1[c1]) return false;
        }
        return true;
        
        // 3rd Method
        if(s.size() != t.size()){
            return false;
        }
        int map[26] = {0};
        for(int i = 0; i < s.size(); i++){
            map[s[i]-'a']++;
            map[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(map[i] != 0){
                return false;
                break;
            }
        }
        return true;
    }
