    bool isBipartite(vector<vector<int>>& adj,int node,vector<int>& color){
         queue<int> q;
         q.push(node);
         color[node] = 1;
         while(!q.empty()){
             int cur = q.front();
             q.pop();
             for(int ele : adj[cur]){
                 if(color[ele] == color[cur]) return false;
                 if(color[ele]==-1){
                    color[ele] = 1 - color[cur];
                    q.push(ele);
                }
             }
         }
         return true;
     }
    bool isBipartite(vector<vector<int>>& dislikes) {
        int N = dislikes.size();
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> color(N+1,-1);
        for(int i=1;i<N;i++){
            if(color[i]==-1){
                if(!isBipartite(dislikes,i,color)) return false;
            }
        }
        return true;
    }
