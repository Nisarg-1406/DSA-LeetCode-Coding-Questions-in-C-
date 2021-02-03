    vector<string> letterCombinations(string digits) {
        //Iterative solution - 
        vector<string> res;
        if(digits.empty()) return res;
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for(int i=0;i<digits.size();i++){
            int num = digits[i] - '0';
            const string candidate = v[num];
            vector<string> tmp;
            for(int j = 0 ; j < candidate.size() ; ++j) {
                for(int k = 0 ; k < res.size() ; ++k) {
                    tmp.push_back(res[k] + candidate[j]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
