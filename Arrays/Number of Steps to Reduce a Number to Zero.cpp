    int numberOfSteps (int num) {
        int cnt = 0;
        while(num != 0) {
            if(num % 2 == 0) {num = num / 2; cnt++;}
            else if (num % 2 != 0) {num = num - 1; cnt++;}
        }
        return cnt;
        
        int cnt=0; 
        while(num){
            if(num & 1) num = num - 1;
            else num >>=1;
            cnt++;
        }
        return cnt;
    }
