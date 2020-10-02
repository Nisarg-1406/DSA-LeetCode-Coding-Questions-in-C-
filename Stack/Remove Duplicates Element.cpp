//316 - https://leetcode.com/problems/remove-duplicate-letters/
string removeDuplicateLetters(string s) {
        //Using vector - Method 1
        /*vector<int> cand(256,0);
        vector<bool> visited(256, false);
        for(char c : s){
            cand[c]++;
        }
        string res = "";
        for(char c : s){
            cand[c]--;
            if (visited[c]) continue;
            while (c < res.back() && cand[res.back()]){
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res;*/
        
        //Using stack - Method - 2
        vector<char>v(256,0);
        for(auto i:s) v[i]++;
        stack<char>st;
        set<int>cur;
        for(auto i:s){
            v[i]--;
            if(cur.find(i)!=cur.end())continue;
            while(!st.empty() && st.top()>i && v[st.top()]){
                cur.erase(st.top());
                st.pop();
            }
            cur.insert(i);
            st.push(i);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
