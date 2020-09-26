    //Question Link - https://leetcode.com/problems/jump-game-ii/

    int jump(vector<int>& nums) {
        //Apporach -1 
        /*int s = nums.size(),i=0,j=1;
        if(s<2)return 0;
        vector<int> v(s,0);
        while(j<s){
            if(j<=i+nums[i]){
                v[j]=v[i]+1;
                j++;
            }
            else i++;
        }
        return v[s-1];*/
        
        //Apporach -2 
        /*int c = 0;
            int pos = 0;
            int des = 0;
            for(int i = 0;i<nums.size()-1;i++){
                des = max(des,i + nums[i]);
                //cout<<"The des is : "<<des<<"\n";
                if(pos == i){
                    c++;
                    //cout<<"The c is : "<<c<<"\n";
                    pos = des;
                    //cout<<"The pos is : "<<pos <<" "<<des<<"\n";
                }
            }
        return c;*/
        
        //Apporach -3 
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
              step++; 
        int maxend = end + 1;
        for (int i = start; i <= end; i++) {
          if (i + nums[i] >= n - 1) return step;
          maxend = max(maxend, i + nums[i]);
        }
          start = end + 1;
          end = maxend;
        }
      return step;
    }
