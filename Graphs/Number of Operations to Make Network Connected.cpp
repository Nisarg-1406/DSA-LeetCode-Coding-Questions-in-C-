    //Forming DFS
    void DFS(unordered_map<int ,vector<int>>& adj ,int curr ,vector<bool>& visited) {
        visited[curr] = true;
        for(auto i: adj[curr])
            if(visited[i] == false)
                DFS(adj,i,visited);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //Make the adjacency list - 
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;
        int edges = 0;
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges += 1;
        }
        //Find the no of components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                components = components + 1;
                DFS(adj ,i ,visited);
            }
        }
        //Count no of edges
        if(edges < n - 1) //If no of edges are less than that in MST
            return -1;
        int redundant = edges-((n - 1) - (components - 1));   //Count redundant edges - IMP Formula
        if(redundant >= (components - 1)) //Check if we can join components using redundant edges
            return components - 1;
        return -1;
    }
