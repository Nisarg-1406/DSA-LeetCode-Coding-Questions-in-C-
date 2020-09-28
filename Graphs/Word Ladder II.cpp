    vector<vector<string>> ans;
    void DFS(string &beginWord,string& endWord,unordered_map<string, unordered_set<string>>& adj, vector<string> &path){
        path.push_back(beginWord);
        if(beginWord == endWord){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x : adj[beginWord])
            DFS(x, endWord, adj, path);
        path.pop_back();
    }
        
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(),wordList.end()); //Insert WordList in SET
        queue<string> Q;
        Q.push(beginWord);
        unordered_map<string, int> visited; //Key->String (Node)...Value->Level (Depth of traversal)
        visited[beginWord] = 0; //Start node will always be at level 0
        while(!Q.empty()){
            string curr = Q.front();
            Q.pop();
            string temp = curr;
            for(int i = 0; i < curr.size(); ++i) {   //For all characters
                for(char x = 'a'; x <= 'z'; ++x) {   //Try all possible 26 letters
                    if(temp[i] == x) continue;   //Skip if letter is same as in original word
                    temp[i] = x;    
                    if(dict.count(temp) > 0) {   //Check if new word is present in wordList
                        if(visited.count(temp) == 0) {   //check if the new word was already visited
                            visited[temp] = visited[curr] + 1;
                            Q.push(temp);
                            adj[curr].insert(temp);
                        } 
                        else if(visited[temp] == visited[curr] + 1) adj[curr].insert(temp); //If already visited and new word is the child (We should always move down)
                    }
                }
                temp[i] = curr[i];  //Revert back temp to curr
            }
        }
        vector<string> path;
        DFS(beginWord, endWord, adj, path); //Find all possible paths with min-depth
        return ans; 
    }
