    //Provided 2 solutions - DP based and Array based solution - Concept is same. 
    
    /*
    Explanation - DP based solution. 
    -> If nums[i] > nums[i-1], that means it wiggles up. the element before it must be a down position. so up[i] = down[i-1] + 1; down[i] keeps the same with before.
    -> If nums[i] < nums[i-1], that means it wiggles down. the element before it must be a up position. so down[i] = up[i-1] + 1; up[i] keeps the same with before.
    -> If nums[i] == nums[i-1], that means it will not change anything becasue it didn't wiggle at all. so both down[i] and up[i] keep the same.
    */
    
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> up(size, 0);
        vector<int> down(size, 0);
        up[0] = down[0] = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if (nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[size-1], down[size-1]);
    }
    
    //Array based solution - 
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) down = up + 1;
            else if (nums[i] > nums[i - 1]) up = down + 1;
        }
        return max(up, down);
    }
