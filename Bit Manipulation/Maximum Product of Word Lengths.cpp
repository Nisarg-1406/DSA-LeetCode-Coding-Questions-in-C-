    int maxProduct(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int s=words.size();
        // cout << s << "\n"; 
        if(s==0) return 0;
        vector<int> bit(s,0);
        sort(words.begin(), words.end(), compare);  //sort the vector from longest to shortest
        for(int i=0; i<s; i++){ //bit manipulation
            for(int j=0; j<words[i].size(); j++) bit[i] |=(1<<(words[i][j]-'a')); 
            // cout << bit[i] << "\n";
        }
        int maxlength=0;
        for(int i=0; i<s-1; i++){
            int si=words[i].size();
            if(si*si<=maxlength) break; //early pruning
            for(int j=i+1; j<s; j++){
                int sj=words[j].size();
                if(si*sj<=maxlength) break;  //early pruning
                if((bit[i]&bit[j])==0) maxlength=si*sj;
            }
        }
        return maxlength;
    }
    static bool compare(string a, string b){
        return a.size()>b.size();
    }
