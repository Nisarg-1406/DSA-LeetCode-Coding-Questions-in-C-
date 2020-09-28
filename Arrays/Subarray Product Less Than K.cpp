//Question Link - https://leetcode.com/problems/subarray-product-less-than-k/

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(k == 0) return 0;
        int start = 0;
        int end = 0;
        int prod = 1;
        int count = 0;
        while(end < nums.size()){
            prod = prod * nums[end];
            while(start < end && prod >= k){
                prod = prod / nums[start];
                start = start + 1;
            }
            if(prod < k) count = count + (end - start + 1);
            end = end + 1;
        }
        return count;
    }
