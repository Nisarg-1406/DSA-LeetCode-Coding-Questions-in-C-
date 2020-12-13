    Explanation - 
    The reason we have to the update from bottom right to top left is stated : we need to calculate values for this iteration given values from the last iteration.
    If we do it the other way around, memo[i][j] is calculated with values from this iteration, which results in overcounting.
    memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1); This line says:

    1) There are two possible ways to form the max number of strings with i 0's and j 1's regarding s: we either form s or skip it.
    2) If we skip s, memo[i][j] shouldn't change.
    3) Otherwise, we form s with numZeroes 0's and numOnes 1's, which leaves us i - numZeroes 0's and j - numOnes 1's to work with for all previous strings. How many
      strings can we form with i - numZeroes 0's and j - numOnes 1's? It's memo[i - numZeroes][j - numOnes] which was calculated in previous rounds, so just add 1 to that.
    4) We choose to form s or skip it based on which of 2 and 3 gives us a larger memo[i][j].
    
    CODE - 
    int findMaxForm(vector<string>& strs, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
          int numZeroes, numOnes;

          for (auto &s : strs) {
            numZeroes = numOnes = 0;
            // count number of zeroes and ones in current string
            for (auto c : s) {
              if (c == '0') numZeroes++;
              else if (c == '1') numOnes++;
            }

            // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
            // from the first few strings up to the current string s
            // Catch: have to go from bottom right to top left
            // Why? If a cell in the memo is updated(because s is selected),
            // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
            // If we go from top left to bottom right, we would be using results from this iteration => overcounting
            for (int i = m; i >= numZeroes; i--) {
                for (int j = n; j >= numOnes; j--) {
                      memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
                }
            }
          }
         return memo[m][n];
    }
