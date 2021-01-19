    Using 2 pointers - T.C - > O(NlogN)
    
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                ans = ans + 1; 
                i++;
                j--;
            }
            else if (nums[i] + nums[j] > k) j--;
            else i++;
        }
        return ans;
    }
