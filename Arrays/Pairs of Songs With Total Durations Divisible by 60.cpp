    int numPairsDivisibleBy60(vector<int>& time) {
        //The below solution is the brute force solution, and it passes 31/34 test cases.
        /*int n = time.size();
        int cnt = 0;
        for(int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (((time[i] + time[j]) % 60) == 0) cnt = cnt + 1;
            }
        }
        return cnt;*/
        
        //optimised solution using the hashmap 
        vector<int> c(60);
        int res = 0;
        for (int t : time) {
            res += c[(600 - t) % 60];
            //res += c[(60 - t % 60)% 60];
            //cout << res << " "<<"\n"; 
            c[t % 60] += 1;
        }
        return res;
    }
