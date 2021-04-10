    int states[1001][1001];
    int longestpath(vector<vector<int>> &matrix, int i, int j){
        int maxd = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        if(states[i][j] != -1) return states[i][j];
        if(j>0 && matrix[i][j-1] > matrix[i][j]) {
            int left = longestpath(matrix, i, j-1);
            maxd = max(maxd, left); 
        }
        if(j<n-1 && matrix[i][j+1] > matrix[i][j]) {
            int right = longestpath(matrix, i, j+1);
            maxd = max(maxd, right);
        }
        if(i>0 && matrix[i-1][j] > matrix[i][j]) {
            int up = longestpath(matrix, i-1, j);
            maxd = max(maxd, up);
        }
        if(i<m-1 && matrix[i+1][j] > matrix[i][j]) {
            int down = longestpath(matrix, i+1, j);
            maxd = max(maxd, down);
        }
        states[i][j] = maxd + 1;
        return states[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        memset(states,-1,sizeof(states));
        int m = matrix.size();
        if (m == 0) return 0;
        int res = 0;
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, longestpath(matrix, i, j));
            }
        }
        return res;
    }
