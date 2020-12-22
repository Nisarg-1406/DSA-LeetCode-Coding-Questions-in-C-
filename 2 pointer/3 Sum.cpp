    //Optimized solution - T.C - O(N^2)
    
    vector<vector<int>> threeSum(vector<int>& num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (num.size() == 0) return {};
        vector<vector<int>> res;
        sort (num.begin(), num.end());
        for (int i = 0; i < (int)(num.size()) - 2; i++){
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                int lo = i + 1, hi = (int)(num.size()) - 1, sum = 0 - num[i]; // B + C = -A
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        while (lo < hi && num[lo] == num[lo+1]) lo++; //Skip the same numbers to avoid the duplicates
                        while (lo < hi && num[hi] == num[hi-1]) hi--; //Skip the same numbers to avoid the duplicates
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
