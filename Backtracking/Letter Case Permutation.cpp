    void solve(string ip,string op,vector<string> &vec){
        if(ip.size() == 0){
            if(find(vec.begin(),vec.end(),op)==vec.end()){
                vec.push_back(op);
            }
            return;
        }
        string op1 = op;
        string op2 = op;
        op1.push_back(ip[0]);
        if(ip[0] >= '0' && ip[0] <= '9'){
            //op1.push_back(ip[0]);
            op2.push_back(ip[0]);
        }
        if(ip[0]>='a' && ip[0]<='z'){
            op2.push_back(toupper(ip[0]));
        }
        if(ip[0]>='A' && ip[0]<='Z'){
            op2.push_back(tolower(ip[0]));
        }
        ip.erase(ip.begin() + 0);
        solve(ip,op1,vec);
        solve(ip,op2,vec);
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> vec;
        solve(S,"",vec);
        return vec;
    }
