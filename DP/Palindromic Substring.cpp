/*Solution using 4 Methods - IMP
1. Using Odd/Even Length Substring
2. Using Recursion
3. Using Memoization
4. Using Tabulation.*/

//Code -

//Solution using odd/even length substring - Method - 1-
/*int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            pallindrome(s,i,i,cnt); //checking of odd length substring
            pallindrome(s,i,i+1,cnt); //checking of even length substring
        }
        return cnt;
    }
    void pallindrome(string s, int left, int right, int &cnt){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            cnt = cnt + 1;
            left = left - 1;
            right = right + 1;
        }
    }*/
    
    //Recursive solution - Method-2-
    /*int countSubstrings(string& s) {
       return recursive(s);
    }
    int recursive(string &s){
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                cnt = cnt + helper(s,i,j);
            }
        }
        return cnt;
    }
    int helper(string& s, int i, int j) {
        if (i == j) return 1;
        return s[i] == s[j] ? helper(s, i+1, j-1) : 0;
    }*/
    
    //Memoization Solution - Method - 3-
    /*int countSubstrings(string& s) {
       return memoization(s);
    }
    int memoization(string& s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += solve(mem, s, i, j);
            }
        }
        return count;
    }
    
    int solve(vector<vector<int>>& mem, string& s, int i, int j) {
        if (i >= j) return 1;
        if (mem[i][j] != -1) return mem[i][j];
        return mem[i][j] = s[i] == s[j] ? solve(mem, s, i+1, j-1) : 0;
    }*/
    
    //Solution same as Longest Pallindromic Substring - DP- Method - 4
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            ans++;
        }	
        for(int i=2; i<=n; i++){
            for(int j=0; j<n-i+1; j++){
                int k = j+i-1;
                if(i==2 && s[j] == s[k]) {
                    dp[j][k] = 1;
                    ans++;
                }
                else if(s[j] == s[k] && dp[j+1][k-1]==1){ 
                    dp[j][k] = 1;
                    ans++;
                }
            }
        }        
        return ans;
    }
