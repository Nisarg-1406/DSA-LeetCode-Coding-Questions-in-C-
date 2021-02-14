    // 2 Approaches 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Method - 1
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> moves = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        queue<vector<int>> que;
        if(grid[0][0] || grid[n][m]) return -1;
        que.push({0, 0, 1});
        while(!que.empty()){
            vector<int> top = que.front();
            que.pop();
            if(top[0] == n && top[1] == m) return top[2];
            for(vector<int> move : moves){
                int x = top[0] + move[0];
                int y = top[1] + move[1];
                if( 0 <= x && x <= n && 0 <= y && y <= m && grid[x][y] == 0){
                    grid[x][y] = 1;  // mark visted
                    que.push({x, y, top[2] + 1});
                }
            }
        }
        return -1;
        
        
        // Method - 2 
        vector <vector <int>> moves = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}}; // The order doesn't matter.
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        queue <vector <int>> que;
        if(grid[0][0] || grid[n][m])
            return -1;
        que.push({0, 0});
        grid[0][0] = 1;
        while(!que.empty() && !grid[n][m]){ 
		/* If my last node is visited, I exit immediately.
		* 1. The Fastest path is always the shortest path in BFS 
		*    Hence, The first path to reach the end is the shortest path.
		*    Early termination is needed here. If there is a lot of
		*    unvisited nodes in-between that don't lead to the end node, it gives TLE.
		* 2. Doing a level order(two loops) is also possible. But we don't need to remember the level.
		*    So one loop will do
		*/
            vector <int> top = que.front();      // Do not use 'auto' here. I gives TLE
            que.pop();
            for(vector <int> move: moves){       // Do not use 'auto' here. I gives TLE
                int x = top[0] + move[0], y = top[1] + move[1];
                if(0 <= x && x <= n && 0 <= y && y <= m && grid[x][y] == 0){
                    grid[x][y] = grid[top[0]][top[1]] + 1;   // mark visted and propagate the distance
                    //cout<<grid[x][y]<<"\n";
                    que.push({x, y});
                }
            }
        }
        return grid[n][m] == 0 ? -1 : grid[n][m];   // If the queue terminated without setting (n, m) to a value other than zero, it means it could never reach the end.
    }
