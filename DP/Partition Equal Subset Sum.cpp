    * First calculating the subset sum using tabulation method. 
    * We can get the equal subset sum when sum of the elements is even. If sum is odd, then to return false as we cannot divide the sum into 2 halves.
    
    bool subsetSum(vector<int> &nums,int sum){
        int len = nums.size();
        int t[len + 1][sum + 1]; 
        for (int j = 0; j < sum+1; j++) {
            t[0][j] = false;
        }
        for (int i = 0; i < len+1; i++) {
            t[i][0] = true;
        }
        for(int i = 1;i<len+1;i++){
            for(int j = 1;j<sum+1;j++){
                if(nums[i-1] <= j) t[i][j] = (t[i-1][j] || t[i-1][j-nums[i-1]]);
                else t[i][j] = t[i-1][j];
            }
        }
        return t[len][sum];
    }
    
     bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        if(sum % 2 != 0) return false;
        else return subsetSum(nums,sum/2);
    }
