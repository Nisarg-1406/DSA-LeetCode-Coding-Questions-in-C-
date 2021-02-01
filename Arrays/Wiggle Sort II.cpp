    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end()); // To find the median - Inbuilt function. 
        threeWayPartition(nums, nums[mid]);
        
        vector<int> res(n);
        int last = n - 1;
        int middle = (n % 2) ? mid : mid - 1;
        for (int i = 0; i < n; i += 2) {
            res[i] = nums[middle];
            middle--;
        }
        for (int i = 1; i < n; i += 2) {
            res[i] = nums[last];
            last--;
        }
        nums = res;
    }
    
    // Same as sorting the 0s, 1s, 2s in the array - Using Dutch National Flag Algorithm using 3 pointers. 
    void threeWayPartition (vector<int> &nums, int val) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        while (mid <= hi) {
            if (nums[mid] < val) swap(nums[lo++], nums[mid++]);
            else if (nums[mid] > val) swap(nums[mid], nums[hi--]);
            else mid++;
        }
    }
