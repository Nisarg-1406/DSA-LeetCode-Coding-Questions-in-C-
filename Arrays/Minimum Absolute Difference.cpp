    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        //Using extra space
        sort (arr.begin(), arr.end());
        vector<vector<int>> res;
        int min_diff = 0;
        for(int i = 1; i < arr.size(); i++) {
            min_diff = min (min_diff, arr[i] - arr[i-1]);
        }
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] == min_diff) {
                res.push_back ({arr[i-1],arr[i]});
            }
        }
        return res;
        
        //In a single pass - T.C - O(nlogn)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  
        sort (arr.begin(), arr.end());
        pair<int, vector<vector<int>>> result (INT_MAX,{});
        for (int i = 0; i < arr.size() - 1; i++) {
            if(arr[i + 1] - arr[i] > result.first) continue;
            if(arr[i + 1] - arr[i] == result.first) result.second.push_back({arr[i], arr[i + 1]});
            else result = {arr[i + 1] - arr[i], {{arr[i], arr[i + 1]}}};
        }
        return result.second;
    }
