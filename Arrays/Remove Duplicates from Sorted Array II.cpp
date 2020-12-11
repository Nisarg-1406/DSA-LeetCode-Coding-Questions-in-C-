    //This is even true for k atmost duplicates taken into consideration 
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (auto n : nums) {
            if (count < 2 || n > nums[count - 2]) {
                nums[count++] = n;
                //count = count + 1;
            }
        }
        return count;
    }
