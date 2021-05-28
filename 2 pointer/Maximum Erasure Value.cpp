    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map <int, bool> mp;
        int start = 0;
        int cur_sum = 0;
        int max_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            while(mp[nums[i]] == true) {
                cur_sum = cur_sum - nums[start];
                mp[nums[start]] = false;
                start++;
            }
            mp[nums[i]] = true;
            cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum; 
    }
