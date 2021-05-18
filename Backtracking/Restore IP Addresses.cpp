    //Using 4 for loops - But faster - 0ms
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> res;
        string ans;
        
        for(int a = 1; a<=3; a++)
            for(int b=1; b<=3; b++)
                for(int c=1; c<=3; c++)
                    for(int d=1; d<=3; d++)
                        if(a + b + c + d == n){
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a+b, c));
                            int D = stoi(s.substr(a+b+c, d));
                            if(A <= 255 && B <= 255 && C <= 255 && D <= 255){
                                if ( (ans = to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length() + 3) res.push_back(ans);
                            }
                        }
        return res;
    }
    
    //Using 3 for loops - But slower - 4ms
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ips;
        for (int i = 1; i <= 3 && i < n; i++) {
            for (int j = 1; j <= 3 && i + j < n; j++) {
                for (int k = 1; k <= 3 && i + j + k < n; k++) {
                    string a = s.substr(0, i);
                    string b = s.substr(i, j);
                    string c = s.substr(i + j, k);
                    string d = s.substr(i + j + k);
                    if (valid(d) && valid(c) && valid(b) && valid(a)) {
                        ips.push_back(a + '.' + b + '.' + c + '.' + d);
                    }
                }
            }
        }
        return ips;
    }
private:
    bool valid(string s) {
        return !s.empty() && s.size() <= 3 && stoi(s) <= 255 && (s[0] != '0' || s.size() == 1);
    }
