    // 3 Approaches - 
    void sortColors(vector<int>& nums) {
        // Appraoch 1 - Using Dutch National Flag Algorithm - Using 3 pointers 
        int lo = 0;
        int hi = nums.size()-1;
        int mid = 0;
        while(mid<=hi){
            switch(nums[mid]){
                case 0:
                    swap(nums[lo++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[hi--]);
                    break;
            }
        }
        
        // Approach 2
        int second = nums.size()-1;
        int zero = 0;
        for(int i=0;i<second + 1;i++){
            while(nums[i] == 2 && i < second) swap(nums[i],nums[second--]);
            while(nums[i] == 0 && i > zero) swap(nums[i],nums[zero++]);
        }
        
        // Appraoch 3
        int lo = 0;
        int hi = nums.size()-1;
        int mid = 0;
        int tmp = 0;
        while(mid<=hi){
            if(nums[mid] == 0){
                tmp = nums[lo];
                nums[lo] = nums[mid];
                nums[mid] = tmp;
                lo++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else if(nums[mid] == 2){
                tmp = nums[hi];
                nums[hi] = nums[mid];
                nums[mid] = tmp;
                hi--;
            }
        }
    }
