    //Question Link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/    

    int findUnsortedSubarray(vector<int>& nums) {
        //Using Sorting
        /*vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int n = nums.size();
        int i=0,j=n-1;
        while(i<n && sorted[i] == nums[i]) i++;
        while(j>i && sorted[j] == nums[j]) j--;
        return j-i+1;*/
        
        //Somewhat Difficult - 
        /*int n = nums.size();
        if (n <= 1) return 0;
        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1]) ++left;
        if (left == n - 1) return 0; // return 0 if already sorted.
        // Or we know the array is unsorted
        // So, it's no need to judge right > 0
        while (/*right > 0 && *\ nums[right] >= nums[right - 1]) --right;

        int rmin = INT_MAX, lmax = INT_MIN;
        for (int i = left; i <= right; ++i) {
            if (nums[i] > lmax) lmax = nums[i];
            if (nums[i] < rmin) rmin = nums[i];
        }
        while (left >= 0 && nums[left] > rmin) --left;
        while (right < n && nums[right] < lmax) ++right;
        return right - left - 1;*/
        
        //Easiest Method - 
        int n = nums.size();
        vector<int> maxlhs(n);   // max number from left to cur
        vector<int> minrhs(n);   // min number from right to cur
        for (int i = n - 1, minr = INT_MAX; i >= 0; i--) minrhs[i] = minr = min(minr, nums[i]);
        for (int i = 0,     maxl = INT_MIN; i < n;  i++) maxlhs[i] = maxl = max(maxl, nums[i]);

        int i = 0, j = n - 1;
        while (i < n && nums[i] <= minrhs[i]) i++;
        while (j > i && nums[j] >= maxlhs[j]) j--;

        return j + 1 - i;
    }
