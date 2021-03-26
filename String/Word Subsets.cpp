    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        int req[26] = {0};
        for (string& b : B) { //If not derefferenced by '&' (address) then it is alright
		    int newReq[26] = {0};
            for (char &c : b) newReq[c - 'a']++; //If not derefferenced by '&' (address) then it is alright
            for (int i = 0; i < 26; ++i) req[i] = max(req[i], newReq[i]);
        }
        for (string& a : A) { //If not derefferenced by '&' (address) then it is alright
            int demand[26] = {0};
            bool flag = true;
            for (char &c : a) demand[c - 'a']++; //If not derefferenced by '&' (address) then it is alright
            for (int i = 0; i < 26; ++i) {
                if (demand[i] < req[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(a);
        }
        return res;
    }
