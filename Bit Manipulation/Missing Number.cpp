    3 Methods
    int missingNumber(vector<int>& nums) {
        // Method 1 - Sorting
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i) return i;
        }
        return nums.size();
        
        // Method 2 - Hash Map
        unordered_set<int> set;
        for(int i : nums){
            set.insert(i);
        }
        for(int i=0;i<nums.size();i++){
            if(set.find(i) == set.end()) return i;
        }
        return nums.size();
        
        // Method 3 - Bit Map
        int result = nums.size();
        int i=0;
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        return result;
    }
