//     2 approaches - 

    map<int,map<int,set<int>>> mymap; 
    void solve(TreeNode *curr,int col,int row){
        if(!curr) return;
        mymap[col][row].insert(curr->val);
        solve(curr->left,col-1,row+1);
        solve(curr->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> ans;
        for(auto m1 : mymap){
            ans.push_back(vector<int>());
            for(auto m2: m1.second){
                for(auto m3: m2.second)
                    ans.back().push_back(m3);
            }
        }
        return ans;
    }

//     Using BFS
     vector<vector<int>> verticalTraversal(TreeNode* root) {
        TreeNode* curr;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        vector<vector<int>> ans;
        map<int,vector<int>> mymap;
        while(!q.empty()){
            int size = q.size();
            map<int,set<int>> mapset;
            while(size--) {
                curr = q.front().first;
                int col = q.front().second;
                q.pop();
                mapset[col].insert(curr->val);
                if(curr->left) q.push({curr->left,col-1});
                if(curr->right) q.push({curr->right,col+1});
            }
            for(auto it: mapset)
                for(auto it2: it.second)
                    mymap[it.first].push_back(it2);
        }
        for(auto it: mymap)
            ans.push_back(it.second);
        return ans;
    }
