    int removeDuplicates(vector<int>& nums) {
        * Using 2 pointers - T.C - O(n) & S.C - O(1)
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i = i + 1;
                nums[i] = nums[j];    
            }
        }
        return i + 1;
        
        * The another method is to directly use the stl in c++ ==> 
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        return nums.size();
    }
