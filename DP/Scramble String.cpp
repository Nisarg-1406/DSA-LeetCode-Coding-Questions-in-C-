    * 3 Approaches -------> Using Recursion, Using Memoization, Using Memoization + Pruning.
    *1. Using Recursion - It results in TLE 
    
    bool solve (string s1, string s2) {
        if(s1.size()==1) return s1==s2;
        if(s1==s2) return true;
        int n=s1.size();
        bool res = false;
        bool flag = false;
        for(int i = 1 ;i < n ;i++){
            bool cond1,cond2;
            cond1 = cond2 = false;
            if(solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i))) cond1 = true; //when flipped 
            if(solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i))) cond2 = true; //same as original 
            if(cond1 || cond2){
                flag = true;
                break;
            }
        }
        return flag;
    }
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return solve (s1,s2);
    }
    
    *2. Using memoization - O(N^3) - Took 152 ms to execute.
    unordered_map<string,bool> mp;
    bool solve(string s1,string s2){
        if(s1.compare(s2) == 0) return true;
        if(s1.size() < 1) return false;
        string key = s1 + s2;  //For unique key identification, we do s1 + s2
        if(mp.find(key)!=mp.end()) return mp[key]; // Storing in the map
        int len = s1.size();
        bool flag = false;
        for(int i = 1;i<=len-1;i++){
            bool cond1,cond2;
            cond1 = cond2 = false;
            if(solve(s1.substr(0,i),s2.substr(len-i,i)) && solve(s1.substr(i,len-i),s2.substr(0,len-i))) cond1 = true;
            if(solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,len-i),s2.substr(i,len-i))) cond2 = true;
            if(cond1 || cond2){
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
        
    bool isScramble(string s1, string s2) {
        if(s1.length()==0 && s2.length()==0) return true;
        int n =s1.length();
        int m =s2.length();
        if(n>m || m>n) return false;
        if(n==0 || m==0) return true;
        return solve(s1,s2);
    }
    
    *3. Using memoization + Pruning - Very Efficent code - Took 12 ms to execute - Worst case Time complexity -> O(N^3)
    unordered_map<string,bool> mp;
    bool solve(string s1,string s2){
        if(s1.compare(s2) == 0) return true;
        if(s1.size() < 1) return false;
        string key = s1 + s2; //For unique key identification, we do s1 + s2
        //Pruning: if the frequency count of any string does not match with the other string, then to return false as both of the string cannot be Scramble
        int n=s1.size();
        vector<int> f1(26),f2(26);
        for(int i=0;i<n;++i){
            f1[s1[i]-'a']+=1;
            f2[s2[i]-'a']+=1;
        }
        if(f1!=f2) return mp[key]=false;
        int len = s1.size();
        bool flag = false;
        for(int i = 1;i<=len-1;i++){
            bool cond1,cond2;
            cond1 = cond2 = false;
            if(solve(s1.substr(0,i),s2.substr(len-i,i)) && solve(s1.substr(i,len-i),s2.substr(0,len-i))) cond1 = true;
            if(solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,len-i),s2.substr(i,len-i))) cond2 = true;
            if(cond1 || cond2){
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
        
    bool isScramble(string s1, string s2) {
        if(s1.length()==0 && s2.length()==0) return true;
        int n =s1.length();
        int m =s2.length();
        if(n>m || m>n) return false;
        if(n==0 || m==0) return true;
        return solve(s1,s2);
    }
